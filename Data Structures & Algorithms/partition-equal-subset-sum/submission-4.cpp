class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int amount = sum / 2;
        vector<vector<int>> mem(amount + 1, vector<int>(nums.size() + 1, -1));

        return dp(amount, nums.size(), nums, mem) == INT_MAX ? false: true;
    }
private:
    int dp(int amount, int index, vector<int>& nums, vector<vector<int>>& mem)
    {
        if (amount == 0) return 1;
        if (index == 0) return INT_MAX;
        if (mem[amount][index] != -1) return mem[amount][index];
        int res = INT_MAX;
        // not pick
        res = dp(amount, index - 1, nums, mem);
        if (res == INT_MAX && nums[index - 1] <= amount)
        {
            // pick
            res = dp(amount - nums[index - 1], index - 1, nums, mem);
        }
        return mem[amount][index] = res;
    }
};
