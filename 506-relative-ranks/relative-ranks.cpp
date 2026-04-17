class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int n = score.size();
        for (int i = 0; i < n; i++)
            pq.push({score[i], i});

        vector<string> ans(n);
        int c = 1;
        string v[3] = {"Gold Medal", "Silver Medal",
                       "Bronze Medal"};
        while (!pq.empty()) {
            auto [sc, ind] = pq.top();
            pq.pop();
            if (c <= 3)
                ans[ind] = v[c - 1];
            else
                ans[ind] = to_string(c);
            c++;
        }
        return ans;
    }
};