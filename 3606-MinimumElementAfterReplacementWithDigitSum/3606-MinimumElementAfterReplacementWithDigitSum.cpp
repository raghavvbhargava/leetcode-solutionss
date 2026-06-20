// Last updated: 6/20/2026, 5:07:09 PM
class Solution {
public:
    int minElement(vector<int>& nums) {

        int ans = INT_MAX;

        for(int num : nums) {

            int sum = 0;

            while(num > 0) {
                sum += num % 10;
                num /= 10;
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};