// Last updated: 6/25/2026, 12:52:26 AM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
       
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > maxi) {
            maxi = piles[i];
            }
        }
        long long low = 1;
        long long  high = maxi;
        long long  ans = maxi;
        long long  hr;
        while(low<=high){
            long long mid =low+(high-low)/2;
            long long hr_taken =0;
            for(int i=0;i<piles.size();i++){
                hr = (piles[i]+mid-1)/mid;
                hr_taken += hr;
            }
                if (hr_taken>h){
                    low = mid +1;
                    
                }
                else {
                    ans = mid;
                    high = mid-1; }
                }
            
                
        return ans;
    }
};