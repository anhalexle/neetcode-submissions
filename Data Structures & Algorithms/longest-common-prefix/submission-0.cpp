class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string firstStr = strs[0];
        for (int i = 0; i < strs[0].length(); i++)
        {
            for (auto str : strs)
            {
                if (i == str.length() || str[i] != strs[0][i]) return firstStr.substr(0, i);
            }
        }
        return firstStr;
    }
};