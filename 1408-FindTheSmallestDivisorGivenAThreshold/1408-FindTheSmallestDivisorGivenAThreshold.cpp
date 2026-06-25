// Last updated: 6/25/2026, 11:28:43 PM
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int n = nums.size();
       int ans = 0;
       
       int maxi = *max_element(nums.begin(),nums.end());
       if (n==threshold) return maxi;
       int low = 1;
       int high = maxi;
       while(low<=high){
        int sum =0;
        int mid = low+(high-low)/2;
        for(int i =0; i<nums.size();i++){
            sum += ceil((double)nums[i]/mid);
        }
        if (sum>threshold){
                low = mid +1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
       }
       return ans;
    }
};