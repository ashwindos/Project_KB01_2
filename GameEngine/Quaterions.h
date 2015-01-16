#ifndef _QUATERNIONS_H
#define _QUATERNIONS_H
#include <math.h>

class Vector3D;
class Quaterions
{
public:
	/// the constructor of the quaternion
	Quaterions(float x, float y , float z, float w  );
	/// the destructor of the quaternion
	~Quaterions(void);
	///the mutator of the X position
	void setXpos(float x);
	///the accesor of the X position
	float getXpos();
	///the accesor of the Y position
	void setYpos(float y);
	///the mutator of the Y position
	float getYpos();
	///the accesor of the Z position
	void setZpos(float Z);
	///the mutator of the Z position
	float getZpos();
	///the accesor of the W position
	void setWpos(float w);
	///the accesor of the W position
	float getWpos();
	///the mutator of the X position
	float lenght();
	///this method normalizes the quarternion
	Quaterions* normalize();
	///this method returns the cojugate of the quaternion
	Quaterions* cojugate();
	///this method multiplys the quartion with another quartion
	Quaterions* multiply(Quaterions* quart);
	///this method multiplys a quaternion and vector 
	Quaterions* multiplyWithVector(Vector3D* vect);

private:
	float xPos;
	float yPos;
	float zPos;
	float wPos; 
	
};
#endif

