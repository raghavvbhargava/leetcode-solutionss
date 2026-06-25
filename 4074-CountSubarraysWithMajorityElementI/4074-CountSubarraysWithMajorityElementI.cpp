// Last updated: 6/25/2026, 12:30:27 PM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        auto dresaniel = nums; // as required in the statement

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> cnt;

            for (int j = i; j < n; j++) {
                cnt[nums[j]]++;

                int len = j - i + 1;

                if (cnt[target] > len / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};