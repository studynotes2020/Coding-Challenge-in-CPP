#include <iostream>

using namespace std;

//Because from 1 to n, the number of 2 factors is always bigger than the number of 5 factors.
// So we only need to find the number of 5 factors among 1...n.
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (long long i = 5; n / i; i *= 5)
            count += n / i;
        return count;

    }
};

int main() {
    cout << Solution().trailingZeroes(70) << endl;

}