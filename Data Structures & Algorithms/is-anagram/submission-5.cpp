class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> myMap;

        if  (s.length() != t.length()) return false; 
        for (char c: s)
        {
            auto it = myMap.find(c);
            if (it != myMap.end())
            {
                it->second++;
            }
            else
            {
                myMap.insert({c,1});
            }
        }

        for (char c:t)
        {
            auto it = myMap.find(c);
            if (it != myMap.end())
            {
                if (it->second == 0) return false;
                it->second--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
