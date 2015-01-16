#include "Vector2D.h"


Vector2D::Vector2D(float x, float y)
{
	xPos = x;
	yPos = y;
}
Vector2D::~Vector2D(void)
{
	delete(this);
}

float Vector2D:: getLenght()
{
	return sqrt(xPos * xPos + yPos * yPos);
}

float Vector2D:: getDot(Vector2D *vector2D)
{
	return xPos * vector2D ->getXpos() + yPos * vector2D->getYpos();
}

float Vector2D:: getXpos()
{
	return xPos;
}

void Vector2D:: setXpos(float x)
{
	xPos = x;
}

float Vector2D:: getYpos()
{
	return yPos;
}

void Vector2D:: setYpos(float y)
{
	yPos = y; 
}

Vector2D* Vector2D::normalize() 
{

	float lenght = getLenght();
	xPos/= lenght;
	yPos/= lenght;

	return this; 
}

Vector2D* Vector2D::add(Vector2D* vector2d)
{
 Vector2D *vect = new Vector2D(vector2d->getXpos() + xPos , vector2d->getYpos() + yPos);
 return vect;
}

Vector2D* Vector2D::add(float r)
{
 Vector2D *vect = new Vector2D(r + xPos ,r + yPos);
 return vect;
}

Vector2D* Vector2D::substract(Vector2D * vector2d)
{
 Vector2D *vect = new Vector2D(vector2d->getXpos() - xPos , vector2d->getYpos() - yPos);
 return vect;
}

Vector2D* Vector2D::subctract(float r)
{
 Vector2D *vect = new Vector2D(r - xPos ,r - yPos);
 return vect;
}

Vector2D* Vector2D::multiply(Vector2D * vector2d)
{
 Vector2D *vect = new Vector2D(vector2d->getXpos() * xPos , vector2d->getYpos() * yPos);
 return vect;
}

Vector2D* Vector2D::multiply(float r)
{
 Vector2D *vect = new Vector2D(r * xPos ,r * yPos);
 return vect;
}

Vector2D* Vector2D::divide(Vector2D * vector2d)
{
 Vector2D *vect = new Vector2D(vector2d->getXpos() / xPos , vector2d->getYpos() / yPos);
 return vect;
}

Vector2D* Vector2D::divide(float r)
{
 Vector2D *vect = new Vector2D(r / xPos ,r / yPos);
 return vect;
}

Vector2D* Vector2D::rotate(float r){
	
	double rad = r * (PI/180);
	double cos_ =  cos(rad);
	double sin_ = sin(rad);

	Vector2D *vect = new Vector2D((float)(xPos * cos_ - yPos * sin_),(float)(xPos * sin_ + yPos * cos_));
	return vect;
}

