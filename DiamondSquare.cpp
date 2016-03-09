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
<<<<<<< Updated upstream
    set_x(size); 
    set_y(size);
    set_array2d(this->x, this->y); 
    this->array2d[0][this->y-1] = rand() % max_height; 
	 this->array2d[0][0] = rand() % max_height;
	 this->array2d[this->x-1][0] = rand() % max_height;
	 this->array2d[this->x-1][this->y-1] = rand() % max_height;
 
     
}

Diamond_Square::Diamond_Square() {}
=======
    set_x(5); 
    set_y(5);
    set_array2d(get(x), get(y)); 
    int** newArray = get_array2d(); 
    
    newArray[0][get_y()] = rand() % 11; 
    newArray[0][0] = rand() % 11; 
    newArray[get_x()][0] = rand)() % 11; 
    newArray[get_x()][get_y()] = rand() % 11;
     
}

int Diamond_Squre::find_midpoint(int value1, int value2)
{
    int midpoint = (int)(std::floor((value1 - value2) / 2);
    
    return(midpoint);
}
>>>>>>> Stashed changes
