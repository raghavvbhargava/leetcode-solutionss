// Last updated: 7/18/2026, 11:57:56 AM
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums) freq[x]++;

        vector<long long> cnt(mx + 1);

        for (int g = 1; g <= mx; g++) {
            long long c = 0;
            for (int j = g; j <= mx; j += g)
                c += freq[j];
            cnt[g] = c * (c - 1) / 2;
        }

        for (int g = mx; g >= 1; g--) {
            for (int j = g * 2; j <= mx; j += g)
                cnt[g] -= cnt[j];
        }

        vector<long long> pref;
        vector<int> vals;
        long long sum = 0;
        for (int g = 1; g <= mx; g++) {
            if (cnt[g] > 0) {
                sum += cnt[g];
                pref.push_back(sum);
                vals.push_back(g);
            }
        }

        vector<int> ans;
        for (long long q : queries) {
            int idx = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(vals[idx]);
        }

        return ans;
    }
};