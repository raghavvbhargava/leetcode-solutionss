// Last updated: 6/20/2026, 5:06:56 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        // Store indices for each value
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // Process each value
        for (auto& it : mp) {
            vector<int>& indices = it.second;
            
            if (indices.size() < 3) continue;
            
            // Sliding window of size 3
            for (int i = 0; i + 2 < indices.size(); i++) {
                int dist = 2 * (indices[i + 2] - indices[i]);
                ans = min(ans, dist);
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};