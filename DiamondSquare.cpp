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

int** Diamond_Squre::get_array2d()
{
    return(this -> array2d);
}
//Setting corners of array 
void Diamond_Squre::set_corners(int** array)
{
    set_array2d(5, 5); 
    int** newArray = get_array2d();  
}
