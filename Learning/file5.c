# include <stdio.h>

int main() {
    FILE * out = fopen("product.txt", "w");
    int n, product,multiplier = 2;
    printf("Enter your number: ");
    scanf("%d", &n);
    

    for (int h = 0; h<=n; h++){
        product = multiplier * h;
        fprintf( out,"The product of %d and %d is %d\n",h , multiplier, product);      
        

    }
    fclose(out);
    
}