// Last updated: 6/20/2026, 5:07:43 PM
class Solution {
public:
    int uniquePaths(int m, int n) {
        // We calculate the combination C(m + n - 2, m - 1)
        long long result = 1;
        
        // We take the smaller of (m - 1) or (n - 1) to reduce the number of iterations
        int k = min(m - 1, n - 1);
        
        // Compute the combination (m + n - 2) choose (m - 1) by iterating step-by-step
        for (int i = 1; i <= k; ++i) {
            result = result * (m + n - 2 - (k - i)) / i;  // Intermediate division keeps the result safe
        }
        
        return (int)result;  // Cast to int since the result is guaranteed to fit within the int range
    }
};
