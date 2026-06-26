// Last updated: 6/26/2026, 9:56:55 AM
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // represents the occurrence count of prefix sums -n, -(n-1), ..., 0, 1,
        // ..., n, with index offset by n.
        vector<int> pre(n * 2 + 1, 0);
        pre[n] = 1;
        int cnt = n;
        long long ans = 0, presum = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                presum += pre[cnt];
                ++cnt;
                ++pre[cnt];
            } else {
                --cnt;
                presum -= pre[cnt];
                ++pre[cnt];
            }
            ans += presum;
        }
        return ans;
    }
};