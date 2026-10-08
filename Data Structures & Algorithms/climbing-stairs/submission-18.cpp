class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem(n + 1, -1);
        return dp(n, mem);
    }
private:
    int dp (int n, vector<int>& mem)
    {
        if (n <= 2) return n; // 0 -> 0, 1-> 1, 2->2
        if (mem[n] != -1) return mem[n];
        return mem[n] = dp(n - 2, mem) + dp(n - 1, mem);
    }
};
