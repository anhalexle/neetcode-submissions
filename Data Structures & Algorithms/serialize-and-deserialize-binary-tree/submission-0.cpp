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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> myArr;
        dfsSerialize(root, myArr);
        string res = "";
        for (auto subStr : myArr)
        {
            res += subStr + ",";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> splitArr;
        int i = 0;
        int initial = 0;
        while (i < data.length())
        {
            if (data[i] == ',')
            {
                splitArr.push_back(data.substr(initial,i - initial));
                initial = i + 1;
            }
            i++;
        }
        int index = 0;
        return dfsDesirialize(splitArr, index);
    }
private:
    void dfsSerialize(TreeNode* root, vector<string> &res)
    {
        if (root == nullptr)
        {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    TreeNode* dfsDesirialize(vector<string>& res, int &index)
    {
        if (res[index] == "N")
        {
            index++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(res[index]));
        index++;
        node->left = dfsDesirialize(res, index);
        node->right = dfsDesirialize(res, index);
        return node;
    }
};
