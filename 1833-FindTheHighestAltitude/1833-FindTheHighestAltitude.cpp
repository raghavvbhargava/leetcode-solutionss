// Last updated: 6/20/2026, 5:07:29 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int atl = 0;
        int high_alt = 0;
     for (int i = 0;i<gain.size();i++){
        atl += gain[i];
        high_alt = max(atl,high_alt);
     }   
     return high_alt;
    }
};