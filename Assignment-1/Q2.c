// Q2. Implementation of Recursive Linear Search

#include <stdio.h>

int linear_search(int arr[], int size, int key, int index) {
    if (index == size) {
        return -1;  
    }
    if (arr[index] == key) {
        return index;
    }else{
       return linear_search(arr, size, key, index + 1);
    }
}

int main() {
    int size, key, i;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = linear_search(arr, size, key, 0);

    if (result == -1) {
        printf("Element not present");
    } else {
        printf("Element found at index %d", result);
    }

    return 0;
}
