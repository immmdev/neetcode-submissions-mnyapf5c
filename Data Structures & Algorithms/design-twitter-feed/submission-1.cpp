class Twitter {
public:
    // userId -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> following;

    int timestamp = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Include user's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);

            if (pq.size() > 10)
                pq.pop();
        }

        // Include tweets of people user follows
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push(tweet);

                if (pq.size() > 10)
                    pq.pop();
            }
        }

        vector<int> res;

        // Currently oldest -> newest
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        // Newest -> oldest
        reverse(res.begin(), res.end());

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};