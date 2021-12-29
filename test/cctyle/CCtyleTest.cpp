//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#include <gtest/gtest.h>

namespace {

TEST(CCtyleTest, create_2d_array)
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

//    assert(test_array[1] == 4);
//    static_assert(test_array.size() == 5);
//    assert(test::is_equal(actual_vector, expected_vector));
}

TEST(CCtyleTest, create_2d_array_as_single_array)
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

//    assert(test_list.size() == 0);
//    assert(test::is_equal(actual_vector, expected_vector));
}

TEST(CCtyleTest, allocate_string)
{
    const int size = 5;
    char* character = (char*)malloc(sizeof(char) * size);
    assert(character != NULL && "character is NULL");
    strcpy(character, "moo");
    printf("%s\n", character);
    free(character);
}
}
