class Solution
{
public:
    bool bk(int r, int c, int i, string &word,
            vector<vector<char>> &board)
    {

        if (i == word.size())
            return true;

        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] != word[i])
        {
            return false;
        }

        char ch = board[r][c];
        board[r][c] = '#';

        bool res = bk(r + 1, c, i + 1, word, board) ||
                   bk(r - 1, c, i + 1, word, board) ||
                   bk(r, c + 1, i + 1, word, board) ||
                   bk(r, c - 1, i + 1, word, board);

        board[r][c] = ch;

        return res;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (bk(r, c, 0, word, board))
                    return true;
            }
        }

        return false;
    }
};