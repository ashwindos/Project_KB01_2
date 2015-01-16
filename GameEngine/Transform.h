#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_
#include "Vector3D.h";
#include "MathMatrix.h"
class Transform
{
public:
	Transform(void);
	~Transform(void);
	///this method returns the transformation of the matrix/ the movement
	MathMatrix* getTransformation();
	/// muatator for the translation 3d vector
	void setTranslation(Vector3D* vect);
	/// muatator for the translation  making a new 3d vector
	void setTranslation(float x, float y , float z);
	/// the accessor for the translation 3d vector
	Vector3D* getTranslation();
	///// muatator for the rotation 3d vector
	void setRotation(Vector3D* vect);
	/// muatator for the rotation making a new 3d vector
	void setRotation(float x, float y , float z);
	/// the accessor for the rotation 3d vector
	Vector3D* getRotation();
private :
	Vector3D* translation;
	Vector3D* rotation;
	
};
#endif

