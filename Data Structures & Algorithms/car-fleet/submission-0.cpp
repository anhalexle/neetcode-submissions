class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> carFleet;
        vector<pair<int,int>> posAndSpeed;
        for (int i = 0; i < position.size(); i++)
        {
            posAndSpeed.push_back({position[i], speed[i]});
        }
        // Sort based on position
        sort(posAndSpeed.begin(), posAndSpeed.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first < b.first;
        });

        for (int i = position.size() - 1; i >= 0; i--)
        {
            float time = (float)(target - posAndSpeed[i].first) / posAndSpeed[i].second;
            if (carFleet.empty() || time > carFleet.top())
            {
                carFleet.push(time);
            }
        }
        return carFleet.size();
    }
};
