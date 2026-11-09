class Solution
{
public:
    void bfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        vis[r][c] = true;
        q.push({r, c});
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions)
            {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == '1' &&
                    !vis[nr][nc])
                {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int islands = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1' && !vis[r][c])
                {
                    bfs(r, c, grid, vis);
                    islands++;
                }
            }
        }
        return islands;
    }
};