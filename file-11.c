#include <stdio.h>
int main() {
char ch;
FILE *in = fopen("input.txt", "r");
while ((ch = getc(in)) != EOF)
putchar(ch);
fclose(in);
}