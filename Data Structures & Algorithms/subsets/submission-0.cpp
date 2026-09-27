class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        set<vector<int>> mySet;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> subSet;
            backTracking(i, nums, mySet, subSet);
        }
        for (auto it : mySet)
        {
            res.push_back(it);
        }
        return res;
    }
private:
    void backTracking(int i, vector<int>& nums, set<vector<int>>&mySet, vector<int>& subSet)
    {
        subSet.push_back(nums[i]);
        mySet.insert(subSet);   // set already dedupes, no need for count() check

        for (int next = i + 1; next < nums.size(); next++)
        {
            backTracking(next, nums, mySet, subSet);
        }

        subSet.pop_back();   // <-- undo the choice before returning to the caller
    }
};
