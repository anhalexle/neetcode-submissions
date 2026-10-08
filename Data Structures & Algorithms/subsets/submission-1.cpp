class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(0, tmp, res, nums);
        return res;
    }
private:
    void dfs(int index, vector<int>& tmp, vector<vector<int>>& res, vector<int>& nums)
    {
        res.push_back(tmp);
        for (int startIndex = index; startIndex < nums.size(); startIndex++)
        {
            tmp.push_back(nums[startIndex]);
            dfs(startIndex + 1, tmp, res, nums);
            tmp.pop_back();
        }
    }
};
