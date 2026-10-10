class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int ans = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int row = std::get<0>(node);
            int col = std::get<1>(node);
            int dist = std::get<2>(node);
            ans = max(ans, dist);
            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
                    grid[nr][nc] == 1) {
                    q.push({nr, nc, dist + 1});
                    grid[nr][nc] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
