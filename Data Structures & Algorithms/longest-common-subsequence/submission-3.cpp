class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mem(text1.length(), vector<int>(text2.length(), -1)); // not compute
        return dp(0, 0, text1, text2, mem);
    }
private:
    int dp(int index1, int index2, string& text1, string& text2, vector<vector<int>>& mem)
    {
        if (index1 == text1.length() || index2 == text2.length()) return 0;
        if (mem[index1][index2] != -1) return mem[index1][index2];
        int res = 0;
        if (text1[index1] == text2[index2])
        {
            res = 1 + dp(index1 + 1, index2  +1, text1, text2, mem);
        }
        else
        {
            int goWithText1 = dp(index1 + 1, index2, text1, text2, mem);
            int goWithText2 = dp(index1, index2 + 1, text1, text2, mem);
            res = max(goWithText1, goWithText2);
        }
        return mem[index1][index2] = res;
    }
};
