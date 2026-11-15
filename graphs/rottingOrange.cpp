class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        int time = 0;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 2)
                {
                    q.push({r, c});
                }
                if (grid[r][c] == 1)
                {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
        {
            return 0;
        }
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty() && fresh > 0)
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : direction)
                {
                    int nr = dr + r;
                    int nc = dc + c;
                    if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] != 1)
                    {
                        continue;
                    }
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh -= 1;
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};