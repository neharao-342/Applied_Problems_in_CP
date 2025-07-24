#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j],
                              min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    return dp[m][n];
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << "Edit Distance: " << minDistance(word1, word2) << endl;

    word1 = "intention", word2 = "execution";
    cout << "Edit Distance: " << minDistance(word1, word2) << endl;

    return 0;
}
