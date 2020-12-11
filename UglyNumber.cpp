#include <iostream>

using namespace std;
/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5

Example 1:
Input: 6
Output: true
Explanation: 6 = 2 × 3

Example 2:
Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2

Example 3:
Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.
*/

class Solution {
public:
    bool isUgly(int num) {
        
        if(num<=0) return false;
        if(num==1) return true;

        while(num%2==0) num = num/2;
        while(num%3==0) num = num/3;
        while(num%5==0) num = num/5;
        //num = maxDivide(num, 2);
        //num = maxDivide(num, 3);
        //num = maxDivide(num, 5);
   
        if(num==1) return true;
        else return false;
        
    }
    int maxDivide(int a, int b) {
        while (a%b == 0) a = a/b;//continue to divide to the smallest
        return a;
    } 
};

int main() {
    int num = 8;
    cout << Solution().isUgly(num) << endl;

    return 0;
}
