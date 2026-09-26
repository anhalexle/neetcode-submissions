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
        // inorder
        stack<int> checkArr;
        stack<TreeNode*> myStack;
        TreeNode* cur = root;
        while (cur != nullptr || !myStack.empty())
        {
            while (cur)
            {
                myStack.push(cur);
                cur = cur->left;
            }
            cur = myStack.top();
            if (!checkArr.empty() && (checkArr.top() >= cur->val))
            {
                return false;
            }
            checkArr.push(cur->val);
            cur = cur->right;
            myStack.pop();
        }
        return true;
    }
};
