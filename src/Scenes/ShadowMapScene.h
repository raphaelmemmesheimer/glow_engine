#ifndef SHADOWMAPSCENE_H

#define SHADOWMAPSCENE_H
#include "../System/Scene.h"
#include <glm/glm.hpp>
#include "../System/CTMModel.h"
#include "../System/AssimpModel.h"
#include "../Shapes/Quad.h"
#include <glm/gtc/matrix_transform.hpp>

class ShadowMapScene : public Scene {
	glm::mat4 projection;
	glm::mat4 modelview;

	Quad* quad;
	Mesh* model;
public:
	ShadowMapScene();
	virtual ~ShadowMapScene();

	void init();
	void draw();
	void resize(int width, int height);
	void update();

	void handleMousePos(int x, int y);
	void handleMouseScroll(int hor, int vert);
	void handleMouseWheel(int mouseWheelPos);
	void handleKeyboard(int key, int action);
};


#endif /* end of include guard: SHADOWMAPSCENE_H */
