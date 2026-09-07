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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> myStack;
        stack<bool> visit;
        myStack.push(root);
        visit.push(false);
        while (!myStack.empty())
        {
            TreeNode* cur = myStack.top();
            bool visited = visit.top();
            myStack.pop();
            visit.pop();
            if (cur)
            {
                if (visited)
                {
                    res.push_back(cur->val);
                }
                else
                {
                    // push back now but with visited value
                    myStack.push(cur);
                    visit.push(true);
                    // push right first so left will be handle first as LIFO
                    myStack.push(cur->right);
                    visit.push(false); // not visted yet
                    myStack.push(cur->left);
                    visit.push(false);
                }
            }
        }
        return res;
    }
};