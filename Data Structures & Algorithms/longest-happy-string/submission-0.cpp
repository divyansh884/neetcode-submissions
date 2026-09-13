class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        pq.push({a,'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        string ans = "";
        int see = 1;
        while (!pq.empty()) {
            int cnt = pq.top().first;
            char cc = pq.top().second;
            pq.pop();
            if(cnt==0)
            continue;
            if (ans.empty()) {
                ans.push_back(cc);
                if (cnt >0) pq.push({cnt - 1, cc});
            } else if (ans.back() == cc) {
                if (see == 1) {
                    ans.push_back(cc);
                    if (cnt > 0) pq.push({cnt - 1, cc});
                    see++;
                } else {
                    if (pq.empty()) break;
                    int cnt1 = pq.top().first;
                    char cc1 = pq.top().second;
                    pq.pop();
                    if(cnt1==0)
                    break;
                    ans.push_back(cc1);
                    if (cnt1 > 0) pq.push({cnt1 - 1, cc1});
                    ans.push_back(cc);
                    if (cnt > 0) pq.push({cnt - 1, cc});
                    see = 1;
                }
            } else {
                ans.push_back(cc);
                if (cnt > 0) pq.push({cnt - 1, cc});
                see = 1;
            }
        }
        return ans;
        return "";
    }
};