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
        stack<TreeNode*> myStack;
        // iterator
        TreeNode* cur = root;
        while(cur || !myStack.empty())
        {
            if (cur)
            {
                res.push_back(cur->val);
                myStack.push(cur->right);
                cur = cur->left;
            }
            else
            {
                cur = myStack.top();
                myStack.pop();
            }
        }
        return res;
    }
};