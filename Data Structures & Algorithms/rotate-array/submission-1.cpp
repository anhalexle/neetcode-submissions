class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int lastIndex = nums.size() - 1;
        // while (k != 0)
        // {
        //     for (int i = 0; i < nums.size() - 1; i++)
        //     {
        //         int temp = nums[i];
        //         nums[i] = nums[lastIndex];
        //         nums[lastIndex] = temp;
        //     }
        //     k--;
        // }
        vector<int> temp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int swapIndex = 0;
            if (i + k < nums.size())
            {
                swapIndex = i + k;
            }
            else
            {
                swapIndex = (i + k) % nums.size();
            }
            temp[swapIndex] = nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = temp[i];
        }
    }
};