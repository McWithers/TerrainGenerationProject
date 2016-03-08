 #include "Header.h"

//Creates empty 2d array 
void Diamond_Squre::set_array2d(int x, int y)
{
    int i; 
    this -> array2d = (int**) malloc(x * sizeof(int*)); 
    
    for(i = 0; i < x; i++)
    { 
        *(this -> array2d + i) = (int*)malloc(y * sizeof(int)); 
    }
    
}

void Diamond_Squre::set_x(int value)
{
    this -> x = value; 
}

void Diamond_Squre::set_y(int value)
{
    this -> y = value; 
}

int** Diamond_Squre::get_array2d()
{
    return(this -> array2d);
}

int Diamond_Squre::get_x()
{
    return(this -> x); 
}

int Diamond_Squre::get_y()
{
    return(this -> y); 
}
//Setting corners of array -- from values 0 to 10 for now
void Diamond_Squre::set_corners(int** array)
{
    set_x(5); 
    set_y(5);
    set_array2d(get(x), get(y)); 
    int** newArray = get_array2d(); 
    
    newArray[0][get_y()] = rand() % 11; 
    newArray[0][0] = rand() % 11; 
    newArray[get_x()][0] = rand)() % 11; 
    newArray[get_x()][get_y()] = rand() % 11; 
 
     
}
