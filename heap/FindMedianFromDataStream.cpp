class MedianFinder
{
public:
    priority_queue<int> ma;
    priority_queue<int, vector<int>, greater<int>> mi;
    MedianFinder()
    {
    }
    void addNum(int num)
    {
        if (ma.empty() || num <= ma.top())
        {
            ma.push(num);
        }
        else
        {
            mi.push(num);
        }

        if (ma.size() > mi.size() + 1)
        {
            mi.push(ma.top());
            ma.pop();
        }
        else if (mi.size() > ma.size())
        {
            ma.push(mi.top());
            mi.pop();
        }
    }

    double findMedian()
    {
        if ((ma.size() + mi.size()) % 2 == 0)
        {
            return (double)(ma.top() + mi.top()) / 2;
        }
        return (double)ma.top();
    }
};