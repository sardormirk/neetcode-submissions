class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int ROWS = static_cast<int>(grid.size()), COLS = static_cast<int>(grid[0].size());

        int maxArea = 0, currentArea = 0;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                {
                    currentArea = 0;
                    dfs(grid, i, j, currentArea);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }

    void dfs(vector<vector<int>> &grid, int r, int c, int &currentArea)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
            return;

        currentArea++;
        grid[r][c] = 0;

        for (int i = 0; i < 4; i++)
        {
            dfs(grid, r + directions[i].first, c + directions[i].second, currentArea);
        }
    }
};
