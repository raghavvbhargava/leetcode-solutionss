// Last updated: 6/21/2026, 10:47:22 AM
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {
            if (coins < cost)
                break;

            coins -= cost;
            count++;
        }

        return count;
    }
};