class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> myvector;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++)
        {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            myvector[sortedStr].push_back(strs[i]);
        }
        for (map <string, vector<string>>::iterator itr = myvector.begin(); itr != myvector.end(); itr++)
        {
            result.push_back(itr->second);
        }
        return result;
    }
};
