class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> post(nums.size(), 1);
        for (int i = 1; i < pre.size(); i++)
        {
            pre[i] = pre[i - 1]* nums[i - 1];
        }
        for (int i = post.size() - 2; i >= 0; i--)
        {
            post[i] = post[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < post.size(); i++)
        {
            post[i] *= pre[i];
        }
        return post;
    }
};
