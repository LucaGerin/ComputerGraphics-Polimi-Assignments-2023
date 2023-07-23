
void Assignment15::createBoxMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The primitive built here is a box centered in the origin, with proportions respecting the texture.
	/*
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	vDef.push_back({{0,0,0}, {0,0,1}, {0,0}});	// vertex 0 - Position, Normal and uv
	vDef.push_back({{1,0,0}, {0,0,1}, {1,0}});	// vertex 1 - Position and Normal
	vDef.push_back({{0,1,0}, {0,0,1}, {0,1}});	// vertex 2 - Position and Normal
	vDef.push_back({{1,1,0}, {0,0,1}, {1,1}});// vertex 3 - Position and Normal

	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
	*/

	float texWidth = 1024.0f;
	float texHeight = 512.0f;

	float boxDepth = (1.0f/200.0f)*texHeight / 5;
	float boxWidth = (1.0f / 200.0f) * texHeight * 3 / 5;
	float boxHeihgt = boxWidth;

	glm::vec3 v1 = glm::vec3(boxDepth / 2, boxHeihgt / 2, boxWidth / 2);
	glm::vec3 v2 = glm::vec3(boxDepth / 2, boxHeihgt / 2, -boxWidth / 2);
	glm::vec3 v3 = glm::vec3(boxDepth / 2, -boxHeihgt / 2, -boxWidth / 2);
	glm::vec3 v4 = glm::vec3(boxDepth / 2, -boxHeihgt / 2, boxWidth / 2);

	glm::vec3 v5 = glm::vec3(-boxDepth / 2, boxHeihgt / 2, boxWidth / 2);
	glm::vec3 v6 = glm::vec3(-boxDepth / 2, boxHeihgt / 2, -boxWidth / 2);
	glm::vec3 v7 = glm::vec3(-boxDepth / 2, -boxHeihgt / 2, -boxWidth / 2);
	glm::vec3 v8 = glm::vec3(-boxDepth / 2, -boxHeihgt / 2, boxWidth / 2);

	//Front face
	int k = vDef.size();
	vDef.push_back({ v1, {1.0f, 0.0f, 0.0f}, {94.0f / texWidth, 92.0f / texHeight}  });
	vDef.push_back({ v2, {1.0f, 0.0f, 0.0f}, {445.0f / texWidth, 92.0f / texHeight} });
	vDef.push_back({ v3, {1.0f, 0.0f, 0.0f}, {445.0f / texWidth, 420.0f / texHeight} });
	vDef.push_back({ v4, {1.0f, 0.0f, 0.0f}, {94.0f / texWidth, 420.0f / texHeight} });
	vIdx.push_back(k);	vIdx.push_back(k+1);	vIdx.push_back(k+2);
	vIdx.push_back(k);	vIdx.push_back(k + 2);	vIdx.push_back(k + 3);

	//Back face
	k = vDef.size();
	vDef.push_back({ v5, {-1.0f, 0.0f, 0.0f}, {890.0f / texWidth, 92.0f / texHeight} });
	vDef.push_back({ v6, {-1.0f, 0.0f, 0.0f}, {537.0f / texWidth, 92.0f / texHeight} });
	vDef.push_back({ v7, {-1.0f, 0.0f, 0.0f}, {537.0f / texWidth, 420.0f / texHeight} });
	vDef.push_back({ v8, {-1.0f, 0.0f, 0.0f}, {890.0f / texWidth, 420.0f / texHeight} });
	vIdx.push_back(k);	vIdx.push_back(k + 1);	vIdx.push_back(k + 2);
	vIdx.push_back(k);	vIdx.push_back(k + 2);	vIdx.push_back(k + 3);

	//Left face
	k = vDef.size();
	vDef.push_back({ v5, {0.0f, 0.0f, -1.0f}, {0.0f / texWidth, 92.0f / texHeight} });
	vDef.push_back({ v1, {0.0f, 0.0f, -1.0f}, {94.0f / texWidth, 92.0f / texHeight} });
	vDef.push_back({ v4, {0.0f, 0.0f, -1.0f}, {94.0f / texWidth, 420.0f / texHeight} });
	vDef.push_back({ v8, {0.0f, 0.0f, -1.0f}, {0.0f / texWidth, 420.0f / texHeight} });
	vIdx.push_back(k);	vIdx.push_back(k + 1);	vIdx.push_back(k + 2);
	vIdx.push_back(k);	vIdx.push_back(k + 2);	vIdx.push_back(k + 3);

	//Right face
	k = vDef.size();
	vDef.push_back({ v2, {0.0f, 0.0f, 1.0f}, {445.0f / texWidth, 92.0f / texHeight} });
	vDef.push_back({ v6, {0.0f, 0.0f, 1.0f}, {537.0f / texWidth, 92.0f / texHeight} });
	vDef.push_back({ v7, {0.0f, 0.0f, 1.0f}, {537.0f / texWidth, 420.0f / texHeight} });
	vDef.push_back({ v3, {0.0f, 0.0f, 1.0f}, {445.0f / texWidth, 420.0f / texHeight} });
	vIdx.push_back(k);	vIdx.push_back(k + 1);	vIdx.push_back(k + 2);
	vIdx.push_back(k);	vIdx.push_back(k + 2);	vIdx.push_back(k + 3);

	//Top face
	k = vDef.size();
	vDef.push_back({ v5, {0.0f, 1.0f, 0.0f}, {94.0f / texWidth, 0.0f / texHeight} });
	vDef.push_back({ v6, {0.0f, 1.0f, 0.0f}, {445.0f / texWidth, 0.0f / texHeight} });
	vDef.push_back({ v2, {0.0f, 1.0f, 0.0f}, {445.0f / texWidth, 92.0f / texHeight} });
	vDef.push_back({ v1, {0.0f, 1.0f, 0.0f}, {94.0f / texWidth, 92.0f / texHeight} });
	vIdx.push_back(k);	vIdx.push_back(k + 1);	vIdx.push_back(k + 2);
	vIdx.push_back(k);	vIdx.push_back(k + 2);	vIdx.push_back(k + 3);

	//Bottom face
	k = vDef.size();
	vDef.push_back({ v4, {0.0f, -1.0f, 0.0f}, {94.0f / texWidth, 420.0f / texHeight} });
	vDef.push_back({ v3, {0.0f, -1.0f, 0.0f}, {445.0f / texWidth, 420.0f / texHeight} });
	vDef.push_back({ v7, {0.0f, -1.0f, 0.0f}, {445.0f / texWidth, 512.0f / texHeight} });
	vDef.push_back({ v8, {0.0f, -1.0f, 0.0f}, {94.0f / texWidth, 512.0f / texHeight} });
	vIdx.push_back(k);	vIdx.push_back(k + 1);	vIdx.push_back(k + 2);
	vIdx.push_back(k);	vIdx.push_back(k + 2);	vIdx.push_back(k + 3);
}

#define M_PI 3.141595f
void Assignment15::createSphereMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
	// The primitive built here is a sphere of radius 1, centered in the origin, on which the Mars texture is applied seamless.
	
	/*
	// The procedure fills array vPos with the positions of the vertices and of the normal vectors of the mesh
	vDef.push_back({{0,0,0}, {0,0,1}, {0,0}});	// vertex 0 - Position, Normal and uv
	vDef.push_back({{1,0,0}, {0,0,1}, {1,0}});	// vertex 1 - Position and Normal
	vDef.push_back({{0,1,0}, {0,0,1}, {0,1}});	// vertex 2 - Position and Normal
	vDef.push_back({{1,1,0}, {0,0,1}, {1,1}});// vertex 3 - Position and Normal

	// The procedures also fill the array vIdx with the indices of the vertices of the triangles
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle
	*/

    float radius = 1.0;
    float horizontalSlices = 200.0;
    float verticalSlices = 200.0;
    float hangle = 2*M_PI / horizontalSlices;
    float vangle = M_PI / verticalSlices;

	glm::vec3 v1 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 norm = glm::vec3(0.0f, 0.0f, 0.0f);
	float u = 0.0f;
	float v = 0.0f;

	for (int i = 0; i <= verticalSlices; i++) {
		vangle = (M_PI / verticalSlices) * i;
		
		for (int j = 0; j <= horizontalSlices; j++) {
			hangle = (2 * M_PI / horizontalSlices) * j;

			v1 = glm::vec3(radius * sin(vangle)*cos(hangle), radius * cos(vangle), radius*sin(hangle)*sin(vangle)); 
			norm = glm::vec3(sin(vangle) * cos(hangle) / radius, cos(vangle) / radius, sin(hangle) * sin(vangle) / radius);
			u = j / horizontalSlices;
			v = i / verticalSlices;

			vDef.push_back({ v1, norm, {u,v} });

		}
	}

	for (int i = 0; i < verticalSlices; i++) {
		for (int j = 0; j < horizontalSlices; j++) {
			vIdx.push_back(i*(verticalSlices+1)+j);
			vIdx.push_back(i * (verticalSlices + 1) + j +1);
			vIdx.push_back(i * (verticalSlices + 1) + j + (verticalSlices + 1));

			vIdx.push_back(i * (verticalSlices + 1) + j +1);
			vIdx.push_back(i * (verticalSlices + 1) + j + (verticalSlices + 1));
			vIdx.push_back(i * (verticalSlices + 1) + j + (verticalSlices + 1) +1);
		}
	}
	

   
}

