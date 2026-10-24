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
    int maxPathSum(TreeNode* root) {
        int res = root->val; // first value
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* root, int& res)
    {
        if(!root)
            return 0;

        // Improve split, if it's negative, ignore it max(leftMax, rightMax, 0 (hint to ignore negative))
        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);
        res = max(res, root->val + leftMax + rightMax); // calculate subtree
        // improve now calculate the path if don't split
        return root->val + max(leftMax, rightMax);
    }
};
