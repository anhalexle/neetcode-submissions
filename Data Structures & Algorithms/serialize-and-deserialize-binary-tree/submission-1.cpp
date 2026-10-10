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
        vector<string> joinArr;
        dfsSerialize(root, joinArr); // preorder: root, left, right
        string res = "";
        for (auto arr : joinArr)
        {
            res += arr + ",";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> splitArr;
        int i = 0;
        while (i < data.length())
        {
            int j = i;
            while (data[j] != ',')
            {
                j++;
            }
            splitArr.push_back(data.substr(i, j - i));
            i = ++j; // char non ','
        }
        int startIndex = 0;
        return dfsDeserialize(splitArr, startIndex);
    }
private:
    void dfsSerialize(TreeNode* root, vector<string>& joinArr)
    {
        if (root == nullptr)
        {
            joinArr.push_back("N");
            return;
        }
        joinArr.push_back(to_string(root->val)); //root
        dfsSerialize(root->left, joinArr);
        dfsSerialize(root->right, joinArr);
    }
    TreeNode* dfsDeserialize(vector<string>& splitArr, int& index)
    {
        if (splitArr[index] == "N")
        {
            index++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(splitArr[index]));
        index++;
        root->left = dfsDeserialize(splitArr, index);
        root->right = dfsDeserialize(splitArr, index);
        return root;
    }

};
