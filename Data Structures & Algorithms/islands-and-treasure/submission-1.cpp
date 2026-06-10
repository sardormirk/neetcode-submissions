class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int ROWS = static_cast<int>(grid.size());
        const int COLS = static_cast<int>(grid[0].size());

        vector<vector<bool>> visited (ROWS, vector<bool>(COLS, false));
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 0)
                {   
                    q.emplace(i, j, 0);
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty())
        {
            auto [r, c, dist] = q.front(); q.pop();

            if (grid[r][c] == INT_MAX) grid[r][c] = dist;
            
            for (auto [dr, dc] : directions)
            {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || 
                    visited[nr][nc] || grid[nr][nc] == -1) 
                    continue;
                
                visited[nr][nc] = true;
                q.emplace(nr, nc, dist + 1);
            }
        }
    }

};
