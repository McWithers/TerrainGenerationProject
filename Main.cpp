#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "EasyBMP.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int sqSize = (2 << 4) + 1;
	int x=sqSize;
	int y=sqSize;
	int z=50;
	World_Map Plot(x,y,z);
	int i = 0;
	int j = 0;
	int k = 0;
	Diamond_Square terrain(5,100);
	BMP *image = new BMP;
	int *tl = (int*)calloc(sizeof(int), 4);
	int *tr = (int*)calloc(sizeof(int), 4);
	int *br = (int*)calloc(sizeof(int), 4);
	int *bl = (int*)calloc(sizeof(int), 4);
	tl[0] = 0;
	tl[1] = terrain.get_size() - 1;
	tr[0] = terrain.get_size() - 1;
	tr[1] = terrain.get_size() - 1;
	br[0] = terrain.get_size() - 1;
	br[1] = 0;
	bl[0] = 0;
	bl[1] = 0;
	terrain.square(tl,tr,br,bl);
	//Generate_Shapes shape(4);
	//shape.make2dterrainimage(terrain.get_array2d());
	
	DS* obj = new DS(sqSize);
	obj->DiamondSquare(50-1);
	Plot.convert_to_3d(obj->get_grid());
	Isometric_Render iso(&Plot, image, 0, x - 1, 0, y - 1, 0, z - 1);
	image->SetSize(iso.width + DEBUGGING_WIDTH, iso.height+DEBUGGING_HEIGHT);

	//for (int level = x + y + z - 3; level >=3; level--) {
	for (int level = 3; level < x + y + z - 3; level++) {
	
		//for (i = 1; i < x - 1; i++) {
		for (i = x-1; i >= 1; i--) {

			//for (j = 1; j < y - 1; j++) {
			for (j = y-1; j >= 1; j--) {

				//for (k = z-1; k >= 1; k--) {
				for (k = 1; k < z - 1; k++) {
				
					if ((i+j+k)==level) {
						if (Plot.map[i][j][k]->isSet == 1) {
							iso.place_cube(i, j, k);
						}
					}
				}
			}
		}
	}
	time_t now = time(NULL);
	struct tm *time_info = new tm;
	localtime_s(time_info, &now);
	if (time_info) {}
	//time_t t = time(0);   // get time now
	//struct tm * now = localtime_s(&t);
	std::stringstream buffer;

	buffer << "isometric" 
		<< (time_info->tm_year + 1900) << '.'
		<< (time_info->tm_mon + 1) << '.'
		<< time_info->tm_mday << '-'
		<< time_info->tm_hour << "h_"
		<< time_info->tm_min << "m_"
		<< time_info->tm_sec << "s"
		<< ".bmp";
	image->WriteToFile(buffer.str().c_str());
	return EXIT_SUCCESS;
}
