#ifndef _VECTOR2D_H
#define _VECTOR2D_H
#include <math.h> 
#define PI 3.14159265
 
class Vector2D
{
public:
	Vector2D(float x, float y);
	~Vector2D(void);
	/// the accessor for the X posistion
	float getXpos();
	/// the mutator for the X posistion
	void setXpos(float x);
	/// the accessor for the X posistion
	float getYpos();
	/// the mutator for the X posistion
	void setYpos(float y);
	 	
private:
	float xPos;
	float yPos;

	/// this method returns the lenght of a 2d vector
	float getLenght();
	/// this method returns the dot of a 2d vector
	float getDot(Vector2D *vector2d);
	/// this method normalizes a 2d vector
	Vector2D* normalize();
	/// this method adds two  2d vectors
	Vector2D* add(Vector2D *vector2d);
	/// this method adds a amount to a 2d vectors
	Vector2D* add(float r);
	/// this method substracts a 2dvector from a 2d vectors
	Vector2D* substract(Vector2D *vector2d);
	/// this method substracts a 2dvector from a amount
	Vector2D* subctract(float r);
	/// this method multiplys a 2d vector to a 2d vectors
	Vector2D* multiply(Vector2D *vector2d);
	/// this method multiplys a amount to a 2d vectors
	Vector2D* multiply(float r);
	/// this method divides a 2d vector from a 2d vectors
	Vector2D* divide(Vector2D *vector2d);
	/// this method divides a amount to a 2d vectors
	Vector2D* divide(float r);
	/// this method roates a a 2d vectors
	Vector2D* rotate(float angle);
};
#endif

