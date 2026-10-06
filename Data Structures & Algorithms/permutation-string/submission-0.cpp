class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        unordered_map<char,int> mp;
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        unordered_map<char,int> mp1;
        int st=0;
        for(int i=0;i<n;i++){
            mp1[s2[i]]++;
            while(mp1[s2[i]]>mp[s2[i]]){
                mp1[s2[st]]--;
                st++;
            }
            bool check=true;
            for(auto it: mp){
                if(mp1[it.first]!=it.second)
                check=false;
            }
            if(check)
            return true;
        }
        return false;
    }
};
