class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // initialized a map        
        unordered_map<int, vector<int>> myMap;
        // fill the prerequisite
        for (auto prerequisite : prerequisites)
        {
            myMap[prerequisite[0]].push_back(prerequisite[1]);
        }
        set<int> visitedCourse;
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(myMap, i, visitedCourse)) return false;
        }
        return true;
    }
private:
    bool dfs(unordered_map<int, vector<int>>& myMap, int course, set<int>& visited)
    {
        if (visited.count(course)) return false; // detect loop
        if (myMap[course].size() == 0) return true; // course can be completed
        visited.insert(course);

        for (auto pre : myMap[course])
        {
            if (!dfs(myMap, pre, visited)) return false;
        }
        visited.erase(course);
        myMap[course] = {}; // marked the course as completed
        return true;
    }
};
