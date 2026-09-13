class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& task) {
        int n = task.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n; i++) {
            task[i].push_back(i);
        }
        sort(task.begin(), task.end());
        vector<int> ans;
        int i = 0;
        long long time = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty() && i < n) {
                time = max(time, (long long)task[i][0]);
            }
            while (i < n && task[i][0] <= time) {
                pq.push({task[i][1], task[i][2]});
                i++;
            }
            if (!pq.empty()) {
                ans.push_back(pq.top()[1]);
                time += pq.top()[0];
                pq.pop();
            }
        }

        return ans;
    }
};