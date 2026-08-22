class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (!alphaNum(s[left]))
            {
                left++;
                continue;
            }
            if (!alphaNum(s[right]))
            {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }

    bool alphaNum(char c)
    {
        return (c >= 'A' && c <= 'Z') || 
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9');
    }
};
