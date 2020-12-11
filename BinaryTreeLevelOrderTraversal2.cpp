#include <vector>
#include <queue> 
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> levelnodes;

        if (root==NULL) return ans;
        
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        
        stack<vector<int>> myStack;
        
        while(!myQueue.empty()){
            int nodesize = myQueue.size();
            for(int i=0;i<nodesize;++i){
                TreeNode* node = myQueue.front();//point to new element
                myQueue.pop();//delete that element in queue
                levelnodes.push_back(node->val);
                if(node->left!=NULL) myQueue.push(node->left); 
                if(node->right!=NULL) myQueue.push(node->right);
            }
            
            myStack.push(levelnodes); //each level
            levelnodes.clear();
        }
        
        while(!myStack.empty()){ //put into answer
            ans.push_back(myStack.top());
            myStack.pop();
        }
        return ans;
        
    }
};

void printNestedVector(vector<vector<int>> res) {
    if (res.size() == 0) {
        cout << "Empty nested vector";
        return;
    }

    for (const auto &v: res) {
        for (const int &i : v)
            cout << i << " ";
        cout << endl;
    }

}

int main() {
    string input = "6,4,3,1,7";
    TreeNode* root = stringToTreeNode(input);
    vector<vector<int>> res = Solution().levelOrderBottom(root);
    printNestedVector(res);

    return 0;
}

