/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // DFS
        // base case
        // if (!root) return 0;
        // return 1 + std::max(maxDepth(root->left), maxDepth(root->right));

        // BFS
        if (!root) return 0;

        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int level = 0;
        while(!myQueue.empty())
        {
            int size = myQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* base = myQueue.front();
                myQueue.pop();
                if (base->left)
                {
                    myQueue.push(base->left);
                }
                if (base->right)
                {
                    myQueue.push(base->right);
                }
            }
            ++level;
        }
        return level;
    }
};
