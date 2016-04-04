#include "Header.h"

void makeTree(int x, int y, int z, double ***map2d) {
	int i;
	int j;
	int k;
		int height = 4 + rand() % (7 - 4 - 1);
		for (i= z; i < height; i++) {
			//placecube(x, y, i);
		}
		z = i;
		if (rand() % 2) {
			height = 3;
			int width = 3;
			int depth = 6;
			x -= width / 2;
			y -= depth / 2;
			for (i = x; i < x + width; i++) {
				for (j = y; j < y + depth; j++) {
					for (k = z; k < z + height; k++) {
						//		placecube(i, j, k);
					}
				}
			}
		}
		else {
			height = 7;
			int width = 4;
			int depth = 4;
			x -= width / 2;
			y -= depth / 2;
			//z == sqrt(c*c*(i*(double)i/(a*a) + j*(double)j/(b*b)));
			for (i = x; i < x + width; i++) {
				for (j = y; j < y + depth; j++) {
					for (k = z; k < z + height; k++) {
						if (k == (-i*i - j*j + 6)) {
							//		placecube(i, j, k);
							int tempz = k;
							for (int h = tempz; h >= z; h--) {
								//placecube(i,j,h);
							}
						}
					}
				}
			}
		}

}