#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "EasyBMP.h"
int main() {
	int sqSize = 40;
	int x=sqSize;
	int y=sqSize;
	int z=sqSize;
	World_Map Plot(x,y,z);
	int i = 0;
	int j = 0;
	int k = 0;
	Diamond_Square terrain(5,100);
	BMP *image = new BMP;
	Isometric_Render iso(&Plot, image, 0, x-1, 0, y-1, 0, z-1);
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
	
	DS* obj = new DS();
	obj->DiamondSquare();
	//image->SetSize(iso.width + DEBUGGING_WIDTH, iso.height+DEBUGGING_HEIGHT);
	//image->WriteToFile("isometric.bmp");
	return EXIT_SUCCESS;
}
