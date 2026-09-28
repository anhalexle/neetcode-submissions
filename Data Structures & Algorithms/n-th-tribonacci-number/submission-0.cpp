class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n <= 2) return 1;
        vector<int> mem (n + 1, 0); // 0 -> n no compute
        return dp(n, mem);
    }
private:
    int dp(int n, vector<int>& mem)
    {
        if (n <= 1) return n;
        if (n <= 2) return 1;
        if (mem[n] != 0) return mem[n];
        // key
        mem[n] = dp(n - 1, mem) + dp(n - 2, mem) + dp (n - 3, mem);
        return mem[n];
    }
};