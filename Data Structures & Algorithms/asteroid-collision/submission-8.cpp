class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto asteroid: asteroids)
        {
            bool alive = true;
            while (alive && !res.empty() && res.back() > 0 && asteroid < 0)
            {
                if (res.back() < -asteroid)
                {
                    res.pop_back();
                    continue;
                }
                if (res.back() == -asteroid)
                    res.pop_back();
                alive = false;
            }
            if (alive) res.push_back(asteroid);
        }
        return res;
    }
};