#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertion_sort(int arr[], int n) {
    int i, curr, prev;
    for (i = 1; i < n; i++) {
        curr = arr[i];
        prev = i - 1;
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
        }
        arr[prev + 1] = curr;
    }
}

void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int n, i, low, high;
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter the range (low high): ");
    scanf("%d %d", &low, &high);

    int arr[n], arr1[n], arr2[n], arr3[n];
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = (rand() % (high - low + 1)) + low;
        
    }
    for (i = 0; i < n; i++) {
        printf("%d ",arr[i]);
        
    }
    printf("\n");

    copy_array(arr, arr1, n);
    copy_array(arr, arr2, n);
    copy_array(arr, arr3, n);

    clock_t start, end;
    double time_taken;

    start = clock();
    bubble_sort(arr1, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort time: %f seconds\n", time_taken);

    start = clock();
    insertion_sort(arr2, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort time: %f seconds\n", time_taken);

    start = clock();
    selection_sort(arr3, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort time: %f seconds\n", time_taken);

    return 0;
}
