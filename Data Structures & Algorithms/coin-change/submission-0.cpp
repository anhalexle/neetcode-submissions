class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -1); // -1 computed yet
        int res = dp(coins, amount, memo);
        return res != INT_MAX ? res : -1; // INT_MAX: no value -> return -1 else return calculted
    }
private:
    int dp(vector<int>& coins, int amount, vector<int>& memo)
    {
        if (amount == 0) return 0;  // base case -> then we find a way just +1
        if (amount < 0) return INT_MAX;
        if (memo[amount] != -1) // computed
            return memo[amount];

        int minCoin = INT_MAX;
        for (int coin: coins)
        {
            int subProb = dp(coins, amount - coin, memo);
            if (subProb != INT_MAX) //solution found
            {
                minCoin = min(minCoin, subProb + 1); // dp[i] = 1 + dp(amount - coins[i])
            }
        }
        memo[amount] = minCoin;
        return minCoin;
    }
};
