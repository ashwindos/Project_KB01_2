#include "Camera.h"

Camera::Camera(Vector3D* pos,Vector3D* forw,Vector3D* upw)
{
	posistion = pos;
	forward = forw;
	up =upw;

	up->normalize();
	forward->normalize();
}


Camera::~Camera(void)
{
}

void Camera ::move(Vector3D* dir, float amount)
{
	posistion = posistion->add(dir->multiply(amount));
}

Vector3D* Camera::getLeft()
{
	Vector3D* left = up->getCrossProduct(forward);
	left->normalize();
	return left;
}

Vector3D* Camera::getRight()
{
	Vector3D* right = forward->getCrossProduct(up);
	right->normalize();
	return right;
}
void Camera ::rotateX(float angle)
{
	Vector3D * yAxis = new Vector3D(0,1,0);
	Vector3D * hAxis = yAxis->getCrossProduct(forward);
	hAxis->normalize();

	forward->rotate(angle,hAxis);
	forward->normalize();
	up = forward->getCrossProduct(hAxis);
	up->normalize();
}
void Camera ::rotateY(float angle)
{
	Vector3D * yAxis = new Vector3D(0,1,0);
	Vector3D * hAxis = yAxis->getCrossProduct(forward);
	hAxis->normalize();

	forward->rotate(angle,yAxis);
	forward->normalize();

	up = forward->getCrossProduct(hAxis);
	up->normalize();
}

int Camera::OnKeyboardInputRecieved(char keyboardState[256])
{
	// Do whatever with the keyboard state.
	return 1;
}

int Camera::OnMouseInputRecieved(DIMOUSESTATE mouseState)
{
	// Do whatever with the mouse state.
	return 1;
}