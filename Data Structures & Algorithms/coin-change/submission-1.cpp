class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // thing change is the amount not the coin
        vector<int> mem(amount + 1, -1);
        int res = dp(amount, coins, mem); 
        return res  == INT_MAX ? -1 : res;
    }
private:
    int dp(int amount, vector<int>& coins, vector<int>& mem)
    {
        if (amount == 0) return 0; // found a solution
        if (amount < 0) return INT_MAX; //not found a solution
        if (mem[amount] != -1) return mem[amount];
        int minCoin = INT_MAX;
        for (auto coin: coins)
        {
            int subDp = dp(amount - coin, coins, mem);
            if (subDp != INT_MAX) // a solution has been found
            {
                minCoin = min(minCoin, subDp + 1); // dp[i] = min(dp[i], 1 + dp[i+n]) with n: i + 1 -> coins.size - 1
            }
        }
        return mem[amount] = minCoin;
    }
};
