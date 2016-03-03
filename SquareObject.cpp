
#include "SquareObject.h"

SquareObject::SquareObject()
{

}

void SquareObject::transform()
{
	//Create transformation matrices
	Matrix scale(SCALE, xScale, yScale, zScale);

	Matrix rotX(ROT_X, xAngle * MATH_PI / 180.0f);

	Matrix rotY(ROT_Y, yAngle * MATH_PI / 180.0f);

	Matrix rotZ(ROT_Z, zAngle * MATH_PI / 180.0f);

	Matrix axisRot(IDENTITY);
	axisRot.set(ROT_AXIS_ANGLE, this -> rotAxis, this -> axisRotAngle * MATH_PI / 180.0f);

	Matrix orbitRot(IDENTITY);
	orbitRot.set(ROT_AXIS_ANGLE, this -> orbitAxis, this -> orbitAngle * MATH_PI / 180.0f);

	Matrix trans( TRANS, this -> startPos[x] + this -> xTrans, this -> startPos[y] + this -> yTrans, this -> startPos[z] + this -> zTrans );

	Matrix orbitTrans(TRANS, this -> xOrbitTrans, this -> yOrbitTrans, this -> zOrbitTrans );

	//Create the normal matrix
	this -> normal = rotX * rotY * rotZ * axisRot * (orbitTrans * orbitRot);

	//Create the local to world matrix (ie Model)
	this -> world = scale * rotX * rotY * rotZ * axisRot * (orbitTrans * orbitRot) * trans;

	// Create the ModelView ( LocalToWorld * View)
	// Some pipelines have the project concatenated, others don't
	// Best to keep the separated, you can always join them with a quick multiply
	CameraManager* cm = CameraManager::getInstance();

	this -> modelView = this -> world * cm -> getCam1() -> getViewMatrix();

	//Since we are using the supplier flat shader we need to send it the
	//combined modelView and Projection Matrices
	this -> modelViewProj = this -> modelView * cm -> getCam1() -> getProjMatrix();

	//Transform the lighting position
	this -> transformedLightPos = this -> lightPos;//  * cm -> getCam1() -> getViewMatrix();  Looks like I do not need this for now
	
}

void SquareObject::setRenderState()
{
	CameraManager* cm = CameraManager::getInstance();
	GlobalVariableManager* gvm = GlobalVariableManager::getInstance();

	if(blend)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	if (gvm -> getWireFrameMode() == true)
	{
		//Draw line antialiased
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glLineWidth(gvm -> getWireFrameLineWidth());

		glDisable(GL_CULL_FACE);

		ShaderManager *sm = ShaderManager::getInstance();
		sm ->useFlatShader(this -> modelViewProj,
							gvm -> getWireFrameColor());
	}

	else if (shaderID == POINT_LIGHT_DIFFUSE)
	{
		glDisable(GL_CULL_FACE);
		
		ShaderManager *sm = ShaderManager::getInstance();
		sm ->usePointLightDiffuseShader(this -> modelViewProj,
										this -> modelView,
										this -> normal,
										this -> diffuseColor,
										this -> transformedLightPos);
	}

	else if (shaderID == TEXTURE_POINT_LIGHT_DIFFUSE)
	{
		//Bind the texture
		TextureManager *tm = TextureManager::getInstance();
		tm -> bind2DTexture(this -> textureID);

		glDisable(GL_CULL_FACE);

		ShaderManager *sm = ShaderManager::getInstance();
		sm -> useTexturePointLightDiffuseShader(this -> modelViewProj,
												this -> modelView,
												this -> normal,
												this -> diffuseColor,
												this -> transformedLightPos);
	}

	else if (shaderID == GOURAUD)
	{
		glDisable(GL_CULL_FACE);
		
		ShaderManager *sm = ShaderManager::getInstance();
		sm -> useGouraudShader(this -> modelViewProj,
								this -> modelView,
								this -> normal,
								this -> ambientColor,
								this -> diffuseColor,
								this -> specularColor,
								this -> shininess,
								this -> transformedLightPos);
	}

	else if (shaderID == TEXTURE_GOURAUD)
	{
		glDisable(GL_CULL_FACE);
		
		//Bind the texture
		TextureManager *tm = TextureManager::getInstance();
		tm -> bind2DTexture(this -> textureID);
		
		ShaderManager *sm = ShaderManager::getInstance();
		sm -> useTextureGouraudShader(this -> modelViewProj,
										this -> modelView,
										this -> normal,
										this -> ambientColor,
										this -> diffuseColor,
										this -> specularColor,
										this -> shininess,
										this -> transformedLightPos);
	}

	else if (shaderID == PHONG)
	{
		glDisable(GL_CULL_FACE);
		
		ShaderManager *sm = ShaderManager::getInstance();
		sm ->usePhongShader(this -> modelViewProj,
										this -> modelView,
										this -> normal,
										this -> ambientColor,
										this -> diffuseColor,
										this -> specularColor,
										this -> shininess,
										this -> transformedLightPos);
	}

	else if (shaderID == TEXTURE_PHONG)
	{
		glDisable(GL_CULL_FACE);
		
		//Bind the texture
		TextureManager *tm = TextureManager::getInstance();
		tm -> bind2DTexture(this -> textureID);
		
		ShaderManager *sm = ShaderManager::getInstance();
		sm ->useTexturePhongShader(this -> modelViewProj,
										this -> modelView,
										this -> normal,
										this -> ambientColor,
										this -> diffuseColor,
										this -> specularColor,
										this -> shininess,
										this -> transformedLightPos);
	}

	else if (shaderID == DISSOLVE)
	{
		//Bind the texture
		TextureManager *tm = TextureManager::getInstance();
		tm -> bind2DTexture(this -> textureID);
		
		ShaderManager *sm = ShaderManager::getInstance();
		sm -> useDissolveShader(this -> modelViewProj,
							   this -> modelView,
							   this -> normal,
							   this -> ambientColor,
							   this -> diffuseColor,
							   this -> specularColor,
							   this -> shininess,
							   this -> transformedLightPos,
							   this -> dissolveFactor);
	}

	else if (shaderID == CELL)
	{
		TextureManager *tm = TextureManager::getInstance();
		
		tm ->load1DTexture(this -> colorArray, 4);
		
		//Bind the texture
		tm -> bind1DTexture(this -> textureID);
		
		ShaderManager *sm = ShaderManager::getInstance();
		sm -> useCellShader(this -> modelViewProj,
						    this -> modelView,
						    this -> normal,
						    this -> transformedLightPos);


	}

	else
	{
		glDisable(GL_CULL_FACE);

		ShaderManager *sm = ShaderManager::getInstance();
		sm ->useFlatShader(this -> modelViewProj,
							this -> diffuseColor);
	}
}

void SquareObject::draw()
{
	Square* square = Square::getInstance();

	square -> draw();

	//Put everything back to the default
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLineWidth(1.0f);
	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	glEnable(GL_CULL_FACE);
}