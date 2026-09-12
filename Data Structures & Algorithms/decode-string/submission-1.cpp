class Solution {
public:
    string decodeString(string s) {
        stack<string> myStack;
        int index = 0;
        while (index < s.length())
        {
            if (s[index] != ']')
            {
                myStack.push(string(1, s[index]));
            }
            else
            {
                string subStr = "";
                while (!myStack.empty() && myStack.top()[0] != '[')
                {
                    string tempStr = myStack.top();
                    myStack.pop();
                    subStr += tempStr;
                }
                // pop "["
                myStack.pop();
                // now get the number
                string lengthStr = "";
                while (!myStack.empty() && isdigit(myStack.top()[0]))
                {
                    string tempNum = myStack.top();
                    myStack.pop();
                    lengthStr += tempNum ;
                }
                reverse(lengthStr.begin(), lengthStr.end());
                int length = stoi(lengthStr);
                while (length > 0)
                {
                    myStack.push(subStr);
                    length--;
                }
            }
            index++;
        }

        // now convert stack subStr to full Str
        string res = "";
        while (!myStack.empty())
        {
            res += myStack.top();
            myStack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};