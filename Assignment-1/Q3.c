// Q3. Implementation of Iterative Binary Search
#include <stdio.h>
int binary_search(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
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

    int result = binary_search(arr, size, key);

    if (result == -1) {
        printf("Element not present");
    } else {
        printf("Element found at index %d", result);
    }

    return 0;
}
