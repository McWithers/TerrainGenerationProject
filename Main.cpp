#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "EasyBMP.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int sqSize = (2 << 5) + 1;
	int x = sqSize;
	int y = sqSize;
	int z = sqSize;
	World_Map Plot(x, y, z);
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
	Plot.convert_to_3d(obj->get_grid());
	Isometric_Render iso(&Plot, image, 0, x - 1, 0, y - 1, 0, z - 1);
	image->SetSize(iso.width + DEBUGGING_WIDTH, iso.height + DEBUGGING_HEIGHT);

	//for (int level = x + y + z - 3; level >=3; level--) {
	//for (int level = 3; level < x + y + z - 3; level++) {
	for (int level = 3; level < (x - 1) + (y - 1) + (z - 1) - 3; level += 1) {

		//cout << "hi" << endl;

		//for (i = 1; i < x - 1; i++) {
		//for (i = x - 1; i >= 1; i--) {
		//for (int i = ((count >> 2) % 2) ? x - 1 : 1; ((count >> 2) % 2) ? (i >= 1) : (i < x - 1); i += ((count >> 2) % 2) ? -1 : 1) {
		for (int i = 1; i < x - 1; i += 1) {

			//cout << "can" << endl;

			//for (j = 1; j < y - 1; j++) {
			//for (j = y - 1; j >= 1; j--) {
			//for (int j = ((count >> 1) % 2) ? y - 1 : 1; ((count >> 1) % 2) ? (j >= 1) : (j < y - 1); j += ((count >> 1) % 2) ? -1 : 1) {
			for (int j = 1; j < y - 1; j += 1) {

				//cout << "i" << endl;

				//for (k = z-1; k >= 1; k--) {
				//for (k = 1; k < z - 1; k++) {
				//for (int k = ((count >> 0) % 2) ? z - 1 : 1; ((count >> 0) % 2) ? (k >= 1) : (k < z - 1); k += ((count >> 0) % 2) ? -1 : 1) {
				for (int k = 1; k < z - 1; k += 1) {

					//cout << "help" << endl;

					if ((i + j + k) == level) {
						if (Plot.map[x - i][y - j][k]->isSet == 1) {
							/*Plot.map[i][j][k]->r = 192;
							Plot.map[i][j][k]->g = 192;
							Plot.map[i][j][k]->b = 192;
							*/iso.place_cube(x - i, y - j, k);
						}
					}
				}
			}
		}
	}
	time_t now = time(NULL);
	struct tm *time_info = new tm;
	localtime_s(time_info, &now);
	//time_t now = time(0);   // get time now
	//struct tm * time_info = localtime(&now);
	std::stringstream buffer;

	buffer << "fixed"
		<< (time_info->tm_year + 1900) << '.'
		<< (time_info->tm_mon + 1) << '.'
		<< time_info->tm_mday << '-'
		<< time_info->tm_hour << "h_"
		<< time_info->tm_min << "m_"
		<< time_info->tm_sec << "s"

		//buffer << "newsets/"
			//<< (count >> 3)%2 << (count >> 2) % 2 << (count >> 1) % 2 << (count >> 0) % 2
		<< ".bmp";
	image->WriteToFile(buffer.str().c_str());
	delete time_info;
	//delete[]iso;
	//delete[]obj;
	//delete[]image;
	//delete[]Plot;
	//delete[]terrain;


	return EXIT_SUCCESS;
}
