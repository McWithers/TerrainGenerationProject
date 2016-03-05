 #include "Header.h"

//Creates empty 2d array 
int** Make_Array(int x, int y)
{
    int i; 
    int** newArray = (int**) malloc(x * sizeof(int*)); 
    
    for(i = 0; i < x; i++)
    { 
        *(newArray + i) = (int*)malloc(y * sizeof(int)); 
    }
    
    return(newArray);     
}

