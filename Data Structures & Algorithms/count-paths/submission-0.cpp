class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, -1));
        int count = dp(0, 0, m, n, mem);
        return count;
    }
private:
    int dp(int curM, int curN, int m, int n, vector<vector<int>>& mem)
    {
        if (curM == m-1 && curN == n -1) return 1;
        if (curM >= m || curN >= n) return 0; //outbound
        if (mem[curM][curN] != -1) return mem[curM][curN];

        int count = dp(curM + 1, curN, m, n, mem) + dp(curM, curN + 1, m, n, mem);
        mem[curM][curN] = count;
        return count;
    }
};
