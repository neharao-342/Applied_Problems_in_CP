#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center / 2;
            int right = left + (center % 2); // handles both even and odd length

            while (left >= 0 && right < n && s[left] == s[right]) {
                ++count;
                --left;
                ++right;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    string s1 = "abc";
    cout << "Output for \"" << s1 << "\": " << sol.countSubstrings(s1) << endl;

    string s2 = "aaa";
    cout << "Output for \"" << s2 << "\": " << sol.countSubstrings(s2) << endl;

    return 0;
}
