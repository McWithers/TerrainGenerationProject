#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "EasyBMP.h"
int main() {
	int x=20;
	int y=20;
	int z=20;
	World_Map Plot(x,y,z);
	int i = 0;
	int j = 0;
	int k = 0;
	BMP *image = new BMP;
	Isometric_Render iso(&Plot, image, 0, x-1, 0, y-1, 0, z-1);
	image->SetSize(iso.width + DEBUGGING_WIDTH, iso.height+1+DEBUGGING_HEIGHT);
	for (i = 0; i < iso.width; i++) {
		for (j = 0; j < iso.height; j++) {
			RGBApixel* pixel = new RGBApixel;
			pixel->Alpha = 127;
			pixel->Red = 0;
			pixel->Green = 0;
			pixel->Blue = 0;
			image->SetPixel(i, j, *pixel);
		}
	}
    //change made
	//bmp image(10,10,(char*)"air.bmp");
	//image->save();
	printf("Saved!\n");
	int x_max = Plot.get_x();
	int y_max = Plot.get_y();
	int z_max = Plot.get_z();
	//for (i = 0; i < x_max; i++) {
		//for (j = 0; j < y_max; j++) {
			//for (k = 0; k < z_max; k++) {
				//if (k == (int)(25 + 10 * sin(i))) {
				//if (1) {
					//Plot.set_point(i, j, k);
					//int * point = iso.find_xy(i, j, k);
					//iso.place_cube(i,j,k);
					//RGBApixel* pixel = new RGBApixel;
					//pixel->Alpha = 127;
					//pixel->Red = Plot.get_point(i, j, k)->r;
					//pixel->Green = Plot.get_point(i, j, k)->g;
					//pixel->Blue = Plot.get_point(i, j, k)->b;
					//image->SetPixel(point[0], iso.height-point[1], *pixel);
					//cout << "i: " << i << "  j: " << j << "  k: " << k << endl;
				//}
				//}
			//}
		//}
	//}
	RGBApixel* pixel = new RGBApixel;
	pixel->Alpha = 127;
	pixel->Red =192;
	pixel->Green = 192;
	pixel->Blue = 192;
	int a[2];
	a[0] = 17;
	a[1] = 82;
	int b[2];
	a[0] = 43;
	a[1] = 53;
	iso.draw_line(a, b, pixel);
	pixel = new RGBApixel;
	pixel->Alpha = 127;
	pixel->Red = 0;
	pixel->Green = 0;
	pixel->Blue = 0;
	image->SetPixel(0, 0, *pixel);


	Plot.set_point(0, 0, 0);
	int * point = iso.find_xy(0, 0, 1);
	printf("\n\n\n%d     %d\n", point[0], point[1]);
	point = iso.find_xy(1, 1, 0);
	printf("\n%d     %d\n", point[0], point[1]);
	image->WriteToFile("isometric.bmp");

	//Plot.~World_Map();
	return EXIT_SUCCESS;
}
