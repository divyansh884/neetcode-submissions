class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        vector<int> ans;
        int stindex=0;
        int maxindex=0;
        for(int i=0;i<n;i++){
            maxindex=max(maxindex,mp[s[i]]);
            if(maxindex==i){
                ans.push_back(maxindex-stindex+1);
                stindex=maxindex+1;
                maxindex=stindex;
            }
        }
        return ans;
    }
};
