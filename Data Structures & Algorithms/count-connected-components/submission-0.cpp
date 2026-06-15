class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj_list(n);
        vector<bool> visited(n, false);
        int connected_count = 0;

        for (const auto& edge : edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cout << i << endl;
                traverse(i, adj_list, visited);
                connected_count++;
            }   
        }
        
        return connected_count;
    }

    void traverse(int node, vector<vector<int>>& adj_list, vector<bool>& visited)
    {
        if (visited[node]) return;

        visited[node] = true;
        
        for (const auto& neighbor : adj_list[node])
        {
            traverse(neighbor, adj_list, visited);
        }
    }
};
