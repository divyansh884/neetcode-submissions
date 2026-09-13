class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        int n = s.size();

        map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();

            if (ans.empty() || ans.back() != first.second) {
                ans.push_back(first.second);
                first.first--;

                if (first.first > 0)
                    pq.push(first);
            }
            else {
                if (pq.empty())
                    return "";

                auto second = pq.top();
                pq.pop();

                ans.push_back(second.second);
                second.first--;

                if (second.first > 0)
                    pq.push(second);

                pq.push(first);
            }
        }

        return ans;
    }
};