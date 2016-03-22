#include "Header.h"

// This class is for Generating Diamond Square

// ====================================================
DS::DS() {
	// Test
	set_array2d(ARRAY_SIZE,ARRAY_SIZE);
	cout << "This is the constructor, an obj has been created" << endl;
}

//Creates empty 2d array 
void DS::set_array2d(int x, int y)
{
	int i;
	this->the_grid = (double**)malloc(x * sizeof(double*));

	for (i = 0; i < x; i++)
	{
		*(this->the_grid + i) = (double*)malloc(y * sizeof(double));
	}
	for (i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			this->the_grid[i][j] = -1;
		}
	}

}
//== DiamondSquare function creates and repeats Square and diamond ==*/
void DS::DiamondSquare() {

	//====== Variables Declaration
	/*size of this->the_grid to generate, note this must be a value 2^n+1 */
	/*An initial seed value for the corners of the data in the array */
	const double SEED = 1000.0;

	//===========Variable Initialization

	//seed the data in this->the_grid, "making all corners = SEED"
	this->the_grid[0][0] = this->the_grid[0][ARRAY_SIZE - 1] = this->the_grid[ARRAY_SIZE - 1][0] =
		this->the_grid[ARRAY_SIZE - 1][ARRAY_SIZE - 1] = SEED;

	//==========
	/*  New value in range of height.
	Side length is distance of a single square side.
	Or distance of diagonal in diamond. */
	double height = 500.0;//the range (-h to +h) for the average offset
	double ranVal = rand();

	for (int sideLength = ARRAY_SIZE - 1; sideLength >= 2; sideLength /= 2, height /= 2.0) {
		/*half the length of the side of a square,
		Or distance from diamond center to one corner
		(just to make calcs below a little clearer)*/
		int halfSide = sideLength / 2;



		/* ***************************
		//generate new square values *
		//****************************/
		for (int x = 0; x<ARRAY_SIZE - 1; x += sideLength) {
			for (int y = 0; y<ARRAY_SIZE - 1; y += sideLength) {
				//x, y is upper left corner of square
				//calculate average of existing corners
				double avg = this->the_grid[x][y] + //top left
					this->the_grid[x + sideLength][y] +//top right
					this->the_grid[x][y + sideLength] + //lower left
					this->the_grid[x + sideLength][y + sideLength];//lower right
				avg /= 4.0;

				//center is average plus random offset
				this->the_grid[x + halfSide][y + halfSide] =
					/*We calculate random value in range of 2h
					and then subtract h so the end value is
					in the range (-h, +h)  */

					avg + (ranVal * 2 * height) - height;

				//Test
				cout << "\n height= " << height << "\n Side Length= " << sideLength <<
					"\n Avg=" << avg << endl;
			}

		} // End of the square part





		  /* *****************************
		  * generate the diamond values *
		  *******************************
		  //since the diamonds are staggered we only move x
		  //by half side
		  //NOTE: if the data shouldn't wrap then x < ARRA_SIZE
		  //to generate the far edge values */

		for (int x = 0; x<ARRAY_SIZE - 1; x += halfSide) {
			/* and y is x offset by half a side, but moved by
			//the full side length
			//NOTE: if the data shouldn't wrap then y < ARRAY_SIZE
			//to generate the far edge values*/

			for (int y = (x + halfSide) % sideLength; y<ARRAY_SIZE - 1; y += sideLength) {
				/* x, y is center of diamond
				//note we must use mod  and add ARRAY_SIZE for subtraction
				//so that we can wrap around the array to find the corners */
				double avg =
					this->the_grid[(x - halfSide + ARRAY_SIZE) % ARRAY_SIZE][y] + //left of center
					this->the_grid[(x + halfSide) % ARRAY_SIZE][y] + //right of center
					this->the_grid[x][(y + halfSide) % ARRAY_SIZE] + //below center
					this->the_grid[x][(y - halfSide + ARRAY_SIZE) % ARRAY_SIZE]; //above center
				avg /= 4.0;

				//new value = average plus random offset
				//We calculate random value in range of 2h
				//and then subtract h so the end value is
				//in the range (-h, +h)
				avg = avg + (ranVal * 2 * height) - height;
				//update value for center of diamond
				this->the_grid[x][y] = avg;

				//wrap values on the edges, remove
				//this and adjust loop condition above
				//for non-wrapping values.
				if (x == 0)  this->the_grid[ARRAY_SIZE - 1][y] = avg;
				if (y == 0)  this->the_grid[x][ARRAY_SIZE - 1] = avg;

				//test
				cout << "ave = " << avg << endl;
			}
		}
	} //Big outer for

} // end of fu()


  // ================ The main function ========
/*
int main() {
	DS obj;
	obj.DiamondSquare();


	return 0;
}
*/


