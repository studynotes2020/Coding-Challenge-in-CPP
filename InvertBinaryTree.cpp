#include <vector>
#include <queue> 
#include <stack>
#include "TreeNode.h"

using namespace std;

/*
Invert a binary tree.

Example:
Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1


*/


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(nullptr == root) return root;

        stack<TreeNode*> myStack;   // stack to do BFS
        myStack.push(root);         //start from root

        while(!myStack.empty()){    // run until no nodes in the stack 
    
            TreeNode *node = myStack.top();  // get element from stack
            myStack.pop();                  //delete it
            
            if(node->left != nullptr){         // add left kid
                myStack.push(node->left);
            }
    
            if(node->right != nullptr){        // add right kid 
                myStack.push(node->right);
            }
    
            // invert left and right pointers      
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
    
        }

    return root;
        
    }
};

int main() {
    string input = "1,2,3,4";
    TreeNode* root = stringToTreeNode(input);
    root = Solution().invertTree(root);
    prettyPrintTree(root);

    return 0;
}
