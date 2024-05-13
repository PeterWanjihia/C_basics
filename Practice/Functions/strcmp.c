#include <stdio.h>


// string length
int strlength(char input[]){
    int i;
    for (i = 0;input[i] != '\0';i++){
        
    }
    return i;
}
int strcompare(char string1[], char string2[]) {
    int len1 = strlength(string1);
    int len2 = strlength(string2);

    if (len1 != len2) {
        return -1;  // Return a non-zero value if lengths are not equal
    }

    for (int i = 0; string1[i] != '\0'; i++) {
        if (string1[i] != string2[i]) {
            return string1[i] - string2[i];  // Return the difference of the mismatched characters
        }
    }

    return 0;  // Strings are equal
}

int main(){ 
    char string1[20],string2[20];   
    printf("Enter first string:");
    scanf("%19s", string1);
    printf("Enter second string:");
    scanf("%19s", string2);

    

    int result = strcompare(string1, string2);
    if (result < 0) {
        printf("'%s' comes before '%s'\n", string1, string2);
    } else if (result > 0) {
        printf("'%s' comes after '%s'\n", string1, string2);
    } else {
        printf("'%s' and '%s' are equal\n", string1, string2);
    }

    return 0;
  
  
    

    return 0;
}