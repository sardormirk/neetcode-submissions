class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        using dist_pairs = tuple<double, int, int>;
        priority_queue<dist_pairs, vector<dist_pairs>> kClosest;
        vector<vector<int>> res;
        
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0], y = points[i][1];

            kClosest.emplace(sqrt(x * x + y * y), x, y);
            if (kClosest.size() > k)
            {
                kClosest.pop();
            }

        }

        while (!kClosest.empty())
        {
            auto [dist, x, y] = kClosest.top(); kClosest.pop();
            res.push_back({x, y});
        }

        return res;

    }
};
