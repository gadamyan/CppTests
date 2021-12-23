#include "CSolutions.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>


void CSolutions::create2DArray() const
{
    const int rowCount = 10;
    const int reelCount = 10;
    
    int** array = (int**)calloc(rowCount, sizeof(int*));
    for (int i = 0; i < rowCount; ++i)
    {
        array[i] = (int*)calloc(reelCount, sizeof(int));
    }
    
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < reelCount; ++j)
        {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < rowCount; ++i)
    {
        free(array[i]);
    }
}

void CSolutions::create2DArrayAsSingleArray() const
{
    const int rowCount = 10;
    const int reelCount = 10;
    
    int* array = (int*)malloc(sizeof(int) * rowCount * reelCount);
    
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < reelCount; ++j)
        {
            const int index = i * reelCount + j;
            array[index] = i * j;
        }
    }
    
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < reelCount; ++j)
        {
            const int index = i * reelCount + j;
            printf("%d", array[index]);
        }
        printf("\n");
    }
    
    free(array);
}

void CSolutions::alocate() const
{
    const int size = 5;
    char* character = (char*)malloc(sizeof(char) * size);
    assert(character != NULL && "character is NULL");
    strcpy(character, "moo");
    printf("%s\n", character);
    free(character);
    
    create2DArrayAsSingleArray();
    create2DArray();
}
