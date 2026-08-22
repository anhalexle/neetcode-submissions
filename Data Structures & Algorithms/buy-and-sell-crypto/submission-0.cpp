class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = left + 1;
        int max = 0;
        while (right < prices.size())
        {
            if (prices[left] >= prices[right])
            {
                left = right;
                right++;
                continue;
            }
            int curProfit = prices[right] - prices[left];
            max = curProfit > max ? curProfit : max;
            right++;
        }
        return max;
    }
};
