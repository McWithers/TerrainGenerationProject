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
//Setting corners of array -- from values 0 to 10 for now
Diamond_Square::Diamond_Square(int size, int max_height)
{
    set_x(size); 
    set_y(size);
    set_array2d(get_x(), get_y()); 
    this->array2d[0][get_y()] = rand() % max_height; 
	 this->array2d[0][0] = rand() % max_height;
	 this->array2d[get_x()][0] = rand() % max_height;
	 this->array2d[get_x()][get_y()] = rand() % max_height;
 
     
}

Diamond_Square::Diamond_Square() {}