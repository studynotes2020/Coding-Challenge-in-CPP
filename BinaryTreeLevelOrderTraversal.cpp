#include <vector>
#include <queue> 
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int>levelnode;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        
        if (root==NULL) return ans;
        
        while(!myQueue.empty()){
            int nodesize = myQueue.size();
            
            for(int i=0; i<nodesize; ++i){
                TreeNode* node = myQueue.front();
                myQueue.pop(); //clear this element
                levelnode.push_back(node->val);
                if(node->left!=NULL)myQueue.push(node->left);
                if(node->right!=NULL)myQueue.push(node->right);
            }
            
            ans.push_back(levelnode);
            levelnode.clear();
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
    string input = "6,4,3,1,7,3,4,6,8";
    TreeNode* root = stringToTreeNode(input);
    vector<vector<int>> res = Solution().levelOrder(root);
    printNestedVector(res);

    return 0;
}
