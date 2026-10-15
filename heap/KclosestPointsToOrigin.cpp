class Solution
{
public:
    void heapify(vector<vector<int>> &v, int i)
    {
        int n = v.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int la = pow(v[i][0], 2) + pow(v[i][1], 2);
        if (left < n)
        {
            int l = pow(v[left][0], 2) + pow(v[left][1], 2);
            if (la < l)
                largest = left;
        }
        if (right < n)
        {
            int r = pow(v[right][0], 2) + pow(v[right][1], 2);
            int d = v[largest][0] * v[largest][0] + v[largest][1] * v[largest][1];
            if (d < r)
                largest = right;
        }
        if (largest != i)
        {
            swap(v[largest], v[i]);
            heapify(v, largest);
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        for (int i = points.size() / 2 - 1; i >= 0; i--)
        {
            heapify(points, i);
        }
        while (points.size() > k)
        {
            swap(points[0], points.back());
            points.pop_back();
            if (!points.empty())
            {
                heapify(points, 0);
            }
        }
        return points;
    }
};