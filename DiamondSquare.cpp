 #include "Header.h"

//Creates empty 2d array 
int** Diamond_Squre::Make_Array(int x, int y)
{
    int i; 
    int** newArray = (int**) malloc(x * sizeof(int*)); 
    
    for(i = 0; i < x; i++)
    { 
        *(newArray + i) = (int*)malloc(y * sizeof(int)); 
    }
    
    return(newArray);     
}

//Setting corners of array 
void Set_Corners(int** array)
{
    array[0][0] = 
}
