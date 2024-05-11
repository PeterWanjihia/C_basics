#include <stdio.h>

int main(){
    char ch;
    int numChar = 0;
    int numBlanks=0;

    printf("Enter some data and press enter:");

    while ((ch = getchar()) != '\n'){
        numChar++;
        if (ch == ' ') numBlanks++;
    }
    printf("The number of chacracters is %d\n",numChar);
    printf("The number of blanks is %d\n",numBlanks);

    
}