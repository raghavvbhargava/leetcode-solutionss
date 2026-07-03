// Last updated: 7/3/2026, 11:52:41 AM
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> best(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];
        if(startHealth <= 0) return false;

        q.push({0,0});
        best[0][0] = startHealth;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(x == m-1 && y == n-1) return true;

            for(int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<m && ny<n) {
                    int newHealth = best[x][y] - grid[nx][ny];

                    if(newHealth > 0 && newHealth > best[nx][ny]) {
                        best[nx][ny] = newHealth;
                        q.push({nx,ny});
                    }
                }
            }
        }

        return false;
    }
};