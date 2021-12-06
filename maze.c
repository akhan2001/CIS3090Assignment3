/**
 * @file maze.c
 * @author Abdullah Khan (mkhan94@uoguelph.ca) - 1101209
 * @brief This program implements the Depth-first algorithm that creates a path
 * through a two dimensional array. This path represents a 2D maze.
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "stack.h"

/*Global variable*/
int **mazeArray;

/**
 * @brief Allocates the two 2D arrays with proper memory size
 * @param size 
 */
void allocate_array(int size) {
    /*Mallocs the mazeArray array*/
	mazeArray = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        mazeArray[i] = (int*)malloc(size * sizeof(int));
    }
}

/**
 * @brief Initializes the array with proper numbers
 * @param size 
 */
void initialize_array(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mazeArray[i][j] = -1;
        }
    }
}

/**
 * @brief Simple swap function
 * @param a 
 * @param b 
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Randomizes given array with shuffled elements
 * @param temp 
 * @param n 
 */
void randomize_array(int temp[], int n) {
    srand(time(0));
    int i;
    for(i = n - 1; i > 0; i--) {
        /*Random number generator*/
        int j = rand() % (i + 1);
        swap(&temp[i], &temp[j]);
    }
}

/**
 * @brief Shuffles the array that is made {1,2,3,4}
 * @return int* arr
 */
int *shuffle_array() {
    static int arr[4] = {1, 2, 3, 4};
    int n = sizeof(arr)/ sizeof(arr[0]);
    randomize_array(arr, n);
    return arr;
}

/**
 * @brief Checks the given point for the neighbors based on requirements. And claims the 
 * points with number '0' using random generated directions
 * @param size 
 * @param x 
 * @param y 
 */
void check_neighbors(int size, int x, int y) {
    int *randArr;
    /*Random num order generator*/
    randArr = shuffle_array();

    // for (int i = 0; i < 4; i++) {
    //     //randNums[i] = 1 + rand() % (4 + 1 - 1);
    //     printf("--- %d ", randArr[i]);
    // }
    //printf("\n");

    for (int i = 0; i < 4; i++) {
        //printf("Number chosen: %d\n", randArr[i]);
        switch (randArr[i]) {
        case 1: //UP
            if (x - 2 <= 0) {
                //If out of bounds, continue
                continue;
            } else if (mazeArray[x - 2][y] == -1) {
                mazeArray[x - 2][y] = 0;
                mazeArray[x - 1][y] = 0;
                check_neighbors(size, x - 2, y);
            }
            break;
        case 2: //RIGHT
            if (y + 2 >= size - 1) {
                //If out of bounds, continue
                continue;
            } else if (mazeArray[x][y + 2] == -1) {
                mazeArray[x][y + 2] = 0;
                mazeArray[x][y + 1] = 0;
                check_neighbors(size, x, y + 2);
            }
            break;
        case 3: //DOWN
            if (x + 2 >= size - 1) {
                //If out of bounds, continue
                continue;
            } else if (mazeArray[x + 2][y] == -1) {
                mazeArray[x + 2][y] = 0;
                mazeArray[x + 1][y] = 0;
                check_neighbors(size, x + 2, y);
            }
            break;
        case 4: //LEFT
            if (y - 2 <= 0) {
                //If out of bounds, continue
                continue;
            } else if (mazeArray[x][y - 2] == -1) {
                mazeArray[x][y - 2] = 0;
                mazeArray[x][y - 1] = 0;
                check_neighbors(size, x, y - 2);
            }
            break; 
        }
    }
}

/**
 * @brief Prints out the maze grid
 * @param size
 */
void print_maze(int size) {
    printf("\nMaze: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mazeArray[i][j] == -1) {
                printf(". ");
            } else {
                printf("%d ", mazeArray[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Main Function
 */
int main(int argc, char* argv[]) {
    /*Declarations of variables*/
    int sizeArray = 0;

    /*Basic error-checking/initializing for command-line arguments*/
    if (argc == 1) {
        sizeArray = 11;
    } else if (argc == 2) {
        sizeArray = 11;
    } else if (argc == 3) {
        sizeArray = atoi(argv[2]);
    } else if (argc == 4) {
        if (strcmp(argv[1], "-n") == 0) {
            sizeArray = atoi(argv[2]);
        } else if (strcmp(argv[2], "-n") == 0) {
            sizeArray = atoi(argv[3]);
        } else {
            printf("Enter:\t\t./maze -n [size of maze]\n");
            printf("\t\t./maze (runs program with default 11 size maze)\n");
            printf("\t\t./maze -s -n [size of maze]\n");
            printf("\t\t./maze -n [size of maze] -s\n");
            exit(0);
        }
    } else {
        printf("Enter:\t\t./maze -n [size of maze]\n");
        printf("\t\t./maze (runs program with default 11 size maze)\n");
        printf("\t\t./maze -s -n [size of maze]\n");
        printf("\t\t./maze -n [size of maze] -s\n");
        exit(0);
    }

    /*Fill array according to size*/
    allocate_array(sizeArray);
    initialize_array(sizeArray);
    
    //Initial point for thread 1 (1,1)
    mazeArray[1][1] = 0;

    check_neighbors(sizeArray, 1, 1);
    print_maze(sizeArray);
 
    // Stack* stackStruct = NULL;
    // push(&stackStruct, 1, 2);
    // push(&stackStruct, 2, 3);
    // push(&stackStruct, 3, 2);
    // pop(&stackStruct);
    // pop(&stackStruct);
    // pop(&stackStruct);
    // peek(stackStruct);

    // if (isEmpty(stackStruct)) {
    //     printf("Stack is empty\n");
    // } else {
    //     printf("Stack is not empty\n");
    // }

    return 0;
}