class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        set<int> mySet;
        vector<int> temp;
        for (auto num : nums)
        {
            temp.push_back(num);
            mySet.insert(num);
            dfs(temp, mySet, nums, res);
            mySet.erase(num);
            temp.pop_back();
        }
        return res;
    }
private:
    void dfs(vector<int>& temp, set<int>& mySet, vector<int>& nums, vector<vector<int>>& res)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for (auto num: nums)
        {
            if (mySet.count(num) == 0)
            {
                mySet.insert(num);
                temp.push_back(num);
                dfs(temp, mySet, nums, res);
                mySet.erase(num);
                temp.pop_back();
            }
        }
    }
};
