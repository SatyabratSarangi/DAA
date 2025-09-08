//  Q4. Implementation of Recursive Binary Search
#include <stdio.h>

int binary_search(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] < key) {
        return binary_search(arr, mid + 1, high, key);
    } else {
        return binary_search(arr, low, mid - 1, key);
    }
}

int main() {
    int size, key, i;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter array elements in sorted order: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = binary_search(arr, 0, size - 1, key);
    if (result == -1) {
        printf("Element not present");
    } else {
        printf("Element found at index %d", result);
    }
    return 0;
}
