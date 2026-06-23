// Last updated: 6/23/2026, 10:08:18 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int h = nums.size() -1;
        int mid;
        while (l<=h){
            mid = (l+h)/2;
            if (target == nums[mid]) return true;
            if(nums[l]==nums[mid] && nums[h]==nums[mid]){
                l++;
                h--;
                continue;
            }
            if (nums[l]<=nums[mid]){
                if (nums[l]<=target && nums[mid]>target){
                    h = mid -1;
                }
                else l =mid +1;
            }
            else {
                if (target>nums[mid] && target<= nums[h])
                    l = mid +1;
                     
                else  
                    h =mid -1;
              
            }
        }
        return false;
    }
};