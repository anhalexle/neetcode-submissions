class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> myMap;
        for (auto c1 : s1)
        {
            myMap[c1]++;
        }
        int l = 0;
        while (l < s2.length())
        {
            if (myMap.count(s2[l]) == 0)
            {
                l++;
                continue;
            }
            int r = l;
            map<char, int> tempMap = myMap;
            bool inValid = false;
            while (r < l + (int)s1.length()) 
            {
                if (tempMap.count(s2[r]) == 0 || tempMap[s2[r]] == 0)
                {
                    inValid = true;
                    break;
                }
                tempMap[s2[r]]--;
                r++;
            }
            if (!inValid)
                return true;
            else
            {
                l++;
            }
        }
        return false;
    }
};
