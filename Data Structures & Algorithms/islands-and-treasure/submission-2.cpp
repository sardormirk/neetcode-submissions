class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int ROWS = static_cast<int>(grid.size());
        const int COLS = static_cast<int>(grid[0].size());

        queue<pair<int, int>> q;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 0)
                {   
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty())
        {
            auto [r, c] = q.front(); q.pop();
            
            for (auto [dr, dc] : directions)
            {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || 
                    grid[nr][nc] != INT_MAX) 
                    continue;
                
                grid[nr][nc] = grid[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }

};
