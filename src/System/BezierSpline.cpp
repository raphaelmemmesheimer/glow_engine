#include "BezierSpline.h"


BezierSpline::BezierSpline()
{
	_controlPoints.clear();
}

BezierSpline::~BezierSpline()
{
}

vector<glm::vec3> copyPoints;


glm::vec3 interpolate(glm::vec3 p1,glm::vec3 p2, float t){
	return (glm::vec3(1.0-t)*p1)+(glm::vec3(t)*p2);
}

// *** 3D Punkt fuer Parameter t bestimmen
glm::vec3 BezierSpline::deCasteljau(float t)
{
	int n;
	int i;

	copyPoints = _controlPoints; // Kopie erstellen
	for (n = copyPoints.size()-2; n >= 0; n--)
		for (i = 0; i <= n; i++)
		{
			copyPoints[i] = interpolate(copyPoints[i],copyPoints[i+1],t);
			//copyPoints[i] = copyPoints[i].interpolate(copyPoints[i+1],t);

		}
	return copyPoints[0];
}

// neuen Punkt anfuegen
void BezierSpline::addPoint(glm::vec3 newPoint)
{
    _controlPoints.push_back(newPoint);
    //generateAndBindBuffers();
}

void BezierSpline::generateAndBindBuffers(int resolution) {
	//float resolution = 20.0;
	float epsylon = 1.0 / (float)resolution;



	glGenVertexArrays(1,&vaoID);
	glBindVertexArray(vaoID);

	vertices.clear();
	indices.clear();
	int tmpi = 0;
	for (unsigned int i = 0 ; i < _controlPoints.size() ; i++) {
		for (float t = 0.0; t <= 1+epsylon; t+= (1.0 / resolution)){
			glm::vec3 tmp = deCasteljau(t);
			//glm::vec3 tmp = interpolate(_controlPoints[i],_controlPoints[i+1],t);
			vertices.push_back(tmp);
			indices.push_back(indices.size());
		}

	}

	GLuint* tindices;
	tindices = new GLuint[indices.size()];

//	for (int x = 0; x < indices.size(); ++x) {
//		tindices[x] = indices[x];
//		//printf("xxx %d \n",tindices[x]);
//	}

	//vertices
    printf("loading vertices bspline\n");
	if (vertices.size()) {
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ARRAY_BUFFER,vboID);
		glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(GL_FLOAT) * 3 ,&vertices[0],GL_STATIC_DRAW);
		glEnableVertexAttribArray(SH_VERTEX);
		glVertexAttribPointer(SH_VERTEX,3,GL_FLOAT,GL_FALSE,0,0);
	}
	if (indices.size()) {
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,(indices.size())* sizeof(indices[0]),&indices[0],GL_STATIC_DRAW);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(tindices),tindices,GL_STATIC_DRAW);
	}

	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

//	for (int i = 0; i < vertices.size();i++){
//		printf("%f %f %f \n",vertices[i].x,vertices[i].y,vertices[i].z);
//
//	}

}

void BezierSpline::generateAndBindBuffersControlPoints() {

	glGenVertexArrays(1,&vaoIDControlPoints);
	glBindVertexArray(vaoIDControlPoints);

	//vertices
    printf("loading vertices\n");
	if (_controlPoints.size()) {
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ARRAY_BUFFER,vboID);
		glBufferData(GL_ARRAY_BUFFER,_controlPoints.size()*sizeof(GL_FLOAT) * 3 ,&_controlPoints[0],GL_STATIC_DRAW);
		glEnableVertexAttribArray(SH_VERTEX);
		glVertexAttribPointer(SH_VERTEX,3,GL_FLOAT,GL_FALSE,0,0);
	}

	for (int i = 0; i < _controlPoints.size(); ++i) {
		indices.push_back(i);
	}

	if (indices.size()) {
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,(indices.size())* sizeof(indices[0]),&indices[0],GL_STATIC_DRAW);
	}

	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

// *** Spline in <resolution> Schritten al GL_LINE_STRIP zeichnen
void BezierSpline::draw()
{
	glLineWidth(2.0);
	glBindVertexArray(this->vaoID);
	glPointSize(10.0);
	glDrawElements(GL_LINE_LOOP,indices.size()*sizeof(indices)[0] * 3,GL_UNSIGNED_INT,0); //vertexCount*3*2
	glDrawElements(GL_POINTS,indices.size()*sizeof(indices)[0] * 3,GL_UNSIGNED_INT,0); //vertexCount*3*2
	glBindVertexArray(0);
}

void BezierSpline::drawControlPoints()
{
	//generateAndBindBuffersControlPoints();
	glPointSize(10.0);
	glLineWidth(1.0);
	glBindVertexArray(this->vaoIDControlPoints);
	glDrawElements(GL_LINE_LOOP,_controlPoints.size()*sizeof(_controlPoints)[0] * 3,GL_UNSIGNED_INT,0); //vertexCount*3*2
	glDrawElements(GL_POINTS,_controlPoints.size()*sizeof(_controlPoints)[0] * 3,GL_UNSIGNED_INT,0); //vertexCount*3*2
	glBindVertexArray(0);
}

