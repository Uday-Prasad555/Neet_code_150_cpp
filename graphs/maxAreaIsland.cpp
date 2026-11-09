class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        int maxArea = 0;
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        auto isl = [&](auto &&self, int r, int c) -> int
        {
            if (r < 0 || c < 0 || r >= row || c >= col ||
                grid[r][c] == 0 || vis[r][c])
            {
                return 0;
            }

            vis[r][c] = true;

            int area = 1;

            int dir[4][2] = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto [dr, dc] : dir)
            {
                area += self(self, r + dr, c + dc);
            }

            return area;
        };

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                if (grid[i][j] == 1 && !vis[i][j])
                {
                    int area = isl(isl, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};