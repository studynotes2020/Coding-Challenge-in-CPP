#include <vector>
#include <map>
#include <iostream>

using namespace std;

/*
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in 
words exactly once and without any intervening characters.

Example 1:
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []

*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
 
      map<string, int> CompareWords;  
      map<string, int> count;  
      for(int i =0; i< words.size(); i++) {  
        CompareWords[words[i]]+=1;  
      }  
      vector<int> result;  
      int numWords = words.size();  
      if(numWords ==0) return result;  
      int wordLen = words[0].size();  
      for(int i =0; i< (int)s.size() - numWords*wordLen+1; i++) {  
        count.clear();
        int j=0;
        for(; j< numWords; j++)  {  
          string sub = s.substr(i+j*wordLen, wordLen);  
          if(CompareWords.find(sub) != CompareWords.end())  {  
            count[sub]+=1;  
          }
          else  
            break;  
          if(count[sub] > CompareWords[sub])  {  
            break;  
          }
        }
        if(j == numWords)  
          result.push_back(i);  
      }
      return result;  
    }
};


int main() {
  string s = "barfoothefoobarman";
  vector<string> words = {"foo","bar"};
  vector<int> res = Solution().findSubstring(s, words);
  for (const auto &str: res) {
    cout << str << " ";
  }
}
