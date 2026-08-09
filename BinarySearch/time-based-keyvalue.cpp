class TimeMap
{
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        vector<pair<string, int>> v;
        v = mp[key];
        int mid;
        int l = 0;
        int r = v.size() - 1;
        string ans = "";
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (v[mid].second <= timestamp)
            {
                ans = v[mid].second;
                l = mid + 1;
            }
            else
            {
                r = mid - 1
            }
        }
        return ans;
    }
};
