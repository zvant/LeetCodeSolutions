/**
 * https://leetcode.com/problems/design-twitter/description/
 * 2016/07
 * 84 ms
 */

struct TwitterUser
{
    int userid;
    std::vector<int> tweetidx;
    std::set<int> follows;
    TwitterUser(int id)
    {
        userid = id;
        tweetidx = std::vector<int>();
        follows = std::set<int>();
        follows.insert(userid);
    }
};

class Twitter
{
private:
    std::vector<int> tweets;
    std::unordered_map<int, TwitterUser *> users;
    
    void addUser(int id)
    {
        if(users.find(id) == users.end())
        {
            users[id] = new TwitterUser(id);
        }
    }

public:
    /** Initialize your data structure here. */
    Twitter()
    {
        tweets = std::vector<int>();
        users = std::unordered_map<int, TwitterUser *>();
    }
    ~Twitter()
    {
        for(auto it = users.begin(); it != users.end(); it ++)
        {
            delete it -> second;
        }
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        tweets.push_back(tweetId);
        addUser(userId);
        users[userId] -> tweetidx.push_back(tweets.size() - 1);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        std::vector<int> new_feeds;
        if(users.find(userId) == users.end())
            return new_feeds;
        
        TwitterUser & user = * users[userId];
        std::vector<int> feeds;
        for(auto it = user.follows.begin(); it != user.follows.end(); it ++)
        {
            int follow_id = * it;
            std::vector<int> & follow_idx = users[follow_id] -> tweetidx;
            for(size_t idx = 0; idx < follow_idx.size(); idx ++)
            {
                feeds.push_back(follow_idx[idx]);
            }
        }
        std::sort(feeds.begin(), feeds.end());

        for(int idx = feeds.size() - 1; idx > -1 && idx > (int)(feeds.size()) - 11; idx --)
        {
            new_feeds.push_back(tweets[feeds[idx]]);
        }
        return new_feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if(followerId == followeeId)
            return;
        addUser(followerId);
        addUser(followeeId);
        users[followerId] -> follows.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if(followerId == followeeId)
            return;
        addUser(followerId);
        addUser(followeeId);
        users[followerId] -> follows.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
