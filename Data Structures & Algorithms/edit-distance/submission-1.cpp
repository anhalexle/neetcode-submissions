class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> mem(word1.size(), vector<int>(word2.size(), -1)); // -1 not compute
        return dp(0, 0, word1, word2, mem);
    }
private:
    int dp (int index1, int index2, string& word1, string& word2, vector<vector<int>>& mem)
    {
        if (index1 == word1.size()) return word2.length() - index2; // total insert steps
        if (index2 == word2.size()) return word1.length() - index1; // total delete steps
        if (mem[index1][index2] != -1) return mem[index1][index2];
        int sum = 0;
        if (word1[index1] == word2[index2])
        {
            sum = dp(index1 + 1, index2 + 1, word1, word2, mem);
        }
        else
        {
            int insertStep = dp(index1, index2 + 1, word1, word2, mem);
            int delStep = dp(index1 + 1, index2, word1, word2, mem);
            int repStep = dp(index1 + 1, index2 + 1, word1, word2, mem);
            sum = 1 + min({insertStep, delStep, repStep});
        }
        return mem[index1][index2] = sum;
    }
};
