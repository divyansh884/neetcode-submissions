class Solution {
   public:
    bool validPalindrome(string s) {
        int st = 0;
        int ed = s.size() - 1;
        bool check = true;
        while (st <= ed) {
            if (s[st] == s[ed]) {
                st++;
                ed--;
            } else {
                check = false;
                break;
            }
        }
        if (check) return check;
        bool c1 = true, c2 = true;
        int st1 = st + 1, ed1 = ed;
        while (st1 <= ed1) {
            if (s[st1] == s[ed1]) {
                st1++;
                ed1--;
            } else {
                c1 = false;
                break;
            }
        }
        if (c1) return true;
        int st11 = st, ed11 = ed - 1;
        while (st11 <= ed11) {
            if (s[st11] == s[ed11]) {
                st11++;
                ed11--;
            } else {
                c2 = false;
                break;
            }
        }
        if (c2) return true;
        return false;
    }
};