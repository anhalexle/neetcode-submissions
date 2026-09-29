class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> visited (text1.length(), vector<int>(text2.length(), -1)); // -1 no visit
        return dp(0, 0, text1, text2, visited);
    }
private:
    int dp(int i, int j, string text1, string text2, vector<vector<int>>& mem)
    {
        if (i == text1.length() || j == text2.length()) return 0; // base case outbound
        if (mem[i][j] != -1) return mem[i][j];
        int count;
        if (text1[i] == text2[j])
        {
            count = 1 + dp(i + 1, j + 1, text1, text2, mem);
        }
        else
        {
            count = max(dp(i + 1, j, text1, text2, mem), dp(i, j + 1, text1, text2, mem));
        }
        mem[i][j] = count;
        return count;
    }
};
