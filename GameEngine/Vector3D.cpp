#include "Vector3D.h"
#include "Quaterions.h"


Vector3D::Vector3D(float x, float y, float z)
{
	xPos = x;
	yPos = y;
	zPos = z;
}


Vector3D::~Vector3D(void)
{
}

float Vector3D:: getXpos()
{
	return xPos;
}

void Vector3D:: setZpos(float z)
{
	xPos = z;
}

float Vector3D:: getZpos()
{
	return zPos;
}

void Vector3D:: setXpos(float x)
{
	xPos = x;
}

float Vector3D:: getYpos()
{
	return yPos;
}

void Vector3D:: setYpos(float y)
{
	yPos = y; 
}
float Vector3D:: getLenght()
{
	return sqrt(xPos * xPos + yPos * yPos + zPos * zPos);
}

float Vector3D:: getDot(Vector3D* vector3D)
{
	return xPos * vector3D->getXpos() + yPos *  vector3D->getYpos();
}

Vector3D* Vector3D:: getCrossProduct(Vector3D* vector3D) 
{	
	float x_ = yPos * vector3D -> getZpos()  - zPos * vector3D -> getYpos();
	float y_ = zPos * vector3D -> getXpos()  - zPos * vector3D -> getZpos();
	float z_ = xPos * vector3D -> getYpos()  - yPos * vector3D -> getXpos();
	Vector3D *vect = new Vector3D(x_,y_,z_);
	return vect;
}
Vector3D* Vector3D::normalize() 
{

	float lenght = getLenght();
	xPos/= lenght;
	yPos/= lenght;
	zPos/= lenght;

	return this; 
}

Vector3D* Vector3D::add(Vector3D* vector3d)
{
 Vector3D *vect = new Vector3D(xPos + vector3d -> getXpos() , yPos + vector3d -> getYpos(),zPos + vector3d -> getZpos());
 return vect;
}

Vector3D* Vector3D::add(float r)
{
 Vector3D *vect = new Vector3D(xPos + r ,yPos + r ,zPos + r);
 return vect;
}

Vector3D* Vector3D::substract(Vector3D* vector3d)
{
	Vector3D *vect = new Vector3D(xPos - vector3d -> getXpos() ,yPos - vector3d -> getYpos(),zPos - vector3d -> getZpos());
 return vect;
}

Vector3D* Vector3D::subctract(float r)
{
 Vector3D *vect = new Vector3D(xPos - r ,yPos - r,zPos - r);
 return vect;
}

Vector3D* Vector3D::multiply(Vector3D* vector3d)
{
	Vector3D *vect = new Vector3D(xPos * vector3d -> getXpos() ,yPos * vector3d -> getYpos(),zPos * vector3d -> getZpos());
 return vect;
}

Vector3D* Vector3D::multiply(float r)
{
 Vector3D *vect = new Vector3D(xPos * r ,yPos * r,zPos * r);
 return vect;
}

Vector3D* Vector3D::divide(Vector3D* vector3d)
{
	Vector3D *vect = new Vector3D(xPos / vector3d->getXpos() ,yPos / vector3d->getXpos(),zPos / vector3d->getXpos());
 return vect;
}

Vector3D* Vector3D::divide(float r)
{
 Vector3D *vect = new Vector3D(xPos/r ,yPos/r, zPos/r );
 return vect;
}

Vector3D* Vector3D::rotate(float angle, Vector3D* axis){
	
	Vector3D* vect = new Vector3D(getXpos(), getYpos(),getZpos());
	double rad = angle * (PI/180);
	float sinHalfAngle =  (float)sin(rad/2);
	float cosHalfAngle =  (float)cos(rad/2);

	float rX = axis->getXpos() * sinHalfAngle;
	float rY = axis->getYpos() * sinHalfAngle;
	float rZ = axis->getZpos() * sinHalfAngle;
	float rW = cosHalfAngle;

	Quaterions * rotation = new Quaterions(rX,rY,rZ,rW);
	Quaterions * conjugate = rotation->cojugate();

	Quaterions* w = rotation->multiplyWithVector(vect);
	w->multiply(conjugate);

	xPos = w->getXpos();
	yPos = w->getYpos();
	zPos = w->getZpos();

	return this;
	
}