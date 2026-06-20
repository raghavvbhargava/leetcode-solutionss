// Last updated: 6/20/2026, 5:07:00 PM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn = *min_element(nums.begin(), nums.end());
        long long mx = *max_element(nums.begin(), nums.end());
        return 1LL * k * (mx - mn);
    }
};