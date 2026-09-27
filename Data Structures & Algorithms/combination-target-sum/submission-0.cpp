class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        int total = 0;
        dfs(nums, target, 0, cur, total);
        return res;
    }
private:
    void dfs(vector<int>&nums, int target, int index, vector<int>& cur, int total)
    {
        if (total == target)
        {
            res.push_back(cur);
            return;
        }
        if (index >= nums.size() || total > target)
        {
            return;
        }
        cur.push_back(nums[index]);
        dfs(nums, target, index, cur, total + nums[index]);
        cur.pop_back(); // make another decision
        dfs(nums, target, index + 1 /*not choose same number anymore*/,cur, total);
    }
};
