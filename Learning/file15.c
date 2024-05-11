#include <stdio.h>

int main() {
    int n;
    int factorial(int);

    printf("Enter a number: ");
    scanf("%d", &n);
    
    printf("The factorial of %d is %d\n", n,factorial(n));


}

int factorial(int n) {
    int result = 1;

    if (n > 0) {
        while (n > 1) {
            result *= n;
            n--;
        }
    }


    return result;
}