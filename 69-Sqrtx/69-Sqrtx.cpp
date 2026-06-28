// Last updated: 6/28/2026, 11:38:33 PM
class Solution {
public:
    int mySqrt(int x) {
       int l =0 ;
       int h =x;
       int ans;
       while (l<=h){
        int mid = l + (h-l) /2;
        long long  n = 1LL * mid * mid;
        if (n == x) return mid;
        if (n<x){
            ans = mid;
            l = mid +1;
        }
        else {
            h= mid -1;
        }
       } 
       return ans;
    }
};