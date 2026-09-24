class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        if (t.length() == 0) return res;
        int minimumLen = s.length() + 1;
        unordered_map<char,int> myMap;
        for (auto c: t)
        {
            myMap[c]++;
        }
        int l = 0;
        unordered_map<char,int> window;
        int formed = 0, required = myMap.size(), start = s.length();
        for (int r = 0; r < s.length(); r++)
        {
            if (myMap.count(s[r]))
            {
                window[s[r]]++;
                if (window[s[r]] == myMap[s[r]]) ++formed;
            }
            while (formed == required)
            {
                int length = r - l + 1;
                if (length < minimumLen)
                {
                    minimumLen = length;
                    start = l;
                    // res = s.substr(l, minimumLen);
                }
                if (myMap.count(s[l]))
                {
                    window[s[l]]--;
                    if (window[s[l]] < myMap[s[l]]) --formed;
                }
                l++;
            }
        }
        return (start == s.length()) ? "" : s.substr(start, minimumLen);
    }
};
