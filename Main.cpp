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
	Diamond_Square terrain(11,11);
	BMP *image = new BMP;
	Isometric_Render iso(&Plot, image, 0, x-1, 0, y-1, 0, z-1);
	image->SetSize(iso.width + DEBUGGING_WIDTH, iso.height+DEBUGGING_HEIGHT);
	for (i = 0; i < iso.width; i++) {
		for (j = 0; j < iso.height; j++) {
			RGBApixel* pixel = new RGBApixel;
			pixel->Alpha = 127;
			//pixel->Red = (int)(iso.height * 255 / (j + 1))%255;
			pixel->Red = 0;
			//pixel->Green = (int)((iso.height/255)*i);
			pixel->Green = 0;
			pixel->Blue = 0;
			image->SetPixel(i, j, *pixel);
		}
	}
	//iso.place_cube(2, 2, 2);
    //change made
	//bmp image(10,10,(char*)"air.bmp");
	//image->save();
	printf("Saved!\n");
	int x_max = Plot.get_x();
	int y_max = Plot.get_y();
	int z_max = Plot.get_z();
	int * a = (int *)malloc(sizeof(int) * 2);
	int * b = (int *)malloc(sizeof(int) * 2);
	a[0] = 40;//x1
	b[1] = 60;//y1
	b[0] = 100;//x2
	a[1] = 80;//y2

	for (i = -sqSize/2; i < x_max-sqSize/2; i++) {
		for (j = -sqSize/2; j < y_max-sqSize/2; j++) {
			for (k = -sqSize/2; k < z_max-sqSize/2; k++) {
				if (i*i + j*j + k*k <= 19 * 19 ? i*i + j*j + k*k >= 18 * 18 ? 1 : 0 : 0) {
					//if (1) {
					Plot.set_point(i+sqSize/2, j+sqSize/2, k+sqSize/2);
					int * point = iso.find_xy(i+sqSize/2, j+sqSize/2, k+sqSize/2);
					iso.place_cube(i+sqSize/2, j+sqSize/2, k+sqSize/2);
					/*RGBApixel* pixel = new RGBApixel;
					pixel->Alpha = 127;
					pixel->Red = Plot.get_point(i, j, k)->r;
					pixel->Green = Plot.get_point(i, j, k)->g;
					pixel->Blue = Plot.get_point(i, j, k)->b;
					image->SetPixel(point[0], iso.height - point[1], *pixel);
					*/
					cout << "i: " << i << "  j: " << j << "  k: " << k << endl;
				}
			}
		}
	}
	
	//}
	RGBApixel* pixel = new RGBApixel;
	pixel->Alpha = 127;
	pixel->Red =192;
	pixel->Green = 192;
	pixel->Blue = 192;
	//int * a = (int *)malloc(sizeof(int)*2);
	//a[0] = 17;
	//a[1] = 82;
	//int * b = (int *)malloc(sizeof(int) * 2);
	//b[0] = 25;
	//b[1] = 3;
	//iso.draw_line(a, b, pixel);
	//pixel = new RGBApixel;
	//pixel->Alpha = 127;
	//pixel->Red = 0;
	//pixel->Green = 0;
	//pixel->Blue = 0;
	//image->SetPixel(0, 0, *pixel);
	free(a);
	free(b);

	//Plot.set_point(0, 0, 0);
	int * point = iso.find_xy(0, 0, 1);
	printf("\n\n\n%d     %d\n", point[0], point[1]);
	point = iso.find_xy(1, 1, 0);
	printf("\n%d     %d\n", point[0], point[1]);
	image->WriteToFile("isometric.bmp");

	//Plot.~World_Map();
	return EXIT_SUCCESS;
}
