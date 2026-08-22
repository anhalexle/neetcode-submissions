class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return (isPalindrom(s.substr(0,left) + s.substr(left + 1)) || (isPalindrom(s.substr(0,right) + s.substr(right + 1))));
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalindrom(string s)
    {
        int left = 0, right = s.length() - 1;
        while(left < right)
        {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};