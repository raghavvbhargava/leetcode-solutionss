// Last updated: 6/20/2026, 5:07:39 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int num : nums){
            ans ^= num;
        }

        return ans;
    }
};