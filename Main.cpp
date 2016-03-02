#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main() {
	World_Map Plot(50,50,50);
	int i = 0;
	int j = 0;
	int k = 0;
    //change made
	bmp image(10,10,(char*)"air.bmp");
	image.save();
	printf("Saved!\n");
	int x_max = Plot.get_x();
	int y_max = Plot.get_y();
	int z_max = Plot.get_z();
	for (i = 0; i < x_max; i++) {
		for (j = 0; j < y_max; j++) {
			for (k = 0; k < z_max; k++) {
				if (k == (int)(25 + 10 * sin(i))) {
					Plot.set_point(i, j, k);
					cout << "i: " << i << "  j: " << j << "  k: " << k << endl;
				}

			}
		}
	}

	//Plot.~World_Map();
	return EXIT_SUCCESS;
}
