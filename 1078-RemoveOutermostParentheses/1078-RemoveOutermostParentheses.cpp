// Last updated: 6/29/2026, 2:03:12 AM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                if (count > 0) {
                    ans += c;
                }
                count++;
            }
            else {
                count--;
                if (count > 0) {
                    ans += c;
                }
            }
        }
        return ans;
    }
};