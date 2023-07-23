
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


void SetupProjectionMatrices(Assignment05 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

	/*
	The perspective uses the aspect ratio passed in parameter Ar, 
	and has the near and far planes located respectively at a distance of 0.1 and 50.0
	*/

	float a = Ar;
	float n = 0.1;
	float f = 50.0;

	glm::mat4 S;
	
	
	// Fov-y = 60 deg
	S = glm::mat4(1);
	S = glm::perspective((float)glm::radians(60.0f), a, n, f);
	S[1][1] *= -1;
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Fov-y = 105 deg
	S = glm::mat4(1); 
	S = glm::perspective((float)glm::radians(105.0f), a, n, f);
	S[1][1] *= -1;
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Fov-y = 25 deg
	S = glm::mat4(1);
	S = glm::perspective((float)glm::radians(25.0f), a, n, f);
	S[1][1] *= -1;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Right View, Fov-x = 45 deg
	S = glm::mat4(1);
	float fov_x = glm::radians(45.0f);
	//float swapped_a = 1.0 / a;	//swapped to obtain right view
	//float cot_half_fov_x = 1.0 / tan(fov_x * 0.5);
	//float distance = f - n;

	/*
	//a = n*tan(fov_x/2)/n*tan(fov_y/2) from which I derive:
	float fov_y = 2.0f * atan(tan(fov_x/2)/a);
	S = glm::perspective(fov_y, a, n, f);
	S[1][1] *= -1;
	// TOO MUCH ZOOM WITH THIS SOLUTION
	// CAN I SET RIGHT VIEW USING perspective()?
	*/

	float l = 0;							//to obtain right view
	float r = 2 * n * tan(fov_x / 2);		//multiplied *2 to obtain right view
	float b = -(1/a) * n * tan(fov_x / 2);
	float t = (1/a) * n * tan(fov_x / 2);


	S = glm::frustum(l, r, b, t, n, f);
	S = glm::scale(glm::mat4(1.0), glm::vec3(1, -1, 1)) * S;

	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
