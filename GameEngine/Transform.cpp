#include "Transform.h"


Transform::Transform(void)
{
	translation = new Vector3D(0,0,0);
}


Transform::~Transform(void)
{
}

void Transform:: setTranslation(Vector3D* vect)
{
	translation = vect;
}

void Transform:: setTranslation(float x, float y , float z)
{
	Vector3D* vect = new Vector3D(x,y,z);
	translation = vect;
}
Vector3D* Transform:: getTranslation()
{
	return translation;
}

void Transform:: setRotation(Vector3D* vect)
{
	rotation = vect;
}

void Transform:: setRotation(float x, float y , float z)
{
	Vector3D* vect = new Vector3D(x,y,z);
	rotation = vect;
}
Vector3D* Transform:: getRotation()
{
	return rotation;
}

MathMatrix* Transform::getTransformation()
{
	MathMatrix * transmMAtrix = new MathMatrix();
	transmMAtrix->initTranslation(translation->getXpos(),translation->getYpos(),translation->getZpos());

	MathMatrix * rotmMAtrix = new MathMatrix();
	rotmMAtrix->initRotation(rotation->getXpos(),rotation->getYpos(),rotation->getZpos());


	return transmMAtrix->multiply(*rotmMAtrix);

}

