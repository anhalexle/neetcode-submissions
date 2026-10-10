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
    bool isValidBST(TreeNode* root) {
        // T: O(n) skewed, O(logn): balance
        // S: O(n)
        stack<TreeNode*> myStack;
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        // inorder
        while (cur || !myStack.empty())
        {
            while (cur)
            {
                myStack.push(cur);
                cur = cur->left; // go left most
            }
            TreeNode* top = myStack.top();
            myStack.pop();
            if (prev && prev->val >= top->val) return false;
            prev = top;
            cur = top->right;
        }
        return true;
    }
};
