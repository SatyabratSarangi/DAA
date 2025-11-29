#include <stdio.h>

struct Item {
    int id;
    float profit, weight, ratio, percent;
};

void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item items[], int n, float capacity) {
    int i;
    float maxProfit = 0;
    sortItems(items, n);
    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            items[i].percent = 100;
            capacity -= items[i].weight;
            maxProfit += items[i].profit;
        } else {
            items[i].percent = (capacity / items[i].weight) * 100;
            maxProfit += items[i].profit * (items[i].percent / 100);
            break;
        }
    }
    return maxProfit;
}

int main() {
    struct Item items[20];
    int n, i;
    float capacity, result;
    printf("Enter number of items: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter ID, Profit and Weight of item %d: ", i + 1);
        scanf("%d %f %f", &items[i].id, &items[i].profit, &items[i].weight);
        items[i].ratio = items[i].profit / items[i].weight;
        items[i].percent = 0;
    }
    printf("Enter capacity of Knapsack: ");
    scanf("%f", &capacity);
    result = fractionalKnapsack(items, n, capacity);
    printf("\nSelected Items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d -> %.2f%%\n", items[i].id, items[i].percent);
    }
    printf("\nMaximum Profit: %.2f\n", result);
    return 0;
}
