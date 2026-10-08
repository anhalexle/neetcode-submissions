class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false); // store used index
        vector<int> temp;
        dfs(temp, used, nums, res);
        return res;
        // Time: n: nums.size -> O(n^n)
        // Space: O(n)
    }
private:
    void dfs(vector<int>& temp, vector<bool>& used, vector<int>& nums, vector<vector<int>>& res)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(used[i]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            dfs(temp,used, nums,res);
            temp.pop_back();
            used[i] = false;
        }
    }
};
