// Last updated: 6/20/2026, 5:07:49 PM
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        // store value of each Roman Character
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        // store in unordered_map as it strore key value pair, and stter comaprinf eith i and i+1
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && mp[s[i]] < mp[s[i + 1]]) {
                ans -= mp[s[i]];
            }
            else {
                ans += mp[s[i]];
            }
        }

        return ans;
    }
};