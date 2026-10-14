class TimeMap {
    map<string, set<pair<int, string>>> mp;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound({timestamp, string(1, char(127))});

        if (it != mp[key].begin()) {
            it--;
            return it->second;
        }

        return "";
    }
};