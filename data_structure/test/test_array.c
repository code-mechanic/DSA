#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Static array */
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Static array element: %d\n", arr[2]);

    /* Dynamic array */
    int *dynArr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++){
        dynArr[i] = i * 10;
    }
    printf("Dynamic array element: %d\n", dynArr[2]);
    free(dynArr);

    /* Static 2D array */
    int matrixStatic[2][3] = {{1,2,3},{4,5,6}};
    printf("Matrix element [1][2]: %d\n", matrixStatic[1][2]);

    /* Dynamic 2D array */
    int rows = 2, cols = 3;
    int **matrix = (int **)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    matrix[1][2] = 99;
    printf("Dynamic Matrix [1][2]: %d\n", matrix[1][2]);

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
