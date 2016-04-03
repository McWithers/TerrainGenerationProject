#include "Header.h"
using namespace std;
// This class is for Generating Diamond Square

// ====================================================
DS::DS() {
	// Test
	set_array2d(this->size,this->size);
	this->size = 9;
	set_array2d(9, 9);
	cout << "This is the constructor, an obj has been created" << endl;
}

DS::DS(int the_size) {
	DS();
	this->size = the_size;
	set_array2d(the_size, the_size);
}

double ** DS::get_grid()
{
	return this->the_grid;
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
			this->the_grid[i][j] = 0;
		}
	}

}
void DS::delete_array2d()
{
	for (int i = 0; i < this->size; i++) {
		free(this->the_grid[i]);
	}
	free(this->the_grid);
}
//== DiamondSquare function creates and repeats Square and diamond ==*/
void DS::DiamondSquare(const double SEED) {

	//====== Variables Declaration
	/*size of this->the_grid to generate, note this must be a value 2^n+1 */
	/*An initial seed value for the corners of the data in the array */
	// double SEED = 50.0;

	//===========Variable Initialization

	//seed the data in this->the_grid, "making all corners = SEED"
	this->the_grid[0][0] = this->the_grid[0][this->size - 1] = this->the_grid[this->size - 1][0] =
		this->the_grid[this->size - 1][this->size - 1] = SEED;

	//==========
	/*  New value in range of height.
	Side length is distance of a single square side.
	Or distance of diagonal in diamond. */
	double height = SEED/2;//the range (-h to +h) for the average offset
	//double ranVal = rand() % (int)height;// % (int)height;
	if (NEW) 
		srand(time(NULL));
	cout << "ranVal: " << rand() % (int) height << endl;

	for (int sideLength = this->size - 1; sideLength >= 2; sideLength /= 2, height /= 2.0) {
		/*half the length of the side of a square,
		Or distance from diamond center to one corner
		(just to make calcs below a little clearer)*/
		int halfSide = sideLength / 2;



		/* ***************************
		//generate new square values *
		*/
		for (int x = 0; x<this->size - 1; x += sideLength) {
			for (int y = 0; y<this->size - 1; y += sideLength) {
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

					avg + rand() % ((int)(height) ? (int) height : 1) - height;

				//Test
				//cout << "\n height= " << height << "\n Side Length= " << sideLength <<
					//"\n Avg=" << avg << endl;
			}

		} // End of the square part





		  /* *****************************
		  * generate the diamond values *
		  *******************************
		  //since the diamonds are staggered we only move x
		  //by half side
		  //NOTE: if the data shouldn't wrap then x < ARRA_SIZE
		  //to generate the far edge values */

		for (int x = 0; x<this->size - 1; x += halfSide) {
			/* and y is x offset by half a side, but moved by
			//the full side length
			//NOTE: if the data shouldn't wrap then y < this->size
			//to generate the far edge values*/

			for (int y = (x + halfSide) % sideLength; y<this->size - 1; y += sideLength) {
				/* x, y is center of diamond
				//note we must use mod  and add this->size for subtraction
				//so that we can wrap around the array to find the corners */
				double avg =
					this->the_grid[(x - halfSide + this->size) % this->size][y] + //left of center
					this->the_grid[(x + halfSide) % this->size][y] + //right of center
					this->the_grid[x][(y + halfSide) % this->size] + //below center
					this->the_grid[x][(y - halfSide + this->size) % this->size]; //above center
				avg /= 4.0;

				//new value = average plus random offset
				//We calculate random value in range of 2h
				//and then subtract h so the end value is
				//in the range (-h, +h)
				avg = avg + rand() % ((int)(height) ? (int)height : 1) - height;
				//update value for center of diamond
				this->the_grid[x][y] = avg;

				//wrap values on the edges, remove
				//this and adjust loop condition above
				//for non-wrapping values.
				if (x == 0)  this->the_grid[this->size - 1][y] = avg;
				if (y == 0)  this->the_grid[x][this->size - 1] = avg;

				//test
				printf("ave: %f\n", avg);
				//cout << "ave = " << avg << endl;
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


