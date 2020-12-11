#include <iostream>
using namespace std;

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 
if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string?
For the purpose of this problem, we will return 0 when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        if (n == 0) return 0;
        if (m < n) return -1;

        int count = 0;
        for(int i = 0; i < m; i++) {
            if (haystack[i] == needle[0]) {
                int k = i;
                for (int j = 0; j < n; j++) {
                    if (haystack[k+j] == needle[j])
                        count++;
                    else
                        break;
                }
                if (count == n)
                    return i;
                else
                    count = 0;
            }


        }
        return -1;

    }
};

int main() {
    cout << Solution().strStr("hello","ll") << endl;
    return 0;

}
