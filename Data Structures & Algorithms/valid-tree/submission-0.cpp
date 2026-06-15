class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        vector<int> state(n);

        for (const auto& edge : edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        if (!dfs(0, -1, adj_list, state))
            return false;
        
        for (const auto& state : state)
        {
            if (state != 2) return false;
        }

        return true;
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj_list, vector<int>& state)
    {
        if (state[node] == 1) return false;

        if (state[node] == 2) return true;

        state[node] = 1;
        for (const auto& neighbor : adj_list[node])
        {   
            if (neighbor == parent) continue;
            
            if (!dfs(neighbor, node, adj_list, state))
                return false;
        }
        state[node] = 2;

        return true;
    }
};
