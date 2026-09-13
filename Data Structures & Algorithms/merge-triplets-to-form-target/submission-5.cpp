class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& tt, vector<int>& target) {
        int n = tt.size();
        sort(tt.begin(), tt.end());
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if(tt[i][1]<=target[1])
            mp[tt[i][2]]++;
            if (tt[i][0] > target[0]) break;
            if (tt[i][0] != target[0]) {
                continue;
            }
            if(tt[i][1]>target[1] || tt[i][2]>target[2])
            continue;
            for (int j = 0; j <= i; j++) {
                if(tt[j][1]<=target[1] && tt[j][2]<=target[2]){
                    if(tt[j][1]==target[1] && mp.find(target[2])!=mp.end())
                    return true;
                }
            }
        }
        return false;
    }
};
