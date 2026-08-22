class Solution {
public:
    string specialChar = "#";
    string encode(vector<string>& strs) {
        string res = "";
        for (string str: strs)
        {
            res += to_string(str.length()) + specialChar + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while (i < s.length())
        {
            int j = i;
            while (s[j] != '#')
                j++;

            string dummyString = "";
            string number;
            while (i <= j)
            {
                number += s[i];
                i++;
            }         
            int length = stoi(number);
            for (int temp = j + 1; temp < j + 1 + length; temp++)
            {
                dummyString += s[temp];
            }
            res.push_back(dummyString);
            i = j + 1 + length;
        }
        return res;
    }
};
