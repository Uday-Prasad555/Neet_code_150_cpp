class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        auto dfs = [&](auto &&self, int r, int c) -> void
        {
            if (r < 0 || c < 0 || r >= row || c >= col ||
                board[r][c] != 'O')
            {
                return;
            }
            board[r][c] = '#';
            self(self, r + 1, c);
            self(self, r - 1, c);
            self(self, r, c + 1);
            self(self, r, c - 1);
        };
        for (int r = 0; r < row; r++)
        {
            if (board[r][0] == 'O')
                dfs(dfs, r, 0);
            if (board[r][col - 1] == 'O')
                dfs(dfs, r, col - 1);
        }
        for (int c = 0; c < col; c++)
        {
            if (board[0][c] == 'O')
                dfs(dfs, 0, c);

            if (board[row - 1][c] == 'O')
                dfs(dfs, row - 1, c);
        }
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};
