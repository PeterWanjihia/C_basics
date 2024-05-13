#include <stdio.h>


int strlength(char input[]){
    int i;
    for (i = 0;input[i] != '\0';i++){
        
    }
    return i;
}
int main(){ 
    char input[20];   
    printf("Enter characters:");
    scanf("%19s", input);
  
    int length = strlength(input);
    printf("The length of the string is %d\n",length);

    return 0;
}