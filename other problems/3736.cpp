class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int max = 0;
        for (int x : nums)
        {
            if (x > max)
            {
                max = x;
            }
        }
        int moves = 0;
        for (int y : nums)
        {
            moves = moves + (max - y);
        }
        return moves;
    }
};