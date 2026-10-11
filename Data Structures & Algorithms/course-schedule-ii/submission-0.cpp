class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            indeg[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
            q.push(i);
            }
        }
        if(q.empty())
        return {};
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0)
                q.push(it);
            }
        }
       if(ans.size()==numCourses)
       return ans;
       return {};
    }
};
