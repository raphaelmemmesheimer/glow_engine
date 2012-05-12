#ifndef FLUT_H

#define FLUT_H

#include "../System/Scene.h"
#include <glm/gtc/matrix_transform.hpp>
#include "../System/Engine.h"
#include "../System/ObjModel.h"
#include "../Shapes/Quad.h"


class Flut : Scene 
{
private:
	//Engine* engine;
	glm::mat4 projection;
	glm::mat4 modelview;

	Quad* quad;
	ObjModel* model;
public:
	Flut();
	~Flut();
	void init();
	void draw();
	void resize(int width, int height);
	void update();

	void handleMousePos(int x, int y);
	void handleMouseScroll(int hor, int vert);
	void handleMouseWheel(int mouseWheelPos);
	void handleKeyboard(int key, int action);
};


#endif /* end of include guard: FLUT_H */
