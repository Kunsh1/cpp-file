#include <iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int W) {
    if (n == 0 || W == 0)
        return 0;

    if (weights[n - 1] > W)
        return knapsack(weights, values, n - 1, W);
    else
        return max(
            values[n - 1] + knapsack(weights, values, n - 1, W - weights[n - 1]),
            knapsack(weights, values, n - 1, W)
        );
}

int main() {
    int n = 4;
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int W = 5;

    int maxProfit = knapsack(weights, values, n, W);
    cout << "Maximum value: " << maxProfit << endl;

    return 0;
}
