
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>
#include <corecrt_math_defines.h>

void SetupProjectionMatrices(Assignment04 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

/*
* The main parallel projection uses an half-width of 10, the aspect ratio passed in parameter Ar,
* and has the near and far planes located respectively at a distance of -50 and 50.
* w=10	n=-50	f=50	a=Ar
*/

	glm::mat4 S;

	float w = 10.0;
	float n = -50.0;
	float f = 50.0;
	float a = Ar;
	
	
	glm::mat4 Port = glm::mat4(1 / w, 0, 0, 0,					//column 1
								0, -a/w, 0, 0,					//column 2
								0, 0, 1/(n-f), 0,				//column 3
								0, 0, n/(n-f), 1);				//column 4
	
	/* ALTERNATIVE WAY TO WRITE PORT
	* //Port = glm::ortho(l, r, b, t, n, f);
	* //where l=-w, r=w, t=w/a, b=-w/a
	glm::mat4 Port = glm::ortho(-w, w, -w / a, w / a, n, f);
	Port = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) * Port;
	*/
	
	
	// Isometric projection
	/* WRITING THE MATRIX */
	S = Port *
		glm::mat4(1, 0, 0, 0,
					0, cos(glm::radians(35.26f)), sin(glm::radians(35.26f)), 0,
					0, -sin(glm::radians(35.26f)), cos(glm::radians(35.26f)), 0,
					0, 0, 0, 1)	*					
		glm::mat4(cos(glm::radians(-45.0f)), 0, -sin(glm::radians(-45.0f)), 0,
					0, 1, 0, 0,
					sin(glm::radians(-45.0f)), 0, cos(glm::radians(-45.0f)), 0,
					0, 0, 0, 1);	
	
	/* USING GLM::ROTATE
	S = glm::mat4(1);
	S = Port *
		glm::rotate(S, glm::radians(35.26f), glm::vec3(1,0,0) ) *
		glm::rotate(S, glm::radians(-45.0f), glm::vec3(0, 1, 0));
	*/
	A->Matrix(1, S); // sets the matrix corresponding to piece 1



	// Dimetric
	float alpha = 23.0f;
	S = Port *
		glm::mat4(1, 0, 0, 0,
					0, cos(glm::radians(alpha)), sin(glm::radians(alpha)), 0,
					0, -sin(glm::radians(alpha)), cos(glm::radians(alpha)), 0,
					0, 0, 0, 1) *
		glm::mat4(cos(glm::radians(45.0f)), 0, sin(glm::radians(45.0f)), 0,
					0, 1, 0, 0,
					-sin(glm::radians(45.0f)), 0, cos(glm::radians(45.0f)), 0,
					0, 0, 0, 1);
	/* USING GLM::ROTATE
	S = glm::mat4(1);
	S = Port *
		glm::rotate(S, glm::radians(alpha), glm::vec3(1,0,0) ) *
		glm::rotate(S, glm::radians(-45.0f), glm::vec3(0, 1, 0));
	*/

	A->Matrix(2, S); // sets the matrix corresponding to piece 2



	// Trimetric
	//S = glm::mat4(1);
	float beta = 70.0f;
	S = Port *
		glm::mat4(1, 0, 0, 0,
				0, cos(glm::radians(alpha)), sin(glm::radians(alpha)), 0,
				0, -sin(glm::radians(alpha)), cos(glm::radians(alpha)), 0,
				0, 0, 0, 1) *
		glm::mat4(cos(glm::radians(beta)), 0, sin(glm::radians(beta)), 0,
				0, 1, 0, 0,
				-sin(glm::radians(beta)), 0, cos(glm::radians(beta)), 0,
				0, 0, 0, 1);
	/* USING GLM::ROTATE
	S = glm::mat4(1);
	S = Port *
		glm::rotate(S, glm::radians(alpha), glm::vec3(1,0,0) ) *
		glm::rotate(S, glm::radians(beta), glm::vec3(0, 1, 0));
	*/
	A->Matrix(3, S); // sets the matrix corresponding to piece 3



	// Cabinet
	//S = glm::mat4(1);
	float p = 0.5;

	S = Port *
		glm::mat4(1, 0, 0, 0,
			0, 1, 0, 0,
			-p*cos(glm::radians(45.0f)), -p*sin(glm::radians(45.0f)), 1, 0,
			0, 0, 0, 1);

	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
