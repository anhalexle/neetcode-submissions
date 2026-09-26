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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversalRec(root, res);
        return res;
    }
private:
    void preorderTraversalRec(TreeNode* root, vector<int>&dfs)
    {
        if (root == nullptr) return;
        dfs.push_back(root->val);
        preorderTraversalRec(root->left, dfs);
        preorderTraversalRec(root->right, dfs);
    }
};