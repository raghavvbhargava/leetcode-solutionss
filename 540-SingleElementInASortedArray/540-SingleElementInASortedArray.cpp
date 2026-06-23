// Last updated: 6/24/2026, 12:35:36 AM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x: nums){
            mp[x]++;
        }
        for (auto it: mp){
            if (it.second==1) return it.first;
        }
        return -1;
    }
};