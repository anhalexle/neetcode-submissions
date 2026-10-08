class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> mem(nums.size(), -1); //not compute
        int maxProfit = 0;
        vector<int> tmp1 = vector<int>(nums.begin(), nums.end() - 1); // left one house begining (vì đầu và cuối tính 1 nhà)
        vector<int> tmp2 = vector<int>(nums.begin() + 1, nums.end()); // left one house end (vì đầu và cuối tính 1 nhà)
        for (int i = 0; i < tmp1.size(); i++)
        {
            maxProfit = max(maxProfit, dp(i, tmp1, mem));
        }
        // reset mem
        mem.assign(nums.size(), -1);
        for (int i = 0; i < tmp2.size(); i++)
        {
            maxProfit = max(maxProfit, dp(i, tmp2, mem));
        }
        return maxProfit;
    }
private:
    int dp(int index, vector<int>& nums, vector<int>& mem)
    {
        if (index >= nums.size()) return 0;
        if (mem[index] != -1) return mem[index];
        int res = max(dp(index + 1, nums, mem), nums[index] + dp(index + 2, nums, mem));
        return mem[index] = res;
    }
};
