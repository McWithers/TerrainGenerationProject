 #include "Header.h"

//Creates empty array
int** Make_Array(int size)
{
    int i; 
    int** newArray = (int**) malloc(size * sizeof(int*)); 
    
    for(i = 0; i < size; i++)
    { 
        *(newArray + i) = (int*)malloc(size * sizeof(int)); 
    }
    
    return(newArray);     
}