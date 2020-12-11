#include <map> 
#include <string>
#include <iostream>

using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same character 
but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> char1, char2;
        
        for(int i=0; i<s.size(); i++){
            if(char1[s[i]]==0 && char2[t[i]]==0)
                char1[s[i]]=char2[t[i]]=i+1;
                
            else if (char1[s[i]]!=char2[t[i]]){
                return false;
            }
        }
        return true;
        
    }
};

int main() {
    string s = "egg";
    string t = "add";
    cout << Solution().isIsomorphic(s, t) << endl;

    return 0;
}
