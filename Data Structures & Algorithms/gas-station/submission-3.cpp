class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> cc;
        int n = gas.size();

        for (int i = 0; i < n; i++)
            cc.push_back(gas[i] - cost[i]);

        int stind = 0;
        int fuel = 0;
        int total = 0;

        for (int i = 0; i < n; i++) {
            fuel += cc[i];
            total += cc[i];

            if (fuel < 0) {
                stind = i + 1;
                fuel = 0;
            }
        }

        if (total < 0)
            return -1;

        return stind;
    }
};