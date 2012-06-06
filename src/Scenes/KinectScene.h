#ifndef KINECTSCENE_H

#define KINECTSCENE_H

#include "../System/Scene.h"

class KinectScene : public Scene
{
public:
	KinectScene();
	~KinectScene();
	void init();
	void draw();
	void update();
	void resize(int width, int height);
	void handleMousePos(int x, int y);
	void handleMouseWheel(int mouseWheelPos);
	void handleMouseScroll(int hor, int vert);
	void handleKeyboard(int key, int action);

private:
	/* data */
};


#endif /* end of include guard: KINECTSCENE_H */
