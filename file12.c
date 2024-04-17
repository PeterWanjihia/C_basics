#include <stdio.h>

int main(){
    char ch;
    FILE *in = fopen("input2.txt","r");
    int lineNo = 1;
    printf("%2d. ",lineNo);

    while((ch =getc(in)) != EOF){
        putchar(ch);
        if (ch == '\n'){
            lineNo++;
            printf("%2d. ",lineNo);
        }
    }
    fclose(in);
}