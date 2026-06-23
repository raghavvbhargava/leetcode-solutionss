// Last updated: 6/23/2026, 7:12:47 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int h = n - 1;  

        while(l <= h){
            int mid = (l + h) / 2;

            if(target == nums[mid])
                return mid;

            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target < nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else{
                if(target > nums[mid] && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }

        return -1;
    }
};