#include <iostream>
#include <vector>

using namespace std;

// Function to find maximum value and selected items
pair<int, vector<pair<int, int>>> knapsack_max_value(const vector<int>& weights, const vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find selected items
    vector<pair<int, int>> selected_items;
    int i = n, w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_items.push_back({weights[i - 1], values[i - 1]});
            w -= weights[i - 1];
        }
        --i;
    }

    return {dp[n][W], selected_items};
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    // Find maximum value and selected items
    pair<int, vector<pair<int, int>>> result = knapsack_max_value(weights, values, W);

    // Output the result
    cout << "Maximum value: " << result.first << endl;
    cout << "Selected items:" << endl;
    for (auto item : result.second) {
        cout << "Weight: " << item.first << ", Value: " << item.second << endl;
    }

    return 0;
}
