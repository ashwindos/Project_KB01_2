#include "MathMatrix.h"


MathMatrix::MathMatrix(void)
{
}


MathMatrix::~MathMatrix(void)
{
}

float MathMatrix ::get(int x, int y)
{
	return mMatrix[x][y]; 
}

void MathMatrix ::setValue(int x, int y, float value)
{
	mMatrix[x][y] = value;
}

MathMatrix* MathMatrix ::initIdentity()
{
	mMatrix[0][0] = 1;	mMatrix[1][0] = 0;	mMatrix[2][0] = 0;	mMatrix[3][0] = 0;
	mMatrix[0][1] = 0;	mMatrix[1][1] = 1;	mMatrix[2][1] = 0;	mMatrix[3][1] = 0;
	mMatrix[0][2] = 0;	mMatrix[1][2] = 0;	mMatrix[2][2] = 1;	mMatrix[3][2] = 0;
	mMatrix[0][3] = 0;	mMatrix[1][3] = 0;	mMatrix[2][3] = 0;	mMatrix[3][3] = 1;

	return this;
}

MathMatrix* MathMatrix ::initTranslation(float x, float y, float z)
{
	mMatrix[0][0] = 1;	mMatrix[1][0] = 0;	mMatrix[2][0] = 0;	mMatrix[3][0] = x;
	mMatrix[0][1] = 0;	mMatrix[1][1] = 1;	mMatrix[2][1] = 0;	mMatrix[3][1] = y;
	mMatrix[0][2] = 0;	mMatrix[1][2] = 0;	mMatrix[2][2] = 1;	mMatrix[3][2] = z;
	mMatrix[0][3] = 0;	mMatrix[1][3] = 0;	mMatrix[2][3] = 0;	mMatrix[3][3] = 1;

	return this;
}

MathMatrix* MathMatrix ::initRotation(float x, float y, float z)
{
	MathMatrix * rx = new MathMatrix();
	MathMatrix * ry = new MathMatrix();
	MathMatrix * rz = new MathMatrix();

	x = x * (PI/180);
	y = y * (PI/180);
	z = z * (PI/180);

	rx->mMatrix[0][0] = 1;			rx->mMatrix[1][0] = 0;			rx->mMatrix[2][0] = 0;				rx->mMatrix[3][0] = 0;
	rx->mMatrix[0][1] = 0;			rx->mMatrix[1][1] = cos(x);		rx->mMatrix[2][1] = -sin(x);		rx->mMatrix[3][1] = 0;
	rx->mMatrix[0][2] = 0;			rx->mMatrix[1][2] = sin(x);		rx->mMatrix[2][2] = cos(x);			rx->mMatrix[3][2] = 0;
	rx->mMatrix[0][3] = 0;			rx->mMatrix[1][3] = 0;			rx->mMatrix[2][3] = 0;				rx->mMatrix[3][3] = 1;

	ry->mMatrix[0][0] = cos(y);		ry->mMatrix[1][0] = 0;			ry->mMatrix[2][0] = -sin(y);		ry->mMatrix[3][0] = 0;
	ry->mMatrix[0][1] = 0;			ry->mMatrix[1][1] = 1;			ry->mMatrix[2][1] = 0;				ry->mMatrix[3][1] = 0;
	ry->mMatrix[0][2] = sin(y);		ry->mMatrix[1][2] = 0;			ry->mMatrix[2][2] = cos(y);			ry->mMatrix[3][2] = 0;
	ry->mMatrix[0][3] = 0;			ry->mMatrix[1][3] = 0;			ry->mMatrix[2][3] = 0;				ry->mMatrix[3][3] = 1;

	rz->mMatrix[0][0] = cos(z);		rz->mMatrix[1][0] = -sin(z);	rz->mMatrix[2][0] = 0;				rz->mMatrix[3][0] = 0;
	rz->mMatrix[0][1] = sin(z);		rz->mMatrix[1][1] = cos(z);		rz->mMatrix[2][1] = 0;				rz->mMatrix[3][1] = 0;
	rz->mMatrix[0][2] = 0;			rz->mMatrix[1][2] = 0;			rz->mMatrix[2][2] = 1;				rz->mMatrix[3][2] = 0;
	rz->mMatrix[0][3] = 0;			rz->mMatrix[1][3] = 0;			rz->mMatrix[2][3] = 0;				rz->mMatrix[3][3] = 1;


	return rz->multiply(*ry->multiply(*rx));
}

MathMatrix* MathMatrix ::multiply(MathMatrix mMatrix)
{
	MathMatrix *nMatrix = new MathMatrix();

	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			nMatrix ->setValue(i,j, mMatrix.get(i,0) * nMatrix ->get(0,j) + 
									mMatrix.get(i,1) * nMatrix ->get(1,j) +
									mMatrix.get(i,2) * nMatrix ->get(2,j) +
									mMatrix.get(i,3) * nMatrix ->get(3,j));
		}
	}

	return nMatrix;
}


