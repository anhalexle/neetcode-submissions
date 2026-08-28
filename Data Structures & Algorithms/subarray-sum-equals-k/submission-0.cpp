class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> myMap;
        myMap[0] = 1;
        int res = 0;
        int curSum = 0;
        for (auto num : nums)
        {
            curSum += num;
            int diff = curSum - k;
            res += myMap[diff]; // return 0 if diff is unknown key
            ++myMap[curSum];
        }
        return res;
    }
};