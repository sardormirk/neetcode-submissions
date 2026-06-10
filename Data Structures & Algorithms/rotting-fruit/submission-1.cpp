class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        const int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int, int>> fruit;
        int fresh = 0;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 2)
                {
                    fruit.emplace(i, j);
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        int mins = 0;

        while (!fruit.empty() && fresh > 0)
        {
            int fruit_count = fruit.size();
            for (int i = 0; i < fruit_count; i++)
            {
            auto [r, c] = fruit.front(); fruit.pop();
            for (auto [dr, dc] : directions)
                {
                    int nr = r + dr, nc = c + dc;

                    if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] != 1)
                        continue;
                    
                    grid[nr][nc] = 2;
                    fresh--;
                    fruit.emplace(nr, nc);
                }
            }
            mins++;
        }

        return !fresh ? mins : -1;
    }
};
