#include "Camera.h"




void Camera::set_center(float x, float y)
{
	view.setCenter(x, y);
}

void Camera::move()
{
	view.move(0.1f, 0.0f);
}
void Camera::reset(int width, int height)
{
	view.reset(FloatRect(0.0f, 0.0f, width, height));
}
View Camera::get_view()
{
	return view;
}
Camera::Camera()
{

}


Camera::~Camera()
{
}
