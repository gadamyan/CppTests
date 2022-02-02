//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include <gtest/gtest.h>

namespace {

TEST(CCtyleTest, create_2d_array_and_check_the_values)
{
    const int rowCount = 10;
    const int reelCount = 20;

    int** array = (int**)calloc(rowCount, sizeof(int*));
    for (int i = 0; i < rowCount; ++i) {
        array[i] = (int*)calloc(reelCount, sizeof(int));
        for (int j = 0; j < reelCount; ++j) {
            array[i][j] = i * j;
        }
    }

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < reelCount; ++j) {
            ASSERT_EQ(array[i][j], i * j);
        }
    }

    for (int i = 0; i < rowCount; ++i) {
        free(array[i]);
    }
}

TEST(CCtyleTest, create_2d_array_as_single_array_and_check_the_values)
{
    const int rowCount = 10;
    const int reelCount = 20;

    int* array = (int*)malloc(sizeof(int) * rowCount * reelCount);

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < reelCount; ++j) {
            const int index = i * reelCount + j;
            array[index] = i * j;
        }
    }

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < reelCount; ++j) {
            const int index = i * reelCount + j;
            ASSERT_EQ(array[index], i * j);
        }
    }

    free(array);
}

TEST(CCtyleTest, allocate_string_and_check_size)
{
    const int size = 5;
    char* character = (char*)malloc(sizeof(char) * size);
    assert(character != NULL && "character is NULL");
    strcpy(character, "moo");
    ASSERT_EQ(strlen(character), 3);
    free(character);
}
}
