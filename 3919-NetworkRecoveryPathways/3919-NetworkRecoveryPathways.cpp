// Last updated: 7/3/2026, 11:52:38 AM
class Solution {
public:
    bool can(int n, vector<vector<int>>& edges, vector<bool>& online, long long k, int val) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (w < val) continue;
            if (u != 0 && !online[u]) continue;
            if (v != n - 1 && !online[v]) continue;

            adj[u].push_back({v, w});
            indegree[v]++;
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &p : adj[u]) {
                int v = p.first;
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == LLONG_MAX) continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int low = 0, high = 0, ans = -1;

        for (auto &e : edges) {
            high = max(high, e[2]);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (can(n, edges, online, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};