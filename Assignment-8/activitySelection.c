#include <stdio.h>

struct Activity {
    int id, start, finish;
};

void sortByFinish(struct Activity a[], int n) {
    int i, j;
    struct Activity temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i].finish > a[j].finish) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int activitySelection(struct Activity a[], int n, struct Activity selected[]) {
    int i, k = 0;
    sortByFinish(a, n);
    selected[0] = a[0];
    for (i = 1; i < n; i++) {
        if (a[i].start >= selected[k].finish) {
            k++;
            selected[k] = a[i];
        }
    }
    return k + 1;
}

int main() {
    struct Activity a[20], selected[20];
    int n, i, count;
    printf("Enter number of activities: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter ID, Start Time and Finish Time of Activity %d: ", i + 1);
        scanf("%d %d %d", &a[i].id, &a[i].start, &a[i].finish);
    }
    count = activitySelection(a, n, selected);
    printf("\nSelected Activities:\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d Start: %d Finish: %d\n", selected[i].id, selected[i].start, selected[i].finish);
    }
    return 0;
}
