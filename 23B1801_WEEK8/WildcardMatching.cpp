#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Base case: both empty
    dp[0][0] = true;

    // If pattern starts with '*', it can match empty string
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    // Fill the table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "aa", p1 = "a";
    cout << boolalpha << "Example 1: " << isMatch(s1, p1) << endl;  // false

    string s2 = "aa", p2 = "*";
    cout << "Example 2: " << isMatch(s2, p2) << endl;  // true

    string s3 = "cb", p3 = "?a";
    cout << "Example 3: " << isMatch(s3, p3) << endl;  // false

    return 0;
}
