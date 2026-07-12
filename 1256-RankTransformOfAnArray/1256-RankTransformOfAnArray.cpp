// Last updated: 7/12/2026, 4:18:51 PM
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int> temp = arr;
       sort(temp.begin(),temp.end());
       unordered_map<int,int> mp;
       int rank = 1;
        for (int x:temp){
            if(!mp.count(x)){
                mp[x]=rank++;
            }
        }
        for (int i =0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};