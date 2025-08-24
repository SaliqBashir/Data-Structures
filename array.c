#include <stdio.h>

void findMinMax(int arr[], int length);
int linearSearch(int arr[], int n, int key);

int main() {
    int length;
    printf("Enter size of array: ");
    scanf("%d", &length);
    
    int arr[length];
    
    for(int i =0; i<length;i++)
    {
        printf("Enter element number %i: ", i+1);
        scanf("%i", &arr[i]);
    }
    
    // Find min and max
    findMinMax(arr, length);

    // Linear search
    int find;
    printf("Enter number to search: ");
    scanf("%d", &find);
    
    int index = linearSearch(arr, length, find);
    if (index != -1){
        printf("Found %i at index %i\n", find, index);
    }
    else{
        printf("%d not found in array\n", find);
    }
    return 0;
}

// Function to find min and max in the array
void findMinMax(int arr[], int length) {
    int min = arr[0];
    int max = arr[0];
    
    for (int i = 1; i < length; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    printf("Minimum = %i\n", min);
    printf("Maximum = %i\n", max);
}

// Function for linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // return index if found
    }
    return -1;  // return -1 if not found
}
