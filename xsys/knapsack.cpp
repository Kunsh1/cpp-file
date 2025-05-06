#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int weights[], int values[], int n, int W) {
    int dp[n + 1][W + 1];

    // Initialize the DP table with 0
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Base Case: 0 items or 0 capacity
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
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
