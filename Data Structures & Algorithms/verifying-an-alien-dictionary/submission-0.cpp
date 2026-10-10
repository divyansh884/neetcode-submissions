class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int n = order.size();
        for (int i = 0; i < n; i++) {
            mp[order[i]] = i;
        }
        int m = words.size();
        for (int i = 1; i < m; i++) {
            char a = '#', b = '#';
            for (int j = 0; j < min(words[i].size(), words[i - 1].size()); j++) {
                if (words[i][j] != words[i - 1][j]) {
                    a = words[i - 1][j];
                    b = words[i][j];
                    break;
                }
            }
            if (a == '#' && words[i - 1].size() > words[i].size()) {
                return false;
            }
            if(mp[a]>mp[b])
            return false;
        }
        return true;
    }
};