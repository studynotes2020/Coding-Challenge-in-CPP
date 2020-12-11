#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int depth = 0;
        while (!myQueue.empty()) {
            depth++;
            int TreeSize = myQueue.size();
            for (int i=0; i<TreeSize; i++) {
                TreeNode* node = myQueue.front();
                myQueue.pop();
                if (node->left) myQueue.push(node->left);
                if (node->right) myQueue.push(node->right);
                if (node->left==NULL && node->right==NULL) return depth;//delete this line if find max
            }
        }
        return depth;
    }
};

int main() {
    string input = "6,4,3,1,7,3,4,6,8";
    TreeNode* root = stringToTreeNode(input);
    int res = Solution().minDepth(root);
    cout << res << endl;

    return 0;
}
