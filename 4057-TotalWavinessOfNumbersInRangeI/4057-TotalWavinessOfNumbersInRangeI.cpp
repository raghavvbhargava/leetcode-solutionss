// Last updated: 6/20/2026, 5:06:57 PM
class Solution {
    using ll = long long;

    struct Node {
        ll cnt;   // count of numbers
        ll sum;   // total waviness
    };

    string s;
    Node dp[20][2][3][11][11];
    bool vis[20][2][3][11][11];

    Node dfs(int pos, bool started, int state,
             int prev2, int prev1, bool tight) {

        if (pos == (int)s.size())
            return {1, 0};

        if (!tight && vis[pos][started][state][prev2 + 1][prev1 + 1])
            return dp[pos][started][state][prev2 + 1][prev1 + 1];

        int lim = tight ? s[pos] - '0' : 9;
        Node res{0, 0};

        for (int d = 0; d <= lim; d++) {
            bool ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, false, 0, -1, -1, ntight);
                res.cnt += nxt.cnt;
                res.sum += nxt.sum;
                continue;
            }

            if (!started) {
                Node nxt = dfs(pos + 1, true, 1, -1, d, ntight);
                res.cnt += nxt.cnt;
                res.sum += nxt.sum;
            }
            else if (state == 1) {
                Node nxt = dfs(pos + 1, true, 2, prev1, d, ntight);
                res.cnt += nxt.cnt;
                res.sum += nxt.sum;
            }
            else {
                int add =
                    ((prev1 > prev2 && prev1 > d) ||
                     (prev1 < prev2 && prev1 < d));

                Node nxt = dfs(pos + 1, true, 2, prev1, d, ntight);

                res.cnt += nxt.cnt;
                res.sum += nxt.sum + 1LL * add * nxt.cnt;
            }
        }

        if (!tight) {
            vis[pos][started][state][prev2 + 1][prev1 + 1] = true;
            dp[pos][started][state][prev2 + 1][prev1 + 1] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, false, 0, -1, -1, true).sum;
    }

public:
    int totalWaviness(int num1, int num2) {
        return (int)(solve(num2) - solve(1LL * num1 - 1));
    }
};