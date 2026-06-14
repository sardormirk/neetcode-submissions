class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<int> path(numCourses);
        vector<int> result;

        for (const auto& pre_reqs : prerequisites)
        {
            adj_list[pre_reqs[0]].push_back(pre_reqs[1]);
        }

        for (int course = 0; course < numCourses; course++)
        {
            if (!traverse(course, adj_list, result, path))
            {
                return {};
            }
        }
        return result;
    }

    bool traverse(int c, vector<vector<int>>& adj_list, vector<int>& result, vector<int>& path)
    {
        if (path[c] == 1)
        {
            return false;
        }

        if (path[c] == 2)
        {
            return true;
        }

        path[c] = 1;
        
        for (const auto& next : adj_list[c])
        {
            if (!traverse(next, adj_list, result, path))
                return false;
        }

        path[c] = 2;
        result.push_back(c);
        return true;
    }
};
