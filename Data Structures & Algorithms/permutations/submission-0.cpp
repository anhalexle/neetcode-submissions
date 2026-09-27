class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return {{}};

        vector<int> tmp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>>permutation = permute(tmp); // split [1,2,3] to [2,3]
        vector<vector<int>> res;

        for (auto p : permutation)
        {
            for (int i = 0; i <= p.size() /* with size p = 1 [3] -> insert [2,3] , insert[3,2] then need <= p.size() instead <*/; i++)
            {
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                res.push_back(p_copy);
            }
        }
        return res;
    }
};
