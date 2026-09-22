class TimeMap {
public:
    map<string, vector<pair<string, int>>> myMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        const auto& myVector = myMap[key];
        int l = 0;
        int r = myVector.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) /2;
            if (myVector[m].second <= timestamp)
            {
                res = myVector[m].first;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return res;
    }
};
