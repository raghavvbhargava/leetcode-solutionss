// Last updated: 6/26/2026, 12:05:51 AM
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high;
        int SumOfWeight =0;
        
        int ans =-1;
        int low = *max_element(weights.begin(),weights.end());
        int n=weights.size();
        for (int i =0;i<n;i++){
            SumOfWeight += weights[i];
        }
        high = SumOfWeight;
        while (low<=high){
            int count = 1;
            int sumPerDay = 0;
            int mid = low + (high-low) /2;
            for (int i =0;i<n;i++){
                if(sumPerDay + weights[i]<=mid){
                    sumPerDay += weights[i];
                }
                else {
                    count++;
                    sumPerDay = weights[i];
                }
            
        }
        if (count <= days){
                ans = mid;
                high = mid -1;
                
            }
            else {
                low = mid +1;
            }
        }
        return ans;
    }
};