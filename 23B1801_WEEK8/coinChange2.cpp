#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;  // base case

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    // Example 1
    int amount1 = 5;
    vector<int> coins1 = {1, 2, 5};
    cout << "Output for Example 1: " << change(amount1, coins1) << endl;

    // Example 2
    int amount2 = 3;
    vector<int> coins2 = {2};
    cout << "Output for Example 2: " << change(amount2, coins2) << endl;

    // Example 3
    int amount3 = 10;
    vector<int> coins3 = {10};
    cout << "Output for Example 3: " << change(amount3, coins3) << endl;

    return 0;
}
