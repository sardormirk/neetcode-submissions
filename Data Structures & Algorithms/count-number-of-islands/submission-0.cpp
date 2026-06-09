class Solution {
public:

    vector<pair<int, int>> directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int numGroups = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    numGroups++;
                }
            }
        }

        return numGroups;
        
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
            return;
        
        grid[r][c] = '0';
        for (int i = 0; i < directions.size(); i++)
        {
            dfs(grid, r + directions[i].first, c + directions[i].second);
        }
    }
};