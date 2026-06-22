// Last updated: 6/22/2026, 12:59:44 PM
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long num = x;
        long rev = 0;
        
        while (x>0){
            long digit = x%10;
            rev = rev*10 + digit;
            x = x/10;
        }
        return rev == num;
    }
};