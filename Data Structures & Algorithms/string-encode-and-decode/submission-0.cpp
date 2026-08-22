class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++)
        {
            res += to_string(strs[i].length()) + "#" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length())
        {
            int j = i;
            while (s[j] != '#')
                j++;
            string number;
            while (i <= j)
            {
                number += s[i];
                i++;
            }
            int length = stoi(number);
            string dummyVal = "";
            for (int temp = j + 1; temp < j + 1 + length; temp++)
            {
                dummyVal += s[temp]; 
            }
            res.push_back(dummyVal);
            i = j + 1 + length;
        }
        return res;
    }
};
