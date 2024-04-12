#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n, matrix[MAX_SIZE][MAX_SIZE];
    int max_sum = 0, current_sum;
    int row, col, start_row, start_col;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }

    // Check main diagonals
    start_row = 0;
    start_col = 0;
    do {
        current_sum = 0;
        row = start_row;
        col = start_col;
        while (row < n && col < n) {
            current_sum += matrix[row][col];
            row++;
            col++;
        }
        if (current_sum > max_sum)
            max_sum = current_sum;
        start_row++;
    } while (start_row < n);

    start_row = 0;
    start_col = n - 1;
    do {
        current_sum = 0;
        row = start_row;
        col = start_col;
        while (row < n && col >= 0) {
            current_sum += matrix[row][col];
            row++;
            col--;
        }
        if (current_sum > max_sum)
            max_sum = current_sum;
        start_col--;
    } while (start_col >= 0);

    printf("The largest sum along any diagonal is: %d\n", max_sum);

    return 0;
}