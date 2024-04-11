#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in = fopen("test.txt", "r");
    if (in == NULL) {
        printf("Error opening input file 'test.txt'.\n");
        return 1;
    }

    int num, sum = 0, count = 0;
    while (fscanf(in, "%d", &num) == 1) {
        if (num == 0) {
            break;
        }
        sum += num;
        count++;
    }

    if (count == 0) {
        printf("\nNo numbers supplied\n");
    } else {
        printf("\n%d number%s supplied\n", count, count > 1 ? "s" : "");
        printf("The sum is %d\n", sum);
        printf("The average is %.2f\n", (double)sum / count);
    }

    fclose(in);

    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file 'output.txt'.\n");
        return 1;
    }

    // Set the buffer mode to _IOFBF (fully buffered) and the buffer size to 1024 bytes
    char buffer[1024];
    setvbuf(fp, buffer, _IOFBF, sizeof(buffer));

    fprintf(fp, "Hello, world!\n");
    fprintf(fp, "This is some output written to a file.\n");

    // Accessing the buffer data is generally not recommended, as it can pose security risks
    // and should only be done if absolutely necessary. In this case, we'll skip it.
    for (int i = 0; i < sizeof(buffer); i++) {
        if (buffer[i] != '\0') {
            printf("Buffer data: %c\n", buffer[i]);
        }
    }

    fclose(fp);

    return 0;
}