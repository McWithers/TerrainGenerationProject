#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Resources.h"

int main() {
	World_Map Plot(50,50,50);
	int i;
	int j;
	int k;
	for (i = 0; i < Plot.get_x(); i++) {
		for (j = 0; j < Plot.get_y(); j++) {
			for (k = 0; k < Plot.get_z(); k++) {
				(int) (25 + 10 * sin(i));
				
			}
		}
	}







	return EXIT_SUCCESS;
}