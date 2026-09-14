class Solution {
public:
    string simplifyPath(string path) {
        stack<string> myStack;
        int index = 0;
        while (index < path.length())
        {
            if (myStack.empty())
            {
                myStack.push("/");
                ++index;
                continue;
            }
            if (path[index] == '/')
            {
                if (myStack.top()[0] != '/')
                {
                    myStack.push("/");
                }
                ++index;
                continue;
            }
            if (path[index] == '.')
            {
                int curDot = 1;
                int tempIndex = index + 1;
                while (tempIndex < path.length() && path[tempIndex] == '.')
                {
                    curDot++;
                    tempIndex++;
                }
                bool specialCase = false;
                switch (curDot)
                {
                    case 1:
                        if (tempIndex < path.length() && path[tempIndex] != '/')
                        {
                            specialCase = true;
                        }
                        break;
                    case 2:
                        if (tempIndex < path.length() && path[tempIndex] != '/')
                        {
                            specialCase = true;
                        }
                        if (myStack.size() != 1 && !specialCase)
                        {
                            myStack.pop(); // "/"
                            myStack.pop(); // dirName
                        }
                        break;
                    default:
                        string fileName = path.substr(index, curDot);
                        myStack.push(fileName);
                        break;
                }
                if (!specialCase)
                {
                    index = tempIndex;
                    continue;
                }
            }
            int dirNameLength = 1;
            int tempIndex = index + 1;
            while (tempIndex < path.length() && path[tempIndex] != '/')
            {
                dirNameLength++;
                tempIndex++;
            }
            string fileName = path.substr(index, dirNameLength);
            myStack.push(fileName);
            index = tempIndex;
            continue;
        }
        if (myStack.top()[0] == '/' && myStack.size() != 1)
        {
            myStack.pop();
        }
        vector<string> myVector;
        string res;
        while (!myStack.empty())
        {
            myVector.push_back(myStack.top());
            myStack.pop();
        }
        for (int i = myVector.size() - 1; i >= 0; i--)
        {
            res += myVector[i];
        }
        return res;
    }

    
};