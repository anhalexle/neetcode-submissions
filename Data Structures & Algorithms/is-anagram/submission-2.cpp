class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() == 0 || t.length() == 0) 
            return true;
        if (s.length() != t.length())
            return false;
        map<char, int> mymap;
        for (int i = 0; i < s.length(); i++)
        {
            mymap[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (mymap.find(t[i]) == mymap.end() || mymap[t[i]] == 0)
                return false;
            mymap[t[i]]--;
        }
        map<char,int>::iterator itr;
        for (itr = mymap.begin(); itr != mymap.end(); ++itr)
        {
            if (itr->second != 0)
                return false;
        }
        return true;
    }
};
