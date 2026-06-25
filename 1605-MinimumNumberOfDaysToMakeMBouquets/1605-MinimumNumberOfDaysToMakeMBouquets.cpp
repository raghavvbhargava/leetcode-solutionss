// Last updated: 6/25/2026, 6:56:40 PM
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long long)m * k > n) return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int l = mini;
        int h = maxi;
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            int count = 0;
            int bouquet = 0;

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    count++;
                } 
                else {
                    count = 0;
                }

                if (count == k) {
                    bouquet++;
                    count = 0;
                }
            }

            if (bouquet >= m) {
                ans = mid;
                h = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};