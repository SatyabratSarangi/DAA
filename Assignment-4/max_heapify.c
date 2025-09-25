#include <stdio.h>

int heapsize;   

int parent(int i) {
    return i / 2;
}

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void max_heapify(int A[], int i) {
    int l = left(i);     
    int r = right(i);    
    int largest, temp;

    if (l <= heapsize && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= heapsize && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        max_heapify(A, largest);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    heapsize = n;   
    int A[n + 1];  
    printf("Enter %d elements:\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Original array:\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");

    for (int i = n / 2; i >= 1; i--) {
        max_heapify(A, i);
    }

    printf("Max Heap:\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}