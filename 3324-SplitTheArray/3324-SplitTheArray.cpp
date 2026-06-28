// Last updated: 6/28/2026, 11:30:10 PM
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for (auto it: mp){
            if (it.second>2) return false;
        }
        return true;
    }
};