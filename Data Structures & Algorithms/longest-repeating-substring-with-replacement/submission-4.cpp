class Solution {
public:
    int characterReplacement(string s, int k) {
        // length - maxF <= k 
        int l = 0;
        int maxFreq = 0;
        int res = 0;
        map<char,int> myMap;
        for (int r = 0; r < s.length(); r++)
        {
            myMap[s[r]]++;
            maxFreq = max(myMap[s[r]], maxFreq);
            while ((r - l + 1 - maxFreq > k) && (l < s.length()))
            {
                myMap[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};