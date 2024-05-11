#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char ch;
    int n, letterCount[27], position(char);
    FILE *in, *out;

    in = fopen("passage.txt", "r");
    if (in == NULL) {
        printf("Error opening input file 'passage.txt'\n");
        return 1;
    }

    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error opening output file 'output.txt'\n");
        fclose(in);
        return 1;
    }

    for (n = 1; n <= 26; n++) letterCount[n] = 0;

    while ((ch = getc(in)) != EOF) {
        n = position(ch);
        if (n > 0) ++letterCount[n];
    }

    fprintf(out, "Letter Frequency\n\n");
    for (n = 1; n <= 26; n++)
        fprintf(out, "%4c %8d\n", 'a' + n - 1, letterCount[n]);

    fclose(in);
    fclose(out);
}

int position(char ch) {
    if (isupper(ch)) return ch - 'A' + 1;
    if (islower(ch)) return ch - 'a' + 1;
    return 0;
}