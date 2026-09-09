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
        // vector<int> temp(nums.size(), 0);
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int swapIndex = 0;
        //     if (i + k < nums.size())
        //     {
        //         swapIndex = i + k;
        //     }
        //     else
        //     {
        //         swapIndex = (i + k) % nums.size();
        //     }
        //     temp[swapIndex] = nums[i];
        // }

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     nums[i] = temp[i];
        // }
        // Reverse Array first
        int l = 0, r = nums.size() - 1;
        k = k % nums.size();
        if (k < 0) k += nums.size(); // defensive, in case k could ever be negative
        while (l <= r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        // swap first portion
        l = 0;
        r = k -1;
        while (l <= r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        // swap other portion
        l = k;
        r = nums.size() - 1;
        while (l <= r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--; 
        }
        
    }
};