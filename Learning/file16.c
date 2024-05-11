#include <stdio.h>
int sumDivisors(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int sum = sumDivisors(n);
    printf("The sum of divisors of %d is: %d\n", n, sum);

    return 0;
}
int sumDivisors(int n){
    int sumDiv =1;
    for (int h=2; h<=n/2;h++)
        if(n%h==0) sumDiv+=h;
    return sumDiv;
}