class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        
        // Your check array mapping comparisons
        vector<int> check(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < arr[i + 1])
                check[i] = 0;
            else if (arr[i] > arr[i + 1])
                check[i] = 1;
            else
                check[i] = -1;
        }

        int ans = 1;
        int current_len = 0; // Tracks the sequence of valid comparisons

        // Iterate through your check array to count alternating 0s and 1s
        for (int i = 0; i < n - 1; i++) {
            if (check[i] == -1) {
                current_len = 0; 
            } 
            else if (i > 0 && check[i] != check[i - 1] && check[i - 1] != -1) {
                current_len++;
            } 
            else {
                current_len = 1;
            }
            ans = max(ans, current_len + 1);
        }
        
        return ans;
    }
};