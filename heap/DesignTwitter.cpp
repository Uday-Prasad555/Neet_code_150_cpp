class Twitter
{
public:
    unordered_map<int, unordered_set<int>> fl;
    unordered_map<int, vector<pair<int, int>>> ps;
    int t = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        ps[userId].push_back({t, tweetId});
        t++;
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> sol;
        priority_queue<pair<int, int>> pq;
        for (auto i : ps[userId])
        {
            pq.push(i);
        }
        for (auto k : fl[userId])
        {
            for (auto j : ps[k])
            {
                pq.push(j);
            }
        }
        int c = 0;
        while (!pq.empty() && c < 10)
        {
            sol.push_back(pq.top().second);
            pq.pop();
            c++;
        }

        return sol;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            fl[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId)
    {
        fl[followerId].erase(followeeId);
    }
};