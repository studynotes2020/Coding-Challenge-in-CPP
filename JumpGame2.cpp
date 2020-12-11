#include <vector>
#include <iostream>

using namespace std;

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int start = 0;  
        int end = 0;  
        int count =0;  
        if(n == 1) return 0;  
        while(end < n)  {  
            int max = 0;  
            count++;  
            for(int i =start; i<= end ; i++ ) {   
            if(nums[i]+i >= n-1)                  
                return count;  
            
            if(nums[i]+ i > max)  
                max = nums[i]+i;  
            }     
        start = end+1;  
        end = max;        
        } 
    }

};

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << Solution().jump(nums) << endl;

    return 0;
}
