class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        vector<int> check(n - 1);

        for (int i = n - 1; i >= 1; i--) {
            if (arr[i] < arr[i - 1])
                check[i - 1] = 0;
            else if (arr[i] > arr[i - 1])
                check[i - 1] = 1;
            else
                check[i - 1] = -1;
        }

        int ans = 0;
        int currsum = 0;
        bool expectZero = true; 
        for (int i = 0; i < n - 1; i++) {
            if (check[i] == 0 && expectZero) {
                currsum++;
                expectZero = false; 
            }
            else if (check[i] == 1 && !expectZero) {
                currsum++;
                expectZero = true; 
            }
            else {
                if (check[i] == 0) {
                    currsum = 1;
                    expectZero = false; 
                } else {
                    currsum = 0;
                    expectZero = true; 
                }
            }
            ans = max(ans, currsum);
        }
        currsum = 0;
        expectZero = false; 
        
        for (int i = 0; i < n - 1; i++) {
            if (check[i] == 1 && !expectZero) {
                currsum++;
                expectZero = true;
            }
            else if (check[i] == 0 && expectZero) {
                currsum++;
                expectZero = false;
            }
            else {
                if (check[i] == 1) {
                    currsum = 1;
                    expectZero = true;
                } else {
                    currsum = 0;
                    expectZero = false;
                }
            }
            ans = max(ans, currsum);
        }

        return ans + 1;
    }
};