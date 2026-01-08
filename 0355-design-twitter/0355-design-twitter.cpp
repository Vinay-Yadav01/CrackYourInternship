class Twitter {
    int count;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        count = 0;
        followers.clear();
        tweets.clear();
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        followers[userId].insert(userId);

        auto cmp = [&](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(
            cmp);

        for (auto followeeId : followers[userId]) {
            if (tweets.count(followeeId)) {
                int index = tweets[followeeId].size() - 1;
                auto [time, tweetId] = tweets[followeeId][index];
                maxHeap.push({time, tweetId, followeeId, index - 1});
            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            auto it = maxHeap.top();
            maxHeap.pop();
            int time = it[0], tweetId = it[1], followeeId = it[2],
                index = it[3];
            res.push_back(tweetId);

            if (index >= 0) {
                auto [newTime, newTweetId] = tweets[followeeId][index];
                maxHeap.push({newTime, newTweetId, followeeId, index - 1});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */