
#include <math.h>

# define M_PI           3.14159265358979323846


void triangleVert(std::vector<Vertex>& vDef, std::vector<uint32_t>& vIdx, glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3, glm::vec3 norm) {
	int k = vDef.size();
	
	vDef.push_back({ pos1, norm });
	vDef.push_back({ pos2, norm });
	vDef.push_back({ pos3, norm });

	for (int i = 0; i < 3; i++) {
		vIdx.push_back(k+i);
	}
	
}

//pos1,2,3,4 to be put in arguments as vertixes of the rectangle in clockwise direction
void rectangleVert(std::vector<Vertex>& vDef, std::vector<uint32_t>& vIdx, glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3, glm::vec3 pos4, glm::vec3 norm) {
	triangleVert(vDef, vIdx, pos1, pos2, pos3, norm);
	triangleVert(vDef, vIdx, pos1, pos3, pos4, norm);
}


void Assignment14::createCubeMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
/*	vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.5f, 0.0f, 0.866f}});	// vertex 0 - Position and Normal
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{1.0f, 1.0f, 0.1f}, {-0.5f, 0.0f, 0.866f}});// vertex 3 - Position and Normal

	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
	
	// The primitive built here is a cube centered in the origin, whose edge lenght is 2.
*/	/*
	// Fill array vPos with the positions of the vertices of the mesh
	vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.5f, 0.0f, 0.866f}});	// vertex 0 - Position and Normal
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 2 - Position and Normal
	vDef.push_back({{1.0f, 1.0f, 0.1f}, {-0.5f, 0.0f, 0.866f}});// vertex 3 - Position and Normal
	// Fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
	*/

	//upper base
	glm::vec3 a = { -1.0f, 1.0f, 1.0f };
	glm::vec3 b = { 1.0f, 1.0f, 1.0f };
	glm::vec3 c = { 1.0f, 1.0f, -1.0f };
	glm::vec3 d = { -1.0f, 1.0f, -1.0f };

	//Lower base
	glm::vec3 e = { -1.0f, -1.0f, 1.0f };
	glm::vec3 f = { 1.0f, -1.0f, 1.0f };
	glm::vec3 g = { 1.0f, -1.0f, -1.0f };
	glm::vec3 h = { -1.0f, -1.0f, -1.0f };

	rectangleVert(vDef, vIdx, a, b, c, d, { 0.0f, 1.0f, 0.0f });
	rectangleVert(vDef, vIdx, e, f, g, h, { 0.0f, 1.0f, 0.0f });

	rectangleVert(vDef, vIdx, a, b, f, e, { 0.0f, 0.0f, 1.0f });
	rectangleVert(vDef, vIdx, d, c, g, h, { 0.0f, 0.0f, -1.0f });

	rectangleVert(vDef, vIdx, c, b, f, g, { 1.0f, 0.0f, 0.0f });
	rectangleVert(vDef, vIdx, a, d, h, e, { -1.0f, 0.0f, 0.0f });
	
}

void Assignment14::createFunctionMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is the surface y = sin(x) * cos(z) with -3 <= x <= 3 and -3 <= z <= 3.
	/*
	// Fill array vPos with the positions of the vertices of the mesh
	vDef.push_back({{0.0f, 0.0f, 0.1f}, {0.5f, 0.0f, 0.866f}});	// vertex 0 - Position and Normal
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 2 - Position and Normal

	// Fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	*/

	float max = 3.0f;
	float min = -3.0f;
	float totalRange = max - min;
	float x = 0;
	float y = 0;
	float z = 0;
	glm::vec3 derivative_y = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 derivative_x = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 derivative_z = glm::vec3(0.0f, 0.0f, 0.0f);
	float pointsPerRangeLine = 100.0f;
	glm::vec3 norm = glm::vec3(0.0f, 0.0f, 0.0f);
	int kinitial = vDef.size();
	int k = vDef.size();
	int cnt = 0;

	for (x = min; x <= max; x+= totalRange/pointsPerRangeLine) {
		for (z = min; z <= max; z += totalRange/pointsPerRangeLine) {
			y = sin(x) * cos(z);
			derivative_x = glm::vec3(1.0f, cos(x) * cos(z), 0.0f);	//=(dx/dx, dy/dx, dz/dx)
			derivative_y = glm::vec3(0.0f, 1.0f, 0.0f);				//=(dx/dy, dy/dy, dz/dy)
			derivative_z = glm::vec3(0.0f, sin(x) * -sin(z), 1.0f);	//=(dx/dz, dy/dz, dz/dz)
			//norm = glm::vec3(-(cos(x) * cos(z)), 1.0f, -(sin(x) * -sin(z)));	//cross product of derivatives: take second member of derivatives
			norm = glm::vec3(cos(x) * cos(z), 1.0f, sin(x) * -sin(z));	//cross product of derivatives: take second member of derivatives

			vDef.push_back({ {x,y,z}, norm});

			cnt++;
		}
	}

	for (int i = 0; i < pointsPerRangeLine; i++) {  
		for (int j = 0; j < pointsPerRangeLine; j++) { 
			vIdx.push_back(i * (pointsPerRangeLine + 1) + j); 
			vIdx.push_back(i * (pointsPerRangeLine + 1) + j + 1); 
			vIdx.push_back(i * (pointsPerRangeLine + 1) + j + (pointsPerRangeLine + 1)); 

			vIdx.push_back(i * (pointsPerRangeLine + 1) + j + 1); 
			vIdx.push_back(i * (pointsPerRangeLine + 1) + j + (pointsPerRangeLine + 1)); 
			vIdx.push_back(i * (pointsPerRangeLine + 1) + j + (pointsPerRangeLine + 1) + 1); 
		}
	}
	

}

void Assignment14::createCylinderMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	// The primitive built here is a cylinder, with radius 1, and height 2, centered in the origin.
	/*
	// Fill array vPos with the positions of the vertices of the mesh
	vDef.push_back({{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 0 - Position and Normal
	vDef.push_back({{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}});	// vertex 1 - Position and Normal
	vDef.push_back({{1.0f, 1.0f, 0.1f}, {-0.5f, 0.0f, 0.866f}});// vertex 2 - Position and Normal

	// Fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	*/
	float height = 2;
	float radius = 1;
	glm::vec3 centerLowerBase = glm::vec3(0, -height/2, 0);
	glm::vec3 centerUpperBase = glm::vec3(0, height / 2, 0);

	int numOfSides = 150;	//Increase for smoother surfaces
	float edgeAngle = 0.0f;

	glm::vec3 v1 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 v2 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 v3 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 v4 = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::vec3 sideNorm = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 upperNorm = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 lowerNorm = glm::vec3(0.0f, -1.0f, 0.0f);


	for (int i = 0; i <= numOfSides; i++) {
		edgeAngle = (2*M_PI/numOfSides)*i;
		
		//side vertexes
		v1 = glm::vec3(radius * cos(edgeAngle), height / 2, radius * sin(edgeAngle));
		v2 = glm::vec3(radius * cos(edgeAngle), -height / 2, radius * sin(edgeAngle));
		v3 = glm::vec3(radius * cos(edgeAngle+(2*M_PI/numOfSides)), -height / 2, radius * sin(edgeAngle+(2*M_PI/numOfSides)));
		v4 = glm::vec3(radius * cos(edgeAngle+(2*M_PI/numOfSides)), height / 2, radius * sin(edgeAngle+(2*M_PI/numOfSides)));

		//side
		sideNorm = glm::vec3(cos(edgeAngle + (2 * M_PI / numOfSides) / 2), 0.0f, sin(edgeAngle + (2 * M_PI / numOfSides) / 2));
		rectangleVert(vDef, vIdx, v1, v2, v3, v4, sideNorm); 

		//top
		triangleVert(vDef, vIdx, v4, v1, centerUpperBase, upperNorm);

		//bottom
		triangleVert(vDef, vIdx, v2, v3, centerLowerBase, lowerNorm);
	}

}
