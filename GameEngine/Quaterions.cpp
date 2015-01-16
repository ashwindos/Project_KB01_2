#include "Quaterions.h"
#include "Vector3D.h"



Quaterions::Quaterions(float x, float y , float z, float w)
{
	xPos = x;
	yPos = y;
	zPos = z;
	wPos = w;
}


Quaterions::~Quaterions(void)
{
}

void Quaterions::setXpos(float x)
{
	xPos = x;
}

float Quaterions::getXpos()
{
	return xPos;
}

void Quaterions::setYpos(float y)
{
	yPos = y;
}

float Quaterions::getYpos()
{
	return yPos;
}
void Quaterions::setZpos(float z)
{
	zPos = z;
}

float Quaterions::getZpos()
{
	return zPos;
}
void Quaterions::setWpos(float w)
{
	wPos = w;
}

float Quaterions::getWpos()
{
	return wPos;
}

float Quaterions:: lenght()
{
	return sqrt(xPos * xPos +yPos * yPos + zPos * zPos + wPos * wPos);
}

Quaterions* Quaterions::normalize()
{
	 float lenght = this->lenght();
	 xPos/= lenght;
	 yPos/= lenght;
	 zPos/= lenght;
	 wPos/= lenght;

	 return this;
}

Quaterions* Quaterions::cojugate()
{
	Quaterions *quart = new Quaterions(-xPos, -yPos, -zPos,wPos);
	return quart;
	
}

Quaterions* Quaterions::multiply(Quaterions* quart)
{ 
	float w_ = wPos * quart -> getWpos() - xPos * quart ->getXpos() - yPos * quart ->getYpos() - zPos * quart ->getZpos();
	float x_ = xPos * quart -> getWpos() + wPos * quart ->getXpos() + yPos * quart ->getZpos() - zPos * quart ->getYpos();
	float y_ = yPos * quart -> getWpos() + wPos * quart ->getYpos() + zPos * quart ->getXpos() - xPos * quart ->getZpos();
	float z_ = zPos * quart -> getWpos() + wPos * quart ->getZpos() + xPos * quart ->getYpos() - yPos * quart ->getXpos();
	
	Quaterions* quarti = new Quaterions(x_, y_, z_, w_);
	return quarti;
}

Quaterions* Quaterions::multiplyWithVector(Vector3D* vect)
{
	float w_ = -xPos * vect -> getXpos() - yPos * vect -> getYpos() - zPos * vect -> getZpos();
	float x_ =  wPos * vect -> getXpos() + yPos * vect -> getZpos() - zPos * vect -> getYpos();
	float y_ =  wPos * vect -> getYpos() + zPos * vect -> getXpos() - xPos * vect -> getZpos();
	float z_ =  wPos * vect -> getZpos() + xPos * vect -> getYpos() - yPos * vect -> getXpos();
	
	Quaterions * quart = new Quaterions(x_, y_, z_, w_);
	return quart;
}