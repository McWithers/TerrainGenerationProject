 #include "Header.h"

//Creates empty 2d array 
void Diamond_Square::set_array2d(int x, int y)
{
    int i; 
    this -> array2d = (int**) malloc(x * sizeof(int*)); 
    
    for(i = 0; i < x; i++)
    { 
        *(this -> array2d + i) = (int*)malloc(y * sizeof(int)); 
    }
	 for (i = 0; i < x; i++) {
		 for (int j = 0; j < y; j++) {
			 array2d[i][j] = -1;
		 }
	 }
    
}

void Diamond_Square::set_x(int value)
{
    this -> x = value; 
}

void Diamond_Square::set_y(int value)
{
    this -> y = value; 
}

int** Diamond_Square::get_array2d()
{
    return(this -> array2d);
}

int Diamond_Square::get_x()
{
    return(this -> x); 
}

int Diamond_Square::get_y()
{
    return(this -> y); 
}
int Diamond_Square::get_size()
{
	return this->size;
}
int Diamond_Square::get_max_height()
{
	return this->max_height;
}
//Setting corners of array -- from values 0 to 10 for now
Diamond_Square::Diamond_Square(int size, int max_height)
{
    set_x(size); 
    set_y(size);
	 this->size = size;
	 this->max_height = max_height;
    set_array2d(this->x, this->y); 
    this->array2d[0][this->size-1] = rand() % max_height; 
	 this->array2d[0][0] = rand() % max_height;
	 this->array2d[this->size-1][0] = rand() % max_height;
	 this->array2d[this->size-1][this->size-1] = rand() % max_height;
	 printf("array2d[4][4]: %d\n", array2d[4][4]);

     
}

Diamond_Square::Diamond_Square() {}

int Diamond_Square::find_midpoint(int value1, int value2)
{
    int midpoint = (int)(std::floor((value2 - value1) / 2));
    
    return(midpoint);
}

void Diamond_Square::square(int * top_left, int * top_right, int * bottom_right, int * bottom_left) {
	int new_x = find_midpoint(top_left[0],top_right[0]);
	int new_y = find_midpoint(bottom_left[0],top_right[0]);
	//find bounds for height
	int * minmax_h = (int *)malloc(sizeof(int)*4);
	minmax_h[0] = array2d[top_left[0]][top_left[1]];
	minmax_h[1] = array2d[top_right[0]][top_right[1]];
	minmax_h[2] = array2d[bottom_right[0]][bottom_right[1]];
	minmax_h[3] = array2d[bottom_left[0]][bottom_left[1]];
	printf("x_offset: %d\ny_offset: %d\ntl: %d\ntr: %d\nbr: %d\nbl: %d\n", new_x, new_y, minmax_h[0], minmax_h[1], minmax_h[2], minmax_h[3]);
	minmax_h[0] = minmax_h[1] < minmax_h[0] ? minmax_h[1] : minmax_h[0];
	minmax_h[0] = minmax_h[2] < minmax_h[0] ? minmax_h[2] : minmax_h[0];
	printf("upper: %d\nlower: %d\n", minmax_h[3],minmax_h[0]);

	array2d[new_x][new_y] = minmax_h[0] + rand() % (minmax_h[3] + 1);


	free(minmax_h);
	return;

}
