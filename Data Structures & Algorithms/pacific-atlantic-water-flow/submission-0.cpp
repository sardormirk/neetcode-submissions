class Solution {
public:
    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        const int ROWS = heights.size(), COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        vector<vector<int>> results;

        for (int row = 0; row < ROWS; row++)
        {
            traverse(row, 0, heights, pacific);
            traverse(row, COLS-1, heights, atlantic);
        }

        for (int col = 0; col < COLS; col++)
        {
            traverse(0, col, heights, pacific);
            traverse(ROWS-1, col, heights, atlantic);
        }

        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (pacific[row][col] && atlantic[row][col])
                {
                    results.push_back({row, col});
                }
            }
        }

        return results;
    }

    void traverse(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean)
    {   
        ocean[r][c] = true;

        for (const auto& [dr, dc] : directions)
        {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nc < 0 || nr >= heights.size() || nc >= heights[0].size() || ocean[nr][nc] || heights[r][c] > heights[nr][nc])
                continue;
            

            traverse(nr, nc, heights, ocean);
        }
    }
};
