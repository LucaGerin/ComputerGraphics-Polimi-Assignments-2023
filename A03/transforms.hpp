
#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void SetupMatrices(Assignment03 *A) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

	glm::mat4 S;
	
	
	// To solve the puzzle: scale 2x proportionally, centered in (2,0,-3)
	//S = glm::mat4(1);
	S = glm::translate(glm::mat4(1), glm::vec3(2, 0, -3)) *		//3) bring back to original position
		glm::scale(glm::mat4(1), glm::vec3(2)) *				//2) scale
		glm::translate(glm::mat4(1), glm::vec3(-2, 0, 3));		//1) bring to origin
	A->Matrix(1, S); // sets the matrix corresponding to piece 1



	// To solve the puzzle: scale 2x (CORREGGERE A 3x??) on an axis oriented 45 degrees between the x and z axis and passing through point (1,0,0)
	//S = glm::mat4(1);
	
	S = glm::translate(glm::mat4(1), glm::vec3(1, 0, 0)) *						//5) bring axis back to original position
		glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0)) *	//4) rotation around y to restore axis angle
		glm::scale(glm::mat4(1), glm::vec3(3, 1, 1)) *							//3) scale 3x
		glm::rotate(glm::mat4(1), glm::radians(-45.0f), glm::vec3(0, 1, 0)) *	//2) inverse rotation around y to aling axis to x
		glm::translate(glm::mat4(1), glm::vec3(-1, 0, 0));						//1) bring axis to origin (now axis passes through O)
	A->Matrix(2, S); // sets the matrix corresponding to piece 2



	// To solve the puzzle: find it yourself! Hint: compose a rotation around an arbitrary point with a translation
	S = glm::mat4(1);
	S = glm::translate(glm::mat4(1), glm::vec3(0, 0, 3)) *						//3) translate to needed position
		glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0)) *	//2) rotate
		glm::translate(glm::mat4(1), glm::vec3(-0.6, 0, -3));					//1) bring to O
	A->Matrix(3, S); // sets the matrix corresponding to piece 3



	// To solve the puzzle: rotate 60 degree around the y axis, centered in (-1,0,-2)
	//S = glm::mat4(1);
	S = glm::translate(glm::mat4(1), glm::vec3(-1, 0, -2)) * 
		glm::rotate(glm::mat4(1), glm::radians(60.0f), glm::vec3(0, 1, 0)) *
		glm::translate(glm::mat4(1), glm::vec3(1, 0, 2));
	A->Matrix(4, S); // sets the matrix corresponding to piece 4



	// To solve the puzzle: rotate -90 degree around an arbitrary axis passing in (-1,0,0). The x axis can be aligned to this arbitrary direction with a rotation of -45 around the y axis.	
	//S = glm::mat4(1);
	S = glm::translate(glm::mat4(1), glm::vec3(0, 0, 1)) *
		glm::rotate(glm::mat4(1), glm::radians(-45.0f), glm::vec3(0, 1, 0)) *
		glm::rotate(glm::mat4(1), glm::radians(90.0f), glm::vec3(-1, 0, 0)) *
		glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0)) *
		glm::translate(glm::mat4(1), glm::vec3(0, 0, -1));
	A->Matrix(5, S); // sets the matrix corresponding to piece 5



	// To solve the puzzle: find it yourself! Hint: compose a non-proportional scaling that halves the object along one of the main axes, centered in an arbitrary point, with a translation
	//S = glm::mat4(1);
	S = glm::translate(glm::mat4(1), glm::vec3(0.5, 0, 0)) *
		glm::scale(glm::mat4(1), glm::vec3(0.5, 1, 1));
	A->Matrix(6, S); // sets the matrix corresponding to piece 6

}
