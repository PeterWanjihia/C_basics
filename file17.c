#include <stdio.h>

int main (){
    char  ch;
    int isDigit(char );
    
    printf("Enter a character:\n");
    scanf("%c", &ch);
    isDigit(ch);

   return 0;
}

int isDigit(char ch){
    return ch >= '0' && ch <= '9';
}