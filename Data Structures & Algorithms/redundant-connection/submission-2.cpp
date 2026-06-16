class Solution {
public:
    vector<vector<int>> adj_list;
    vector<bool> visited;
    unordered_set<int> cycle;
    int cycleStart;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        adj_list.resize(n + 1);
        visited.resize(n+1, false);
        cycleStart = -1;

        for (const auto& edge : edges)
        {
            adj_list[edge[0]].emplace_back(edge[1]);
            adj_list[edge[1]].emplace_back(edge[0]);
        }

        traverse(1, -1);

        for (int i = edges.size() - 1; i >= 0; i--)
        {
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
            {
                return {edges[i][0], edges[i][1]};
            }
        }

        return {};
    }

    void traverse(int cur, int parent)
    {
        if (visited[cur])
        {
            cycleStart = cur;
            return;
        }

        visited[cur] = true;
        for (const auto& neighbor : adj_list[cur])
        {
            if (parent != neighbor)
            {
                traverse(neighbor, cur);
                if (cycleStart != -1)
                {
                    cycle.insert(cur);
                    if (cur == cycleStart)
                    {
                        cycleStart = -1;
                    }
                    return;
                }

            }
        }
    }
};
