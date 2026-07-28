class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        if (position.size() == 0)
            return 0;
        if (position.size() == 1)
            return 1;

        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        stack<double> time;
        for (int i = cars.size() - 1; i >= 0; i--)
        {
            double t = (double)(target - cars[i].first) / cars[i].second;
            if (time.empty())
            {
                time.push(t);
            }
            else if (t > time.top())
            {
                time.push(t);
            }
        }
        return time.size();
    }
};