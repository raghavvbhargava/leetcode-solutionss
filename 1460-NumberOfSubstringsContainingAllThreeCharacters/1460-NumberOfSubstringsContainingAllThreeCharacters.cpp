// Last updated: 6/30/2026, 9:12:36 AM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') a = i;
            else if (s[i] == 'b') b = i;
            else c = i;

            if (a != -1 && b != -1 && c != -1) {
                count += min(a, min(b, c)) + 1;
            }
        }

        return count;
    }
};