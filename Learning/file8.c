#include <stdio.h>

int main() {
    printf("Enter data: ");

    int count = 0;
    char ch;

    for (;;) {
        ch = getchar();
        if (ch == '\n') {
            break;
        }
        printf("Character %d is %c\n", count + 1, ch);
        count++;
    }

    printf("The length of the input is: %d\n", count);

    return 0;
}


#include <stdio.h>;

int main(){
    printf("Enter data:");
    int i =0;
    char ch;
    while ((ch=getchar())!='\n'){
        printf("Character %d is %c\n",i+1,ch);
        i++;
    }
    printf("The length of input is: %d\n",i);
    return 0;
}