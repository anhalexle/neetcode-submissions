class Solution {
public:
    string longestPalindrome(string s) {
        // T:O(n)
        // S:O(1)
        int startIndex = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int evenOrOdd = max(expand(i, i, s), expand(i, i + 1,s));
            if (evenOrOdd > maxLen)
            {
                startIndex = i - ((evenOrOdd - 1) /2);// must (len - 1)/2 for both odd and length case
                maxLen = evenOrOdd; 
            }
        }
        return s.substr(startIndex, maxLen);
    }
private:
    int expand(int left, int right, string& s)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1; // len
    }
};
