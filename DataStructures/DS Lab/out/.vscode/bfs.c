#include <stdio.h>
#include <stdlib.h>

// Function for insertion sort
void insort(int arr[], int n, int *count) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*count) += 2;  // Increment count for comparisons and assignments
        }
        arr[j + 1] = key;
        (*count) += 1; // Increment for the assignment of key
    }
}

int main() {
    int i, n;
    int count = 0; // Counter for time complexity
    int space; // Space complexity

    // Input the size of the array
    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;  // Exit if input is invalid
    }
    
    int ar[n];  // Declare the array (VLA)
    space = sizeof(int) * n; // Count space for the array

    // Input the elements of the array
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &ar[i]) != 1) {
            printf("Invalid input.\n");
            return 1;  // Exit on invalid input
        }
        count += 2;  // Increment for input reading
    }

    // Call the insertion sort function
    insort(ar, n, &count);
    
    // Print the sorted array
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");

    // Print space and time complexities
    printf("Space Complexity : %d bytes\n", space);
    printf("Time Complexity : %d operations\n", count);
    
    return 0;
}
