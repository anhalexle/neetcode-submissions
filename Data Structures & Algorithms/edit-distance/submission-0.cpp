class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> mem (word1.length(), vector<int>(word2.length(), -1)); // not computed yet
        return dp(0, 0, word1, word2, mem);
    }
private:
    int dp(int i, int j, string& word1, string& word2, vector<vector<int>>& mem)
    {
        if (i == word1.length()) return word2.length() - j; // insert all elements left in word2
        if (j == word2.length()) return word1.length() - i; // delete all elements left in word1
        if (mem[i][j] != -1) return mem[i][j];
        int res = 0;
        if (word1[i] == word2[j])
        {
            res = dp (i + 1, j + 1, word1, word2, mem);
        }
        else
        {
            int ins = dp(i, j + 1, word1, word2, mem);
            int del = dp(i + 1, j, word1, word2, mem);
            int rep = dp(i + 1, j + 1, word1, word2, mem);
            res = 1 + min({ins, del, rep}); // 1: we have already done one step
        }
        return mem[i][j] = res;
    }
};
