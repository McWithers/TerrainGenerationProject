#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "EasyBMP.h"
#include "Main.h"
#define _CRT_SECURE_NO_WARNINGS

int Generate(int size, int depth, int color1R, int color1G, int color1B, int color2R, int color2G, int color2B, int gradient) {
	int sqSize = (2 << size) + 1;
	int x = sqSize;
	int y = sqSize;
	int z = sqSize / depth;

	BMP *image = new BMP;
	DS* obj = new DS(sqSize);

	obj->DiamondSquare(z);

	Isometric_Render iso(NULL, image, 0, x, 0, y, 0, z);

	image->SetSize(iso.width + DEBUGGING_WIDTH, iso.height + DEBUGGING_HEIGHT);

	double *** map2d = &(obj->the_grid);

	iso.map_2d = map2d;
	iso.BFS_place(1, 1, 1); //RENDERING USING BFS

	std::stringstream buffer;
	buffer << "Terrain"
		<< ".bmp";

	image->WriteToFile(buffer.str().c_str());

	return EXIT_SUCCESS;
}
