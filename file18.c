#include  <stdio.h>

int scores[60];

int main(){
FILE * in = fopen("scores.txt", "r");
for (int h = 0; h < 60; h++)
fscanf(in, "%d", &scores[h]);

fclose(in);

printf("the last element is %d",scores[59]);

}