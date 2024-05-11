# include <stdio.h>

int main(){
    char ch , bigChar = '\n';
    printf("Type some data and press Enter:");
   
    while ((ch = getchar())!= '\n')
        if (ch > bigChar) bigChar =ch;
    printf("\nThe largest character is %c \n",bigChar);
}