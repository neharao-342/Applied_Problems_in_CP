#include <iostream>
#include <vector>
#include <climits>  // for INT_MAX
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1); // fill with amount+1 as infinity
    dp[0] = 0; // base case

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    // Example 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Output for Example 1: " << coinChange(coins1, amount1) << endl;

    // Example 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Output for Example 2: " << coinChange(coins2, amount2) << endl;

    // Example 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Output for Example 3: " << coinChange(coins3, amount3) << endl;

    return 0;
}
