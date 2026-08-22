class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preFix (nums.size(), 1);
        vector<int> postFix (nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            preFix[i] = preFix[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            postFix[i] = postFix[i + 1] * nums[i + 1];
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(preFix[i] * postFix[i]);
        }
        return res;
    }
};
