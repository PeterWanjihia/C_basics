#include <stdio.h>
#include <stdlib.h>

int glb_uninit; /* Part of BSS Segment -- global uninitialized variable, at runtime it is initialized to zero */
int glb_init = 10; /* Part of DATA Segment -- global initialized variable */

void foo(void) {
    static int num = 0; /* Static variable, stored in DATA Segment */
    int autovar; /* Automatic variable/Local variable, stored in Stack Segment */
    int* ptr_foo = (int*)malloc(sizeof(int)); /* Dynamically allocated memory, stored in Heap Segment */

    if (++num == 4) /* Creating four stack frames */
        return;

    printf("Stack frame number %d: address of autovar: %p\n", num, &autovar);
    printf("Address of heap allocated inside foo() %p\n", ptr_foo);
    foo(); /* Recursive function call, creating a new stack frame */
    free(ptr_foo); /* Deallocating dynamically allocated memory */
}

int main() {
    char p, b, *nb; /* Automatic variables, stored in Stack Segment */
    int* ptr_main = (int*)malloc(sizeof(int)); /* Dynamically allocated memory, stored in Heap Segment */

    printf("Text Segment:\n");
    printf("Address of main: %p\n", main); /* Address of main function in Text Segment */
    printf("Address of foo: %p\n", foo); /* Address of foo function in Text Segment */

    printf("Stack Locations:\n");
    foo(); /* Function call, creating a new stack frame */

    printf("Data Segment:\n");
    printf("Address of glb_init: %p\n", &glb_init); /* Address of global initialized variable in Data Segment */

    printf("BSS Segment:\n");
    printf("Address of glb_uninit: %p\n", &glb_uninit); /* Address of global uninitialized variable in BSS Segment */

    printf("Heap Segment:\n");
    printf("Address of heap allocated inside main() %p\n", ptr_main); /* Address of dynamically allocated memory in Heap Segment */

    free(ptr_main); /* Deallocating dynamically allocated memory */
    return 0;
}