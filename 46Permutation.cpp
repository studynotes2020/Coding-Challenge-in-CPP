#include <iostream>
#include <vector>

using namespace std;

/*
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int>> result;

	    permuteRecursive(num, 0, result);
	    return result;
    }

    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int>> &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}

		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
    // Lexicographic order
    vector<string> generate_permutations(string word) {
        vector<string> result;
        if (word.length() <= 1) {
            result.push_back(word);
            return result;
        }
        for (int i = 0 ; i < word.length(); i++) {
            string shorter_word = word.substr(0, i) + word.substr(i+1);
            vector<string> shorter_permutations = generate_permutations(shorter_word);
            for (int j = 0; j < shorter_permutations.size(); j++) {
                string longer_word = word[i] + shorter_permutations[j];
                result.push_back(longer_word);
            }
        }
        return result;
    }
};

int main() {
	std::cout << "Permutation" << std::endl;
	vector<int> v = {1,2,3};
    vector<vector<int>> result = Solution().permute(v);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << '\t';
        }
        cout << endl;
    }
    string s = "123";
    vector<string> result2 = Solution().generate_permutations(s);
    for (int i = 0; i < result2.size(); i++)
        cout << result2[i] << "\n";
    return 0;
}