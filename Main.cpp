#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main() {
	World_Map Plot(50,50,50);
	int i;
	int j;
	int k;
    //change made
	for (i = 0; i < Plot.get_x(); i++) {
		for (j = 0; j < Plot.get_y(); j++) {
			for (k = 0; k < Plot.get_z(); k++) {
				if (k == (int)(25 + 10 * sin(i))) {
					Plot.set_point(i, j, k);
					cout << "i: " << i << "  j: " << j << "  k: " << k << endl;
				}

			}
		}
	}

	return EXIT_SUCCESS;
}
