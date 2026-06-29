// Last updated: 6/29/2026, 11:42:01 AM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
       int count = 0;
       for(int i =0; i<patterns.size();i++){
        if(word.find(patterns[i]) != string::npos){
            count++;
        }
       }
       return count;
    }
};