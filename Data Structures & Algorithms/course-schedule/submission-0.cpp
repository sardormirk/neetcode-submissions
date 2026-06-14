class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*

        if you want to take course X, that has a, b, c pre requisites

        a -> X
        b -> X
        c -> X

        check if a cycle exists in the graph, and if not, then its possible to take every course
        */

        vector<vector<int>> adj_list(numCourses);
        vector<int> course_path(numCourses);

        for (const auto pre_req : prerequisites)
        {
            adj_list[pre_req[0]].push_back(pre_req[1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!traverse(i, adj_list, course_path))
            {
                return false;
            }
        }

        return true;
    }

    bool traverse(int course, vector<vector<int>>& adj_list, vector<int>& course_path)
    {
        if (course_path[course] == 1)
            return false;

        course_path[course] = 1;

        if (course_path[course] == 2) // path from course 2 down reveals no cycles
            return true;
        
        for (const auto& course : adj_list[course])
        {
            if (!traverse(course, adj_list, course_path))
            {
                return false;
            }
        }

        course_path[course] = 2;
        return true;
    }
};
