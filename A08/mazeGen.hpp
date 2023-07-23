
struct cube {
	int pos[2];
	bool isWall;
	bool isDrawn;
	int Vup1;
	int Vup2;
	int Vup3;
	int Vup4;
	int Vdown1;
	int Vdown2;
	int Vdown3;
	int Vdown4;
}; 


void Assignment08::createMazeMesh(int row, int col, char **maze) {
	// The procedure gets in input the number of rows <row> of the maze, and the number of columns <col>
	// Element <maze[r][c]>, with 0 <= r <= row-1 and 0 <= c <= col-1 contains:
	//		Symbol ' ' if there is an empty space
	//		Symbol '#' if there is a wall
	//
	// Example: The following piece of code executes the instruction in the ... section
	//          if there is a wall in position r=5, c=7
	//
	// int r, c;
	// r = 5; c = 7;
	// if(maze[r][c] == '#') {
	//		...
	// }
	
	// Vertexes for the floor
	vPos.push_back(0.0); vPos.push_back(0.0); vPos.push_back(0.0);	// vertex 0
	vPos.push_back(col*1.0); vPos.push_back(0.0); vPos.push_back(0.0);	// vertex 1
	vPos.push_back(0.0); vPos.push_back(0.0); vPos.push_back(-row*1.0);	// vertex 2
	vPos.push_back(col*1.0); vPos.push_back(0.0); vPos.push_back(-row*1.0);	// vertex 3
	// Draw floor
	vIdx.push_back(0); vIdx.push_back(1); vIdx.push_back(2);	// First triangle
	vIdx.push_back(1); vIdx.push_back(2); vIdx.push_back(3);	// Second triangle

	const int r = row;
	const int c = col;
	int numWalls = 0;

	cube* myMaze;
	myMaze = new cube[r*c];

	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			myMaze[i*col + j].pos[0] = i;
			myMaze[i * col + j].pos[1] = j;
			if (maze[i][j] == '#') {
				myMaze[i * col + j].isWall = true;
				numWalls++;
			}
			else {
				myMaze[i * col + j].isWall = false;
			}
			myMaze[i * col + j].isDrawn = false;
			myMaze[i * col + j].Vup1=NULL;
			myMaze[i * col + j].Vup2 = NULL;
			myMaze[i * col + j].Vup3 = NULL;
			myMaze[i * col + j].Vup4 = NULL;
			myMaze[i * col + j].Vdown1 = NULL;
			myMaze[i * col + j].Vdown2 = NULL;
			myMaze[i * col + j].Vdown3 = NULL;
			myMaze[i * col + j].Vdown4 = NULL;
		}
	}

	int k = 0;
	int newVup1;
	int newVup2;
	int newVup3;
	int newVup4;
	int newVdown1;
	int newVdown2;
	int newVdown3;
	int newVdown4;
	
	int current_index = 3;

		//HORIZONTAL
		//std::cout << "\n\n\n ----HORIZONTAL----";
		for (i = 0; i < row*col; i ++) {
			//std::cout << "\n -------";
				//std::cout << "\n i= " << i;	
				if (myMaze[i].isWall && i < row * col) {
					//try to go right
					//Count how much to go right

					k = 0;
					int currRow = myMaze[i + k].pos[0];
					//std::cout << "\n cuurRow= " << currRow;
					//std::cout << "\n i+k: isWall, isDrawn, pos0, i+k = " << myMaze[i + k].isWall << (myMaze[i + k].isDrawn) << myMaze[i + k].pos[0] << (i + k);
					while (myMaze[i + k].isWall && myMaze[i + k].isDrawn==false && (myMaze[i + k].pos[0] == currRow) && (i + k < row * col)) {
						k++;
					}
					//std::cout << "\n k=" << k;
					if(k > 1) { //there is at least one wall at the right
						
						//std::cout << "\n drawing..." << k;
						//Vup1
						vPos.push_back(i%col * 1.0f); vPos.push_back(1.0); vPos.push_back((-row + myMaze[i].pos[0]) * 1.0);
						current_index++;
						newVup1 = current_index;
						//myMaze[i].Vup1 = current_index;
						//if (i -1 > 0) myMaze[i - 1].Vup2 = current_index;
						//if(i-col>0) myMaze[i - col].Vup4 = current_index;
						//if (i - col -1 > 0) myMaze[i - col - 1].Vup3 = current_index;
						
						//Vdown1
						vPos.push_back(i%col * 1.0f); vPos.push_back(0.0); vPos.push_back((-row + myMaze[i].pos[0]) * 1.0);
						current_index++;
						newVdown1 = current_index;
						//myMaze[i].Vdown1 = current_index;
						//if (i - 1 > 0) myMaze[i - 1].Vdown2 = current_index;
						//if (i - col > 0) myMaze[i - col].Vdown4 = current_index;
						//if (i - col - 1 > 0) myMaze[i - col - 1].Vdown3 = current_index;

						//Vup4
						vPos.push_back(i % col * 1.0f); vPos.push_back(1.0); vPos.push_back((-row + myMaze[i].pos[0] + 1) * 1.0);
						current_index++;
						newVup4 = current_index;
						//myMaze[i].Vup4 = current_index;
						//if (i - 1 > 0) myMaze[i - 1].Vup3 = current_index;
						//if (i + col < row*col) myMaze[i + col].Vup1 = current_index;
						//if (i + col - 1 < row * col) myMaze[i + col - 1].Vup2 = current_index;
						
						//Vdown4
						vPos.push_back(i % col * 1.0f); vPos.push_back(0.0); vPos.push_back((-row + myMaze[i].pos[0] + 1) * 1.0);
						current_index++;
						newVdown4 = current_index;
						//myMaze[i].Vdown4 = current_index;
						//if (i - 1 > 0) myMaze[i - 1].Vdown3 = current_index;
						//if (i + col < row * col) myMaze[i + col].Vdown1 = current_index;
						//if (i + col - 1 < row * col) myMaze[i + col - 1].Vdown2 = current_index;
						

						//Vup2
						vPos.push_back((i % col + k) * 1.0f); vPos.push_back(1.0); vPos.push_back((-row + myMaze[i].pos[0]) * 1.0);
						current_index++;
						newVup2 = current_index;
						//myMaze[i + k].Vup2 = current_index;
						//if (i + 1 < row * col) myMaze[i + 1].Vup1 = current_index;
						//if (i - col > 0) myMaze[i - col > 0].Vup3 = current_index;
						//if (i - col + 1 > 0) myMaze[i - col + 1].Vup4 = current_index;

						//Vdown2
						vPos.push_back((i% col + k) * 1.0f); vPos.push_back(0.0); vPos.push_back((-row + myMaze[i].pos[0]) * 1.0);
						current_index++;
						newVdown2 = current_index;
						//myMaze[i + k].Vdown2 = current_index;
						//if (i + 1 < row * col) myMaze[i + 1].Vdown1 = current_index;
						//if (i - col > 0) myMaze[i - col].Vdown3 = current_index;
						//if (i - col + 1 > 0) myMaze[i - col + 1].Vdown4 = current_index;

						//Vup3
						vPos.push_back((i% col + k) * 1.0f); vPos.push_back(1.0); vPos.push_back((-row + myMaze[i].pos[0] + 1) * 1.0);
						current_index++;
						newVup3 = current_index;
						//myMaze[i + k].Vup3 = current_index;
						//if (i + 1 < row * col) myMaze[i + 1].Vup4 = current_index;
						//if (i + col < row * col) myMaze[i + col].Vup2 = current_index;
						//if (i + col + 1 < row * col) myMaze[i + col + 1].Vup1 = current_index;

						//Vdown3
						vPos.push_back((i% col + k) * 1.0f); vPos.push_back(0.0); vPos.push_back((-row + myMaze[i].pos[0] + 1) * 1.0);
						current_index++;
						newVdown3 = current_index;
						//myMaze[i + k].Vdown3 = current_index;
						//if (i + 1 < row * col) myMaze[i + 1].Vdown4 = current_index;
						//if (i + col < row * col) myMaze[i + col].Vdown2 = current_index;
						//if (i + col + 1 < row * col) myMaze[i + col + 1].Vdown1 = current_index;

						//draw the prisma
						vIdx.push_back(newVup1); vIdx.push_back(newVdown2); vIdx.push_back(newVup2);
						vIdx.push_back(newVup1); vIdx.push_back(newVdown1); vIdx.push_back(newVdown2);

						vIdx.push_back(newVup1); vIdx.push_back(newVup4); vIdx.push_back(newVdown1);
						vIdx.push_back(newVdown1); vIdx.push_back(newVdown4); vIdx.push_back(newVup4);

						vIdx.push_back(newVup4); vIdx.push_back(newVdown3); vIdx.push_back(newVup3);
						vIdx.push_back(newVup4); vIdx.push_back(newVdown4); vIdx.push_back(newVdown3);

						vIdx.push_back(newVup3); vIdx.push_back(newVdown2); vIdx.push_back(newVup2);
						vIdx.push_back(newVup3); vIdx.push_back(newVdown3); vIdx.push_back(newVdown2);

						vIdx.push_back(newVup1); vIdx.push_back(newVup2); vIdx.push_back(newVup3);
						vIdx.push_back(newVup1); vIdx.push_back(newVup4); vIdx.push_back(newVup3);

						for (int h = i; h < i + k; h++) {
							myMaze[h].isDrawn = true;
							//std::cout << "\nAt " << h << " isWall TRUE";
						}
					}

						
				}
		}

		//VERTICAL
		//std::cout << "\n\n\n ----VERTICAL----";
		for (i = 0; i < row * col; i++) {
			//std::cout << "\n -------";
			//std::cout << "\n i= " << i;
			if (myMaze[i].isWall && i < row * col) {
				//try to go right
				//Count how much to go right

				k = 0;
				int currCol = myMaze[i].pos[1];
				//std::cout << "\n cuurCol= " << currCol;
				//std::cout << "\n i+k: isWall, isDrawn, pos1, i+k = " << myMaze[i + k].isWall <<", "<< (myMaze[i + k].isDrawn) << ", " << myMaze[i + k].pos[1] << ", " << (i + k);
				while (myMaze[i + col*k].isWall && myMaze[i + col*k].isDrawn == false && (myMaze[i + col*k].pos[1] == currCol) && (i + col * k < row * col)) {
					k++;
				}
				//std::cout << "\n k=" << k;
				if (k > 0) { //there is at least one wall at the right

					//std::cout << "\n drawing..." << k <<"from i= "<<i<< " in "<< myMaze[i].pos[0]<<", "<< myMaze[i].pos[1];
					//Vup1
					vPos.push_back(i % col * 1.0f); vPos.push_back(1.0); vPos.push_back((-row + myMaze[i].pos[0]) * 1.0);
					current_index++;
					newVup1 = current_index;
					//myMaze[i].Vup1 = current_index;
					//if (i -1 > 0) myMaze[i - 1].Vup2 = current_index;
					//if(i-col>0) myMaze[i - col].Vup4 = current_index;
					//if (i - col -1 > 0) myMaze[i - col - 1].Vup3 = current_index;

					//Vdown1
					vPos.push_back(i % col * 1.0f); vPos.push_back(0.0); vPos.push_back((-row + myMaze[i].pos[0]) * 1.0);
					current_index++;
					newVdown1 = current_index;
					//myMaze[i].Vdown1 = current_index;
					//if (i - 1 > 0) myMaze[i - 1].Vdown2 = current_index;
					//if (i - col > 0) myMaze[i - col].Vdown4 = current_index;
					//if (i - col - 1 > 0) myMaze[i - col - 1].Vdown3 = current_index;

					//Vup4
					vPos.push_back(i % col * 1.0f); vPos.push_back(1.0); vPos.push_back((-row + myMaze[i].pos[0] + k) * 1.0);
					current_index++;
					newVup4 = current_index;
					//myMaze[i].Vup4 = current_index;
					//if (i - 1 > 0) myMaze[i - 1].Vup3 = current_index;
					//if (i + col < row*col) myMaze[i + col].Vup1 = current_index;
					//if (i + col - 1 < row * col) myMaze[i + col - 1].Vup2 = current_index;

					//Vdown4
					vPos.push_back(i % col * 1.0f); vPos.push_back(0.0); vPos.push_back((-row + myMaze[i].pos[0] + k) * 1.0);
					current_index++;
					newVdown4 = current_index;
					//myMaze[i].Vdown4 = current_index;
					//if (i - 1 > 0) myMaze[i - 1].Vdown3 = current_index;
					//if (i + col < row * col) myMaze[i + col].Vdown1 = current_index;
					//if (i + col - 1 < row * col) myMaze[i + col - 1].Vdown2 = current_index;


					//Vup2
					vPos.push_back((i % col + 1) * 1.0f); vPos.push_back(1.0); vPos.push_back((-row + myMaze[i].pos[0]) * 1.0);
					current_index++;
					newVup2 = current_index;
					//myMaze[i + k].Vup2 = current_index;
					//if (i + 1 < row * col) myMaze[i + 1].Vup1 = current_index;
					//if (i - col > 0) myMaze[i - col > 0].Vup3 = current_index;
					//if (i - col + 1 > 0) myMaze[i - col + 1].Vup4 = current_index;

					//Vdown2
					vPos.push_back((i % col + 1) * 1.0f); vPos.push_back(0.0); vPos.push_back((-row + myMaze[i].pos[0]) * 1.0);
					current_index++;
					newVdown2 = current_index;
					//myMaze[i + k].Vdown2 = current_index;
					//if (i + 1 < row * col) myMaze[i + 1].Vdown1 = current_index;
					//if (i - col > 0) myMaze[i - col].Vdown3 = current_index;
					//if (i - col + 1 > 0) myMaze[i - col + 1].Vdown4 = current_index;

					//Vup3
					vPos.push_back((i % col + 1) * 1.0f); vPos.push_back(1.0); vPos.push_back((-row + myMaze[i].pos[0] + k) * 1.0);
					current_index++;
					newVup3 = current_index;
					//myMaze[i + k].Vup3 = current_index;
					//if (i + 1 < row * col) myMaze[i + 1].Vup4 = current_index;
					//if (i + col < row * col) myMaze[i + col].Vup2 = current_index;
					//if (i + col + 1 < row * col) myMaze[i + col + 1].Vup1 = current_index;

					//Vdown3
					vPos.push_back((i % col + 1) * 1.0f); vPos.push_back(0.0); vPos.push_back((-row + myMaze[i].pos[0] + k) * 1.0);
					current_index++;
					newVdown3 = current_index;
					//myMaze[i + k].Vdown3 = current_index;
					//if (i + 1 < row * col) myMaze[i + 1].Vdown4 = current_index;
					//if (i + col < row * col) myMaze[i + col].Vdown2 = current_index;
					//if (i + col + 1 < row * col) myMaze[i + col + 1].Vdown1 = current_index;

					//draw the prisma
					vIdx.push_back(newVup1); vIdx.push_back(newVdown2); vIdx.push_back(newVup2);
					vIdx.push_back(newVup1); vIdx.push_back(newVdown1); vIdx.push_back(newVdown2);

					vIdx.push_back(newVup1); vIdx.push_back(newVup4); vIdx.push_back(newVdown1);
					vIdx.push_back(newVdown1); vIdx.push_back(newVdown4); vIdx.push_back(newVup4);

					vIdx.push_back(newVup4); vIdx.push_back(newVdown3); vIdx.push_back(newVup3);
					vIdx.push_back(newVup4); vIdx.push_back(newVdown4); vIdx.push_back(newVdown3);

					vIdx.push_back(newVup3); vIdx.push_back(newVdown2); vIdx.push_back(newVup2);
					vIdx.push_back(newVup3); vIdx.push_back(newVdown3); vIdx.push_back(newVdown2);

					vIdx.push_back(newVup1); vIdx.push_back(newVup2); vIdx.push_back(newVup3);
					vIdx.push_back(newVup1); vIdx.push_back(newVup4); vIdx.push_back(newVup3);

					for (int h = 0; h < k; h++) {
						myMaze[i+col*h].isDrawn = true;
					}
				}


			}
		}
	
	
}
