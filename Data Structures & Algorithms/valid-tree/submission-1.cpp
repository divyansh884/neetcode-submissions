class Solution {
   public:
   bool f(int i, vector<vector<int>> &adj, vector<int> &vis) {
		queue<vector<int>> q;
		q.push({i, -1});
		vis[i]=true;
		while (!q.empty()) {
			int node = q.front()[0];
			int parent = q.front()[1];
			q.pop();
			for (auto it: adj[node]) {
				if (!vis[it]) {
					vis[it] = true;
					q.push({it, node});
				}
				else if (it != parent)
					return false;
			}
		}
		return true;
	}
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
		for (int i = 0; i<edges.size(); i++) {
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
		}
		
		vector<int> vis(n, 0);
        int cnt=0;
		for (int i = 0; i<n; i++) {
			if(!vis[i]){
                bool see=f(i,adj,vis);
                if(!see)
			    return false;
                else
                cnt++;
			}
		}
        if(cnt>1)
        return false;
		return true;
    }
};
