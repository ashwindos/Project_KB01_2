#ifndef _VECTOR3D_H
#define _VECTOR3D_H
#include <math.h> 
#define PI 3.14159265

class Quaterions;
class Vector3D
{
public:
	/// the constructor for the vector class
	Vector3D(float x, float y, float z);
	~Vector3D(void);

	/// the accessor for the X posistion
	float getXpos();
	/// the mutator for the X posistion
	void setXpos(float x);
	/// the accessor for the Y posistion
	float getYpos();
	/// the mutator for the Y posistion
	void setYpos(float z);
	/// the accessor for the Z posistion
	float getZpos();
	/// the mutator for the Z posistion
	void setZpos(float z);
	/// this method mutiplys two 3d vectors
	Vector3D* multiply(Vector3D* vector3d);
	/// this method mutiplys a vector by a amount
	Vector3D* multiply(float r);
	/// this method returns the lenght of a 3d vector
	float getLenght();
	/// this method returns the dot of 3d vector
	float getDot(Vector3D* vector3d);
	/// this method returns the corsproduct of a 3d vector
	Vector3D* getCrossProduct(Vector3D* vector3d);
	/// this method normalizes the vector
	Vector3D* normalize();
	/// this method adds two  3d vectors
	Vector3D* add(Vector3D* vector3d);
	/// this method adds a amount to a 3d vectors
	Vector3D* add(float r);
	/// this method substracts two 3d vectors
	Vector3D* substract(Vector3D* vector3d);
	/// this method substracts a 3d vectors by a amount
	Vector3D* subctract(float r);
	/// this method divides two 3d vectors
	Vector3D* divide(Vector3D* vector3d);
	/// this method divides a 3d vectors by a amount
	Vector3D* divide(float r);
	/// this method rotate a 3d vector and returns the rotated vector
	Vector3D* rotate(float angle , Vector3D* axis);
	 	
private:
	float xPos;
	float yPos;
	float zPos; 
	
};
#endif

