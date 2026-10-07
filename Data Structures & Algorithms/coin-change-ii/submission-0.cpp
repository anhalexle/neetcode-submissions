class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> mem(amount + 1, vector<int>(coins.size() + 1, -1)); // no compute yet
        return dp(amount /*capacity*/, coins.size() /*items*/, coins, mem); // truyen max amount and max items thi cai mem can phai chua du ở index là max amount và max items
        // Time: O(amount*coins)
        // Space: O(amount*coins)
    }
private:
    // state change amount *items
    int dp (int amount, int items, vector<int>& coins, vector<vector<int>>& mem)
    {
        if (amount == 0) return 1; // base case we have found a valid combinations
        if (items == 0) return 0; // have no coin to choose left
        // work in here has a look up so O(1)
        if (mem[amount][items] != -1) return mem[amount][items];

        int result = 0;
        int notPick = dp(amount, items - 1, coins, mem);
        result += notPick;
        if (coins[items - 1] <= amount)
        {
            int pick = dp(amount - coins[items - 1], items, coins, mem); // unlimited coin
            result += pick; 
        }
        return mem[amount][items] = result;
    }
};
