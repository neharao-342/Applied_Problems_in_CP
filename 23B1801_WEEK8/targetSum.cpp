#include <iostream>
#include <vector>
#include <numeric>  // for accumulate
using namespace std;

// Function to find number of expressions that evaluate to target
int findTargetSumWays(vector<int>& nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);

    // If (total + target) is odd or target is not reachable
    if ((total + target) % 2 != 0 || abs(target) > total)
        return 0;

    int subsetSum = (total + target) / 2;
    vector<int> dp(subsetSum + 1, 0);
    dp[0] = 1;  // Only one way to make sum 0 (empty subset)

    for (int num : nums) {
        for (int j = subsetSum; j >= num; --j) {
            dp[j] += dp[j - num];
        }
    }

    return dp[subsetSum];
}

int main() {
    // Example 1
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Output for Example 1: " << findTargetSumWays(nums1, target1) << endl;

    // Example 2
    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "Output for Example 2: " << findTargetSumWays(nums2, target2) << endl;

    // You can also take input from user like this:
    /*
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << "Enter target: ";
    cin >> target;
    cout << "Output: " << findTargetSumWays(nums, target) << endl;
    */

    return 0;
}
