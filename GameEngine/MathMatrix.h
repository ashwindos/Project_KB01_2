#ifndef _MATHMATRIX_H
#define _MATHMATRIX_H
#define SIZE 4
#define PI 3.14159265
#include <math.h>

class MathMatrix
{
public:
	MathMatrix(void);
	~MathMatrix(void);
	float mMatrix [SIZE][SIZE];
	float get(int x, int y);
	///this is a mutator for a value in the 2d array
	void setValue(int x, int y, float value);
	/// this method inintializes the matrix
	MathMatrix* initIdentity();
	/// this method initializes the tranlation matrix
	MathMatrix* initTranslation(float x, float y, float z);
	/// this method intializes the rotation for the matrix
	MathMatrix* initRotation(float x, float y, float z);
	///this method multiplys 2 matrices.
	MathMatrix* multiply(MathMatrix  mMatrix);

};
#endif

