#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getstring(void)
{
    int buffer_size = 8; // Initial buffer size
    int position = 0;
    char *buffer = malloc(sizeof(char) * buffer_size);
    char c;

    if (buffer == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    while (1)
    {
        c = getchar();

        if (c == '\n' || c == EOF)
        {
            buffer[position] = '\0'; // Null-terminate the string
            return buffer;
        }
        else
        {
            buffer[position++] = c;
        }

        if (position >= buffer_size)
        {
            buffer_size += 8; // Increase buffer size
            buffer = realloc(buffer, buffer_size);

            if (buffer == NULL)
            {
                printf("Memory reallocation failed.\n");
                return NULL;
            }
        }
    }
}

int main(void)
{
    char *input_string = getstring();
    printf("You entered: %s\n", input_string);
    free(input_string); // Free the dynamically allocated memory
    return 0;
}