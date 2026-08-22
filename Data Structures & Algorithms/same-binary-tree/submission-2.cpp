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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || (p->val != q->val)) return false;

        // BFS
        // queue<TreeNode*> queue1;
        // queue<TreeNode*> queue2;
        // queue1.push(p);
        // queue2.push(q);
        // while(!queue1.empty() && !queue2.empty())
        // {
        //     int tempQueueSize = queue1.size();
        //     for (int i = 0; i < tempQueueSize; i++)
        //     {
        //         TreeNode* temp1 = queue1.front();
        //         TreeNode* temp2 = queue2.front();
        //         queue1.pop();
        //         queue2.pop();
        //         if (temp1->val != temp2->val) return false;
        //         if (temp1->left && temp2->left)
        //         {
        //             queue1.push(temp1->left);
        //             queue2.push(temp2->left);
        //         }
        //         else if(temp1->left || temp2->left)
        //         {
        //             return false;
        //         }
        //         if (temp1->right && temp2->right)
        //         {
        //             queue1.push(temp1->right);
        //             queue2.push(temp2->right);
        //         }
        //         else if(temp1->right || temp2->right)
        //         {
        //             return false;
        //         }
        //     }
        // }
        // return true;

        // DFS
        return (isSameTree(p->left, q->left) && (isSameTree(p->right, q->right)));
    }
};
