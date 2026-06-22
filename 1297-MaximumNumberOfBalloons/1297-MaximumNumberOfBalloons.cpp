// Last updated: 6/22/2026, 12:45:46 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;

        for (int i = 0; i < text.size(); i++) {
            mp[text[i]]++;
        }

        int ans = min({mp['b'],
                       mp['a'],
                       mp['l'] / 2,
                       mp['o'] / 2,
                       mp['n']});

        return ans;
    }
};