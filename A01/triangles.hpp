

void SetupTriangles(Assignment01 *A) {
/**************
 Function Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 Using function Triangle(...) try to draw a children house, similar to the one below.
 
 First remove the two function below (given only as an example), and replace them with your own.
 Since it is a C program, you can use for loops if you think it can be helpful in your drawing.
 The for() command below that draws a sun like shape in exact center of the screen near the top,
 is an example on how you can use it: please remove it, and replace it with your own code.
 It is not necessery to use a for loop if you do not really need it: it has been put here only as
 an example to help students not familiar with C++.
***************/

	/*
	A->Triangle(-1,-1, 0,0, -1,1,   1,0,0);	// Draws a red triangle pointing right
	A->Triangle(1,-1, 0,0, 1,1,   0,1,0);	// Draws a green triangle pointing left
	A->Triangle(1,-1,   0,-0.25,   1, 1,   0,1,2);	//TEST of Triangle function
	*/

	

	A->Triangle( 0.12, -0.4,   0.12, 0.31,   0.38, -0.04,   0.161, 0.103, 0.037); //original orange
	A->Triangle( 0.12, 0.62,   0.12, -0.4,   -0.25, 0.1,    0.097, 0.061, 0.019); //original red
	A->Triangle( -0.25, 0.85,  0.29, 0.85,   -0.25, 0.1,    0.161, 0.103, 0.037); //original blue
	A->Triangle( -0.25, 0.85,  -0.64, 0.85,  -0.8, 0.60,    0.117, 0.113, 0.108); //original green pt1
	A->Triangle( -0.25, 0.85,  -0.42, 0.60,  -0.8, 0.60,    0.117, 0.113, 0.108); //original green pt2
	A->Triangle( 0.12, -0.4,   0.3, -0.15,   0.49, -0.4,    0.191, 0.156, 0.115); //original purple pt 1
	A->Triangle( 0.12, -0.4,   0.3, -0.65,   0.49, -0.4,    0.191, 0.156, 0.115); //original purple pt 2
	A->Triangle( 0.49, -0.9,   0.3, -0.65,   0.49, -0.4,    0.097, 0.061, 0.019); //right ear
	A->Triangle( 0.12, -0.4,   0.3, -0.65,   0.12, -0.9,    0.161, 0.103, 0.037); //left ear


	//NOT NECESSARY
	//Face details
	A->Triangle( 0.28, -0.4,   0.3, -0.37,   0.32, -0.4,   0, 0, 0); //nose
	A->Triangle( 0.28, -0.3,   0.3, -0.37,   0.32, -0.3,   0.232, 0.160, 0.226); //month

	A->Triangle( 0.33, -0.38,  0.41, -0.39,  0.41, -0.4,   0.117, 0.117, 0.117); //whiskers
	A->Triangle( 0.27, -0.38,  0.2, -0.39,   0.2, -0.4,    0.117, 0.117, 0.117);
	A->Triangle( 0.33, -0.38,  0.41, -0.37,  0.41, -0.36,  0.117, 0.117, 0.117);
	A->Triangle( 0.27, -0.38,  0.2, -0.37,   0.2, -0.36,   0.117, 0.117, 0.117);

	A->Triangle( 0.23, -0.43,  0.2, -0.43,   0.2, -0.45,   0.196, 0.196, 0.196); //left eye
	A->Triangle( 0.23, -0.43,  0.23, -0.45,  0.2, -0.45,   0.196, 0.196, 0.196);
	A->Triangle( 0.38, -0.43,  0.41, -0.43,  0.41, -0.45,  0.196, 0.196, 0.196); //right eye
	A->Triangle( 0.38, -0.43,  0.38, -0.45,  0.41, -0.45,  0.196, 0.196, 0.196);

	//UTIL
	//indicate the center
	//A->Triangle(-0.01, -0.01, 0.01, -0.01, 0, 0.01, 0, 0, 0);

}
