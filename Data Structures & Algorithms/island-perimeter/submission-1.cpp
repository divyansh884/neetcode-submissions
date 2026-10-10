
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    break;
                }
            }
            if (!q.empty()) break;
        }

        int perimeter = 0;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m ||
                    grid[nr][nc] == 0) {
                    perimeter++;
                }
                else if (!vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return perimeter;
    }
};
