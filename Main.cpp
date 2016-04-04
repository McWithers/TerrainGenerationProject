#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "EasyBMP.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int sqSize = (2 << 3) + 1;
	int x = sqSize;
	int y = sqSize;
	int z = sqSize;
	//World_Map Plot(x, y, z);
	//Diamond_Square terrain(5, 100);
	BMP *image = new BMP;
	/*
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
	terrain.square(tl, tr, br, bl);
	*/
	//Generate_Shapes shape(4);
	//shape.make2dterrainimage(terrain.get_array2d());
	
	DS* obj = new DS(sqSize);
	obj->DiamondSquare(z - 1);
	//Plot.convert_to_3d(obj->get_grid());
	Isometric_Render iso(NULL, image, 0, x, 0, y, 0, z);
	image->SetSize(iso.width + DEBUGGING_WIDTH, iso.height + DEBUGGING_HEIGHT);
    
    //Random print statement
	double *** map2d = &(obj->the_grid);

	for (int level = 3; level < (x - 1) + (y - 1) + (z - 1) - 3; level += 1) {

		for (int i = 1; i < x; i += 1) {

			for (int j = 1; j < y; j += 1) {

				for (int k = 1; k < z; k += 1) {


					if ((i + j + k) == level) {
						//if (level == 15) {
							//if (Plot.map[x - i][y - j][k]->isSet == 1) {
								//Plot.map[i][j][k]->r = 192;
								//Plot.map[i][j][k]->g = 192;
								//Plot.map[i][j][k]->b = 192;
								//iso.place_cube(x - i, y - j, k);
							//}
						int newx = x - i;
						int newy = y - j;
						int newz = obj->the_grid[x - i][y - j];
						RGBApixel * pixel = new RGBApixel;
						pixel->Alpha = 127;
						pixel->Red = 192;
						pixel->Blue = 192;
						pixel->Green = 192;
					//	iso.place_cube(newx, newy, newz, pixel);
						if (k == newz) {
							std::cerr << "found pixel: " << 100.0 * ((double) level / ((x - 1) + (y - 1) + (z - 1) - 3 ))<< "%" << std::endl  ;
							iso.place_cube(newx, newy, newz, pixel);
						}
						else if (k <= newz) {
							pixel->Red = 255 / (x - 1)*i % 255;
							pixel->Green = 255 / (y - 1)*j % 255;
							pixel->Blue = 255 / (z - 1)*k % 255;
							iso.place_cube(newx, newy, k, pixel);
						}
						delete pixel;
						//}
					}
				}
			}
		}
	}
	time_t now = time(NULL);
	struct tm *time_info = new tm;
	localtime_s(time_info, &now);
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
	//delete time_info;
	//std::cerr.flush();
	return EXIT_SUCCESS;
}
