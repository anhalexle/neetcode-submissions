class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2) return false; 
        map<char,char> validParentheses = {{'{', 
         '}'}, {'[', ']'}, {'(', ')'}};
        vector<char> checkString;
        for (int i = 0; i < s.size(); i++)
        {
            if (checkString.size() == 0)
            {
                if (!validParentheses[s[i]]) return false;
                checkString.push_back(s[i]);
                continue;
            }
            if (validParentheses[s[i]])
            {
                checkString.push_back(s[i]);
                continue;
            }
            if (validParentheses[checkString[checkString.size() - 1]] != s[i]) return false;
            checkString.pop_back();
        }
        if (checkString.size() != 0) return false;
        return true;
    }
};
