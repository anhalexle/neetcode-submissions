class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> mySet;
        int l = 0;
        int res = 0;
        for (int r = 0; r < s.length(); r++)
        {
            while(mySet.contains(s[r]))
            {
                mySet.erase(s[l]);
                ++l;
            }
            mySet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
