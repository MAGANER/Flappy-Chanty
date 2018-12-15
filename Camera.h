#pragma once
#include"stdafx.h"
class Camera
{
private:
	View view;
public:
	void set_center(float x, float y);
	void move();
	void reset(int width, int height);
	View get_view();
	Camera();
	~Camera();
};

