class Solution
{
public:
    void heapify(vector<int> &v, int i, int n)
    {
        int s = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && v[s] < v[left])
        {
            s = left;
        }
        if (right < n && v[s] < v[right])
        {
            s = right;
        }
        if (s != i)
        {
            swap(v[i], v[s]);
            heapify(v, s, n);
        }
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
        {
            heapify(nums, i, n);
        }
        for (int i = 0; i < k - 1; i++)
        {
            swap(nums[0], nums[n - 1]);
            n--;
            heapify(nums, 0, n);
        }
        return nums[0];
    }
};