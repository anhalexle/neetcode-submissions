class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            res.push_back(countOne(i));
        }
        return res;
    }
    int countOne(int n)
    {
        int res = 0;
        while(n)
        {
            n &= n -1;
            res++;
        }
        return res;
    }
};
