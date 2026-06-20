// Last updated: 6/20/2026, 5:07:24 PM
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long current = mass;
        for (int x : asteroids){
            if (current<x){
                return false;
            }
            current = current +x;
        }
        return true;
    }
};