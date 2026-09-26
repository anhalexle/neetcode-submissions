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
        if (!root) return 0;
        vector<vector<int>> dfs;
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            dfs.push_back({});
            for (int i = 0; i < size; i++)
            {
                TreeNode* top = q.front();
                dfs[level].push_back(top->val);
                if (top->left)
                {
                    q.push(top->left);
                }
                if (top->right)
                {
                    q.push(top->right);
                }
                q.pop();
            }
            level++;
        }
        return dfs.size();
    }
};
