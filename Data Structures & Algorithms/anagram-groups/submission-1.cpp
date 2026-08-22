class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> myMap;

        for (string str :strs)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            myMap[sortedStr].push_back(str);
        }

        vector<vector<string>> res;
        map<string,vector<string>>::iterator it;
        for (it = myMap.begin(); it != myMap.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
