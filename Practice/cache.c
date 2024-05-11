#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define DATA_FILE "phonebook.dat"

// Structure to store name and phone number
typedef struct {
    char name[50];
    char phone[15];
} PhoneBook;

// Function prototypes
int binarySearch(PhoneBook arr[], int n, char *name);
void loadData(PhoneBook entries[], int *numEntries);
void saveData(PhoneBook entries[], int numEntries);

int main() {
    PhoneBook entries[MAX_ENTRIES];
    int numEntries = 0;
    char searchName[50];

    // Load data from file
    loadData(entries, &numEntries);

    // Read additional names and phone numbers into the array
    printf("Enter new names and phone numbers (type 'end' to stop):\n");
    while (numEntries < MAX_ENTRIES) {
        printf("Name: ");
        if (scanf("%49s", entries[numEntries].name) != 1 || strcmp(entries[numEntries].name, "end") == 0)
            break;
        printf("Phone number: ");
        scanf("%14s", entries[numEntries].phone);
        numEntries++;
    }

    // Sort the array by name (required for binary search)
    qsort(entries, numEntries, sizeof(PhoneBook), (int (*)(const void*, const void*))strcmp);

    // Search for a name
    printf("\nEnter a name to search: ");
    scanf("%49s", searchName);

    int index = binarySearch(entries, numEntries, searchName);
    if (index == -1)
        printf("Name not found.\n");
    else
        printf("Phone number for %s: %s\n", searchName, entries[index].phone);

    // Save data to file
    saveData(entries, numEntries);

    return 0;
}

// Binary search function (no changes)
int binarySearch(PhoneBook arr[], int n, char *name) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmpResult = strcmp(name, arr[mid].name);

        if (cmpResult == 0)
            return mid; // Name found
        else if (cmpResult < 0)
            right = mid - 1; // Search left subarray
        else
            left = mid + 1; // Search right subarray
    }

    return -1; // Name not found
}

// Load data from file
void loadData(PhoneBook entries[], int *numEntries) {
    FILE *file = fopen(DATA_FILE, "r");
    if (file != NULL) {
        int i = 0;
        while (fscanf(file, "%49s %14s", entries[i].name, entries[i].phone) == 2) {
            i++;
        }
        *numEntries = i;
        fclose(file);
    }
}

// Save data to file
void saveData(PhoneBook entries[], int numEntries) {
    FILE *file = fopen(DATA_FILE, "w");
    if (file != NULL) {
        for (int i = 0; i < numEntries; i++) {
            fprintf(file, "%s %s\n", entries[i].name, entries[i].phone);
        }
        fclose(file);
    }
}