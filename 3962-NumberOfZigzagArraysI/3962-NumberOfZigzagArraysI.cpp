// Last updated: 6/23/2026, 10:51:52 AM
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long mod = 1e9 + 7;
        int m = r - l + 1;

        if (n == 1) return m;

        vector<int> up(m, 0), down(m, 0);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - i - 1;
        }

        for (int len = 2; len < n; len++) {
            vector<int> nextUp(m, 0), nextDown(m, 0);

            long long pref = 0;
            for (int i = 0; i < m; i++) {
                nextUp[i] = pref;
                pref = (pref + down[i]) % mod;
            }

            long long suff = 0;
            for (int i = m - 1; i >= 0; i--) {
                nextDown[i] = suff;
                suff = (suff + up[i]) % mod;
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % mod;
        }

        return ans;
    }
};