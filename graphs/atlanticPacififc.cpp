class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> sol;

        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pb(row, vector<bool>(col, false));
        vector<vector<bool>> ab(row, vector<bool>(col, false));

        auto dfs = [&](auto &&self, int r, int c,
                       vector<vector<bool>> &s,
                       int prevHeight) -> void
        {
            if (r < 0 || c < 0 || r >= row || c >= col ||
                s[r][c] || heights[r][c] < prevHeight)
            {
                return;
            }
            s[r][c] = true;
            self(self, r + 1, c, s, heights[r][c]);
            self(self, r - 1, c, s, heights[r][c]);
            self(self, r, c + 1, s, heights[r][c]);
            self(self, r, c - 1, s, heights[r][c]);
        };
        for (int c = 0; c < col; c++)
        {
            dfs(dfs, 0, c, pb, heights[0][c]);
            dfs(dfs, row - 1, c, ab, heights[row - 1][c]);
        }

        for (int r = 0; r < row; r++)
        {
            dfs(dfs, r, 0, pb, heights[r][0]);
            dfs(dfs, r, col - 1, ab, heights[r][col - 1]);
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (ab[i][j] && pb[i][j])
                {
                    sol.push_back({i, j});
                }
            }
        }
        return sol;
    }
};
