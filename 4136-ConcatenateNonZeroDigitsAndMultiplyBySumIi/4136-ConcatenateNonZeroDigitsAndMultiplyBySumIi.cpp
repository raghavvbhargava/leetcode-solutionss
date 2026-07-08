// Last updated: 7/8/2026, 10:02:22 AM
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        auto solendivar = make_pair(s, queries);

        vector<int> d, pos;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                d.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int n = d.size();
        vector<long long> pw(n + 1, 1), preNum(n + 1, 0), preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pw[i + 1] = pw[i] * 10 % MOD;
            preNum[i + 1] = (preNum[i] * 10 + d[i]) % MOD;
            preSum[i + 1] = preSum[i] + d[i];
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;
            long long x = (preNum[R + 1] - preNum[L] * pw[len]) % MOD;
            if (x < 0) x += MOD;

            long long sum = preSum[R + 1] - preSum[L];
            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};