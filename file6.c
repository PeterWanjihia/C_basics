#include <stdio.h>

#define SIZE 5  // Adjust the size as needed

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int row, col;

    printf("Main Diagonal: ");
    for (row = 0, col = 0; row < SIZE; row++, col++) {
        printf("%d ", matrix[row][col]);
    }

    printf("\nSecondary Diagonal: ");
    for (row = 0, col = SIZE - 1; row < SIZE; row++, col--) {
        printf("%d ", matrix[row][col]);
    }

    return 0;
}