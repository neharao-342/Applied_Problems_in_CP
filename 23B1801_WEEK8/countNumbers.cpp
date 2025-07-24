#include <iostream>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;

    int total = 10; // for n = 1
    int uniqueDigits = 9, available = 9;

    for (int i = 2; i <= n && available > 0; ++i) {
        uniqueDigits *= available;
        total += uniqueDigits;
        --available;
    }

    return total;
}

int main() {
    cout << "n = 2 → Output: " << countNumbersWithUniqueDigits(2) << endl; // 91
    cout << "n = 0 → Output: " << countNumbersWithUniqueDigits(0) << endl; // 1
    cout << "n = 3 → Output: " << countNumbersWithUniqueDigits(3) << endl; // 739
    return 0;
}
