#include <stdio.h>

int main() {
    int n, result = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n > 0) {
        while (n > 1) {
            result *= n;
            n--;
        }
        printf("The factorial of %d is %d\n", n, result);
    } else {
        printf("Invalid input. Please enter a positive integer.\n");
    }

    return 0;
}