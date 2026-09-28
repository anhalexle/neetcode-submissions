class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> mem (n + 1, 0); // n + 1 means from 0 to n with 0: no computed yet
        return dp(n, mem);
    }
private:
    int dp(int n, vector<int>& mem)
    {
        if (n <= 2) return n; // 0: 0, 1: 1, 2:2
        if (mem[n] != 0) return mem[n]; // no need to resolved

        mem[n] = dp(n - 1, mem) + dp(n - 2, mem);
        return mem[n];
    }
};
