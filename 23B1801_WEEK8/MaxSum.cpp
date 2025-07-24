#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp = arr;  // dp[i] stores max sum ending at index i

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> arr1 = {1, 101, 2, 3, 100};
    vector<int> arr2 = {4, 1, 2, 3};
    vector<int> arr3 = {4, 1, 2, 4};

    cout << "Input: [1, 101, 2, 3, 100] → Output: " << maxSumIncreasingSubsequence(arr1) << endl; // 106
    cout << "Input: [4, 1, 2, 3] → Output: " << maxSumIncreasingSubsequence(arr2) << endl;       // 6
    cout << "Input: [4, 1, 2, 4] → Output: " << maxSumIncreasingSubsequence(arr3) << endl;       // 7

    return 0;
}
