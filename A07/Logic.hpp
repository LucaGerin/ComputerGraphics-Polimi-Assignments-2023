#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/quaternion.hpp>

glm::mat4 ViewPrj_Previous = glm::mat4(1);

void GameLogic(Assignment07 *A, float Ar, glm::mat4 &ViewPrj, glm::mat4 &World) {
	// The procedure must implement the game logic  to move the character in third person.
	// Input:
	// <Assignment07 *A> Pointer to the current assignment code. Required to read the input from the user
	// <float Ar> Aspect ratio of the current window (for the Projection Matrix)
	// Output:
	// <glm::mat4 &ViewPrj> the view-projection matrix of the camera
	// <glm::mat4 &World> the world matrix of the object

	// Parameters
	// Camera FOV-y, Near Plane and Far Plane
	const float FOVy = glm::radians(45.0f);
	const float nearPlane = 0.1f;
	const float farPlane = 100.f;
	
	// Player starting point
	const glm::vec3 StartingPosition = glm::vec3(-41.50, 0.0, -19.5);
	
	// Camera target height and distance
	const float camHeight = 0.25;
	const float camDist = 1.5;
	// Camera Pitch limits
	const float minPitch = glm::radians(-8.75f);
	const float maxPitch = glm::radians(60.0f);
	// Rotation and motion speed
	const float ROT_SPEED = glm::radians(120.0f);	//omega
	const float MOVE_SPEED = 2.0f;					//mu

	// Integration with the timers and the controllers
	// returns:
	// <float deltaT> the time passed since the last frame
	// <glm::vec3 m> the state of the motion axes of the controllers (-1 <= m.x, m.y, m.z <= 1)
	// <glm::vec3 r> the state of the rotation axes of the controllers (-1 <= r.x, r.y, r.z <= 1)
	// <bool fire> if the user has pressed a fire button (not required in this assginment)
	float deltaT;
	glm::vec3 m = glm::vec3(0.0f), r = glm::vec3(0.0f);
	bool fire = false;
	A->getSixAxis(deltaT, m, r, fire);

	// Game Logic implementation
	// Current Player Position - statc variables make sure that their value remain unchanged in subsequent calls to the procedure
	static glm::vec3 Pos = StartingPosition;
	static float alpha, beta, rho;
	static float yaw, pitch, roll;

	//yaw = 0.0f; //starting angle pointing 0 degrees north

	glm::vec3 ux = glm::vec3(glm::rotate(glm::mat4(1), yaw, glm::vec3(0, 1, 0)) *  
		glm::vec4(1, 0, 0, 1));  
	glm::vec3 uy = glm::vec3(0, 1, 0);  
	glm::vec3 uz = glm::vec3(glm::rotate(glm::mat4(1), yaw, glm::vec3(0, 1, 0)) *  
		glm::vec4(0, 0, -1, 1));  

	pitch += ROT_SPEED * r.x * deltaT;
	pitch = glm::clamp(pitch, minPitch, maxPitch);
	//if (pitc)
	yaw += ROT_SPEED * r.y * deltaT;
	roll += ROT_SPEED * r.z * deltaT;

	Pos += ux * MOVE_SPEED * m.x * deltaT;
	Pos += uy * MOVE_SPEED * m.y * deltaT;
	Pos += uz * MOVE_SPEED * m.z * deltaT;


	// To be done in the assignment
	//WORLD MATRIX
	//glm::mat4 Mw = makeWorldEuler(pos, alpha, beta, rho);
	/* 
	glm::quat qe = glm::quat(glm::vec3(0, yaw, 0)) *
		glm::quat(glm::vec3(pitch, 0, 0)) *
		glm::quat(glm::vec3(0, 0, roll));
	glm::quat qeNorm = glm::normalize(qe);
	glm::mat4 R = glm::mat4(qeNorm);	//rotation matrix

	glm::mat4 Mw =
		glm::translate(glm::mat4(1.0), Pos) *
		R *				
		glm::scale(glm::mat4(1.0), glm::vec3(1,1,1));
	*/

	glm::vec3 xAxis = glm::vec3(1, 0, 0);
	glm::vec3 yAxis = glm::vec3(0, 1, 0);
	glm::vec3 zAxis = glm::vec3(0, 0, 1);

	//glm::mat4 P = glm::perspective(FOVy, Ar, nearPlane, farPlane);
	//P[1][1] *= -1;

	glm::mat4 R_x = glm::rotate(glm::mat4(1.0f), pitch, xAxis);
	glm::mat4 R_y = glm::rotate(glm::mat4(1.0f), yaw, yAxis);
	glm::mat4 R_z = glm::rotate(glm::mat4(1.0f), roll, zAxis);

	//World = glm::translate(glm::mat4(1.0), glm::vec3(Pos)) * R_y * R_x * R_z * glm::scale(glm::mat4(1.0), glm::vec3(1, 1, 1));
	World = glm::translate(glm::mat4(1.0), glm::vec3(Pos)) * glm::scale(glm::mat4(1.0), glm::vec3(1, 1, 1));

	//World = Mw;

	//VIEW-PROJECTION MATRIX
	glm::mat4 Mp = glm::perspective(FOVy, Ar, nearPlane, farPlane);
	Mp[1][1] *= -1;

	glm::vec3 u = glm::vec3(0, 1, 0);
	glm::vec3 a = glm::vec3(World * glm::vec4(0, 0, 0, 1.0)) + glm::vec3(0, camHeight, 0);
	glm::vec3 c = glm::vec3(World * R_y * glm::vec4(0, camHeight + camDist * sin(pitch), camDist * cos(pitch), 1));
	//glm::vec3 a = glm::vec3( World * glm::vec4(0, 0, 0, 1.0) + (0, 0, camHeight) );
	

	/* explicit computation of Mv /*
	glm::vec3 vz = glm::normalize(c - a);
	glm::vec3 vx = glm::normalize(glm::cross(u, vz));
	glm::vec3 vy = glm::cross(vz, vx);
	glm::mat4 Mc = glm::mat4(glm::vec4(vx, 0), glm::vec4(vy, 0), glm::vec4(vz, 0), glm::vec4(c, 0, 0, 1));
	//glm::mat4 Mc = glm::mat4(glm::vec4(vx, 0), glm::vec4(vy, 0), glm::vec4(vz, 0), glm::vec4(0, 0, 0, 1));
	glm::mat4 Mv = glm::inverse(Mc);
	/**/
	//using LookAt() function
	glm::mat4 Mv = glm::lookAt(c, a, u);
	Mv = glm::rotate(glm::mat4(1.0f), -roll, glm::vec3(0, 0, 1)) * Mv;


	glm::mat4 Mvp = Mp * Mv;
	ViewPrj = Mvp;	


	//Damping
	float damp_speed = 25.0;
	ViewPrj = ViewPrj_Previous * exp(-damp_speed * deltaT) + ViewPrj * (1 - exp(-damp_speed * deltaT));
	ViewPrj_Previous = ViewPrj;
	
}