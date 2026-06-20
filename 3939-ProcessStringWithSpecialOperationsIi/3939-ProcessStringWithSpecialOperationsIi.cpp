// Last updated: 6/20/2026, 5:07:04 PM
class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len(s.size());
        long long curr = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            
            if (ch >= 'a' && ch <= 'z') {
                curr++;
            }
            else if (ch == '*') {
                if (curr > 0) curr--;
            }
            else if (ch == '#') {
                curr = curr * 2;
            }
            else if (ch == '%') {
            }
            
            len[i] = curr;
        }
        
        if (k >= curr) return '.';
        
        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];
            long long currLen = len[i];
            
            if (ch >= 'a' && ch <= 'z') {
                if (k == currLen - 1) return ch;
            }
            else if (ch == '*') {
                continue;
            }
            else if (ch == '#') {
                long long oldLen = currLen / 2;
                if (k >= oldLen) k -= oldLen;
            }
            else if (ch == '%') {
                k = currLen - 1 - k;
            }
        }
        
        return '.';
    }
};