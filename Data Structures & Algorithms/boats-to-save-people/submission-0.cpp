class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, h = people.size() - 1;
        int boat = 0;
        while (l <= h)
        {
            if (people[h] + people[l] > limit)
            {
                h--;
            }
            else
            {
                h--;
                l++;
            }
            boat++;
        }
        return boat;
    }
};