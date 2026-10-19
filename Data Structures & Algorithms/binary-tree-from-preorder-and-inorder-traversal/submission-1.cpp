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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // first half [first, half)
        // Base case
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        // built root
        TreeNode* root = new TreeNode(preorder[0]);
        // find mid for split
        auto m = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin() /*pointer arithmetic*/;
        // split leftpre [1, m(inorder) + 1) -> first: 1, half: m(inorder) + 1
        // pre[1,2,3,4], in[2,1,3,4] -> leftpre[2], leftin[2]
        vector<int> leftpre = vector(preorder.begin() + 1 /*first*/, /*half*/preorder.begin() + m + 1);
        vector<int> leftin = vector(inorder.begin(), inorder.begin()+m);
        root->left = buildTree(leftpre, leftin);
        // rightpre[3,4] rightin[3,4]
        vector<int> rightpre = vector(preorder.begin() + m + 1, preorder.end());
        vector<int> rightin = vector(inorder.begin() + m + 1, inorder.end()); //attention
        root->right = buildTree(rightpre, rightin);
        return root;
    }
    // T:O(n^2) //search from the left to n and from n ->right for every element
    // S: O(n) // depth of recursion
};
