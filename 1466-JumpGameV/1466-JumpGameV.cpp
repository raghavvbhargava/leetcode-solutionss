// Last updated: 6/20/2026, 5:07:33 PM
class Solution {
public:
    int n;
    vector<int> dp;

    int dfs(int i, vector<int>& arr, int d) {
        if (dp[i] != -1)
            return dp[i];

        int best = 1;

        // move right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i])
                break;

            best = max(best, 1 + dfs(j, arr, d));
        }

        // move left
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i])
                break;

            best = max(best, 1 + dfs(j, arr, d));
        }

        return dp[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.assign(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d));
        }

        return ans;
    }
};