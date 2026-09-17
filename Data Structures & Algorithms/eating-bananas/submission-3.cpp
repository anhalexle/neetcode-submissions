class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int maxPile = piles.back();
        int l = 1;
        int r = maxPile;
        int min = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            unsigned long long totalTime = 0;
            for (auto pile : piles)
            {
                totalTime += (unsigned long long) pile / m + (pile % m ? 1 : 0);
            }
            if (totalTime <= h)
            {
                min = (min == 0 ? m : std::min(min, m));
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return min;
    }
};
