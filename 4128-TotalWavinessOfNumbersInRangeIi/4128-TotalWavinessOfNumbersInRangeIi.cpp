// Last updated: 6/20/2026, 5:06:54 PM
class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    vector<int> digits;
    Node dp[20][4][11][11];
    bool vis[20][4][11][11];

    Node dfs(int pos, int lenState, int last2, int last1, bool tight) {
        if (pos == (int)digits.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][lenState][last2][last1]) {
            return dp[pos][lenState][last2][last1];
        }

        int limit = tight ? digits[pos] : 9;
        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (lenState == 0) {
                // Still no non-leading digit chosen
                if (d == 0) {
                    Node nxt = dfs(pos + 1, 0, 10, 10, ntight);
                    res.cnt += nxt.cnt;
                    res.sum += nxt.sum;
                } else {
                    Node nxt = dfs(pos + 1, 1, 10, d, ntight);
                    res.cnt += nxt.cnt;
                    res.sum += nxt.sum;
                }
            } else {
                long long add = 0;

                if (lenState >= 2) {
                    int a = last2;
                    int b = last1;

                    if ((b > a && b > d) || (b < a && b < d))
                        add = 1;
                }

                int nLen;
                int nLast2;
                int nLast1;

                if (lenState == 1) {
                    nLen = 2;
                    nLast2 = last1;
                    nLast1 = d;
                } else {
                    nLen = 3; // means length >= 3
                    nLast2 = last1;
                    nLast1 = d;
                }

                Node nxt = dfs(pos + 1, nLen, nLast2, nLast1, ntight);

                res.cnt += nxt.cnt;
                res.sum += nxt.sum + add * nxt.cnt;
            }
        }

        if (!tight) {
            vis[pos][lenState][last2][last1] = true;
            dp[pos][lenState][last2][last1] = res;
        }

        return res;
    }

    long long solve(long long N) {
        if (N < 0) return 0;

        digits.clear();
        string s = to_string(N);
        for (char c : s) digits.push_back(c - '0');

        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, 10, 10, true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};