#ifndef __CAMERA_H_
#define __CAMERA_H_
#include "Entity.h"
#include "Vector3D.h"

class Camera : public Entity
{
public:
	/// The constructer that needs a vector in the forward direction, up direction and an position of the camera
	Camera(Vector3D* pos,Vector3D* forw,Vector3D* upw);
	~Camera(void); 
	/// Moves the camera/world 
	void move(Vector3D* dir, float amount);
private:
	Vector3D* posistion;
	Vector3D* forward;
	Vector3D* up;
	/// returns the camera vector to the left
	Vector3D* getLeft();
	/// returns the camera vector to the right
	Vector3D* getRight();
		/// Rotates the camera over the X-asis
	void rotateX(float angle);
	/// Rotates the camera over the X-asis
	void rotateY(float angle);

	
};
#endif

