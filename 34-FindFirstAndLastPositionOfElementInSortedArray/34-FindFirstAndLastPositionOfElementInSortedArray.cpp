// Last updated: 6/20/2026, 5:07:48 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int first = -1;
        int last = -1;
        int high = n-1;
        while (low<=high){
            int mid = (low + high) /2;
            if (nums[mid]==target){
                first = mid;
                high = mid -1;
            } 
            else if (nums[mid]<target){
                low = mid +1;
            }
            else high = mid -1;
        }
        low = 0;
        high = n-1;
        while (low<=high){
            int mid = (low + high) /2;
            if (nums[mid]==target){
                last = mid;
                low = mid + 1;
            } 
            else if (nums[mid]<target){
                low = mid +1;
            }
            else high = mid -1;
        }
        return {first,last};
    }
};