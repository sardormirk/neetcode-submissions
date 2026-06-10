class Solution {
public:
    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == 'O' && (j == 0 || j == COLS-1 || i == 0 || i == ROWS-1))
                {
                    q.emplace(i, j);
                }
            }
        }

        while(!q.empty())
        {
            auto [r, c] = q.front(); q.pop();
            
            board[r][c] = 'B';

            for (const auto& [dr, dc] : directions)
            {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || board[nr][nc] != 'O')
                    continue;
                
                q.emplace(nr, nc);
            }
        }

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'B')
                {
                    board[i][j] = 'O';
                }
            }
        }
                
    }
};
