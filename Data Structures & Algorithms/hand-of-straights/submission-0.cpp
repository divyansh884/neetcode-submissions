class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        map<int, int> mp;
        int n=hand.size();
        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }
        for (int i = 0; i < n; i++) {
            int start = hand[i];
            int cnt = 1;
            if (mp.find(start) == mp.end()) continue;
            mp[start]--;
            if (mp[start] == 0) mp.erase(start);
            while (mp.find(start + 1) != mp.end()) {
                if (cnt == groupSize) break;
                cnt++;
                start++;
                mp[start]--;
                if (mp[start] == 0) mp.erase(start);
            }
            if (cnt != groupSize) return false;
        }
        return true;
    }
};
