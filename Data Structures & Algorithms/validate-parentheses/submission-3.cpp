class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        stack<char> st;
        for (char c : s) {
            // If it's a closing bracket
            if (pairs.count(c)) {
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();
            } else {
                // It's an opening bracket
                st.push(c);
            }
        }
        return st.empty();
    }
};
