#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int weights[], int values[], const int w, const int n) {
    int dp[n + 1][w + 1] = {0};
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    return dp[n][w];
}
int solveOptimized(int weights[], int values[], const int w, const int n) {
    int dp[2][w + 1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < w + 1; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weights[i - 1] > j) {
                dp[1][j] = dp[0][j];
            } else {
                dp[1][j] = max(dp[0][j], dp[0][j - weights[i - 1]] + values[i - 1]);
            }
        }
        for (int j = 0; j < w + 1; j++) {
            dp[0][j] = dp[1][j];
        }
    }
    return dp[1][w];
}
void constructSolution(int weights[], int values[], const int w, const int n) {
    int dp[n + 1][w + 1] = {0};
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    int i = n, j = w;
    cout << "Weights used to fill bag of capacity " << w << ":";
    while (i >= 0 && j >= 0) {
        if (weights[i - 1] <= j) {
            if (dp[i - 1][j] > (values[i - 1] + dp[i - 1][j - weights[i - 1]])) {
                i--;
            } else {
                if (weights[i - 1] != 0)
                    cout << weights[i - 1] << " ";
                j -= weights[i - 1];
                i--;
            }
        } else {
            i--;
        }
    }
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, capacity;
        cin >> n >> capacity;
        int weights[1000], values[1000];
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }
        // cout << solve(weights, values, capacity, n) << endl;
        cout << solveOptimized(weights, values, capacity, n) << endl;
        constructSolution(weights, values, capacity, n);
    }
    return 0;
}