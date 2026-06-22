// Last updated: 6/22/2026, 1:24:27 PM
class Solution {
public:
    bool isValid(string s) {
        
    /* here i have considered parenthese such as )( are also valid, but actually these will be invalid  
    unordered_map<char,int> mp;
        // store value of each paranthesis Character
        mp['('] = 1;
        mp[')'] = -1;
        mp['{'] = 2;
        mp['}'] = -2;
        mp['['] = 3;
        mp[']'] = -3;
     int ans = 0;
     for (int i=0;i<s.length();i++){
        ans += mp[s[i]];

     }  
     if (ans == 0) return true;
     else return false; 
    }*/

    // how i will be using stack if valid parathesis opeing -> store otherwise return fasle
    stack<char> st;
    for (int i = 0; i<s.length(); i++){
        if (s[i]=='(' || s[i] =='{' || s[i] =='['){
            st.push(s[i]);
        }
        else {
            if (st.empty()) return false;
            if (s[i] == ')' && st.top() != '(') return false;
            if (s[i] == '}' && st.top() != '{') return false;
            if (s[i] == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
        return st.empty();
    }
};