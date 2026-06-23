// Last updated: 6/23/2026, 11:55:57 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h = nums.size()-1;
        int mid;
        while(l<h){
            mid = (h+l)/2;
            if (nums[mid]>nums[h]){
                l = mid +1;
            }
            else h=mid;
        }
        return nums[l];
    }
};