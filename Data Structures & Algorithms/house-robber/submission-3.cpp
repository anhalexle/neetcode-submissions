class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res = max(res, dp(i, nums, mem));
        }
        return res;
    }
private:
    int dp(int index, vector<int>& nums, vector<int>& mem)
    {
        if (index >= nums.size()) return 0; // no more house
        if (mem[index] != -1) return mem[index];

        int res = max(dp(index + 1, nums, mem), nums[index] + dp(index + 2, nums, mem)); // no rob vs value of rob house + next two house
        return mem[index] = res;
    }
};
