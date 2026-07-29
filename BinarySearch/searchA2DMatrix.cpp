class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int l = 0;
        int r = matrix.size() - 1;
        int innersize = matrix[0].size();
        int inner;
        while (l <= r)
        {
            inner = l + (r - l) / 2;
            if (target >= matrix[inner][0] && target <= matrix[inner][innersize - 1])
            {
                break;
            }
            else if (target > matrix[inner][innersize - 1])
            {
                l = inner + 1;
            }
            else
            {
                r = inner - 1;
            }
        }
        if (l > r)
        {
            return false;
        }
        int l1 = 0;
        int r1 = innersize - 1;
        int mid;
        while (l1 <= r1)
        {
            mid = l1 + (r1 - l1) / 2;
            ;
            if (target == matrix[inner][mid])
            {
                return true;
            }
            else if (target < matrix[inner][mid])
            {
                r1 = mid - 1;
            }
            else
            {
                l1 = mid + 1;
            }
        }
        return false;
    }
};