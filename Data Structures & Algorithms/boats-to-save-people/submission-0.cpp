class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0, l = 0, r = people.size() - 1;
        while (l <= r) {
            int li=people[l];
            if(l!=r)
            li+=people[r];
            if(li<=limit){
            res++;
            l++;
            r--;
            }
            else{
                res++;
                r--;
            }
        }
        return res;
    }
};