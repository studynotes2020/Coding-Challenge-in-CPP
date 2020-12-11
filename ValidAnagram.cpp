#include <iostream>
#include <vector>

using namespace std;

/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note: You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabert(26,0);
        for(int i=0; i<s.size(); i++){
            alphabert[s[i]-'a']+=1;
        }
        for(int i=0; i<t.size(); i++){
            alphabert[t[i]-'a']-=1;
        }
        for(int i=0;i<alphabert.size();i++){
            if(alphabert[i]!=0) return false;
        }
        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    cout << Solution().isAnagram(s, t) << endl;

    return 0;
}