#include <stdio.h>
#include <math.h>

#define NUM_CUSTOMERS_MAX 1000
#define NUM_ORDERS 5

void readOrders(int orders[][NUM_ORDERS], int numCustomers) {
    for (int i = 0; i < numCustomers; i++) {
        for (int j = 0; j < NUM_ORDERS; j++) {
            scanf("%d", &orders[i][j]);
        }
    }
}

int calculateSum(double score[], int orders[][NUM_ORDERS], int numCustomers) {
    double sum = 0;
    for (int i = 0; i < numCustomers; i++) {
        for (int j = 0; j < NUM_ORDERS; j++) {
            if (orders[i][j]) {
                sum += score[j];
            }
        }
    }
    return ceil(sum);
}

int main(void) {
    int numCustomers, sum;
    int orders[NUM_CUSTOMERS_MAX][NUM_ORDERS];
    double score[NUM_ORDERS] = {1, 0.75, 0.5, 0.25, 0.125};

    scanf("%d", &numCustomers);
    readOrders(orders, numCustomers);
    sum = calculateSum(score, orders, numCustomers);
    printf("%d\n", sum);

    return 0;
}
