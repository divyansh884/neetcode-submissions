class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int st = 0, ed = s.size() - 1;

        while (st < ed) {
            if (s[st] != s[ed]) {
                return isPalindrome(s, st + 1, ed) ||
                       isPalindrome(s, st, ed - 1);
            }
            st++;
            ed--;
        }

        return true;
    }
};