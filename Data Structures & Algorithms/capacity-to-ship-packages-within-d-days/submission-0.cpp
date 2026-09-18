class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0;
        for (auto weight : weights)
        {
            r += weight;
        }
        int minWeight = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int ship = 1;
            int curCapacity = m;
            for (auto weight : weights)
            {
                if (curCapacity - weight < 0)
                {
                    ++ship;
                    curCapacity = m;
                }
                curCapacity -= weight;
            }
            if (ship <= days)
            {
                minWeight = (minWeight == 0) ? m : min(minWeight, m);
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return minWeight;
    }
};