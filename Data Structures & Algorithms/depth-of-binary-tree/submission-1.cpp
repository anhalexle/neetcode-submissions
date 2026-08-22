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
        // DFS (incursive)
        // if (!root) return 0;
        // return 1 + max(maxDepth(root->left), maxDepth(root->right));

        // BFS (queue)
        if (!root) return 0;
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while(q.size() != 0)
        {
            int tempQueueSize = q.size();
            for (int i = 0; i < tempQueueSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            level++;
        }
        return level;
    }
};
