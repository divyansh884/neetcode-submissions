class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        if (s[n - 1] == '1')
            return false;

        vector<int> ans(n + 1, 0);

        int sum = 0;

        ans[minJump]++;
        ans[min(n, maxJump + 1)]--;

        for (int i = 1; i < n; i++) {

            sum += ans[i];

            if (s[i] == '1')
                continue;

            if (sum == 0)
                continue;

            ans[min(n, i + minJump)]++;
            ans[min(n, i + maxJump + 1)]--;
        }

        return sum > 0;
    }
};