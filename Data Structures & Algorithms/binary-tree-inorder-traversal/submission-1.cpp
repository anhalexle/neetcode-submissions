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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalRec(root, res);
        return res;
    }
private:
    void inorderTraversalRec(TreeNode* root, vector<int>& dfs)
    {
        if (root == nullptr) return;
        inorderTraversalRec(root->left, dfs);
        dfs.push_back(root->val);
        inorderTraversalRec(root->right,dfs);
    }
};