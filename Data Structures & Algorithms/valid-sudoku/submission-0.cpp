class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> squares(9);

        /*

        (i / 3) + ((j / 3) * 3) + 1

        square 1:
        i / 3 = 0;
        j / 3 = 0

        square 2:
        i / 3 = 1
        j / 3 = 0

        square 3:
        i / 3 = 2
        j / 3 = 0

        square 4:

        i / 3 = 0
        j / 3 = 1

        square 5:

        i / 3 = 1
        j / 3 = 1

        square 6
        i / 3 = 2
        j / 3 = 1

        square 7:
        i / 3 = 0
        j / 3 = 2

        */
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    char num = board[i][j];
                    int square_idx = (i / 3) + ((j / 3) * 3);
                    if (rows[i].find(num) != rows[i].end())
                    {
                        return false;
                    }
                    if (cols[j].find(num) != cols[j].end())
                    {
                        return false;
                    }
                    if (squares[square_idx].find(num) != squares[square_idx].end())
                    {
                        return false;
                    }

                    rows[i].insert(num);
                    cols[j].insert(num);
                    squares[square_idx].insert(num);
                }
            }
        }
        return true;
    }
};
