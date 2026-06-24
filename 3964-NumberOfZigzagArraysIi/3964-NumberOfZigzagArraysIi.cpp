// Last updated: 6/24/2026, 10:24:46 AM
class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        Matrix U(m, vector<long long>(m, 0));
        Matrix D(m, vector<long long>(m, 0));

        // U[i][j] = 1 if j < i
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                U[i][j] = 1;
            }
        }

        // D[i][j] = 1 if j > i
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                D[i][j] = 1;
            }
        }

        long long steps = n - 1;

        Matrix UD = multiply(U, D);
        Matrix V = power(UD, steps / 2);

        if (steps & 1) {
            V = multiply(V, U);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans = (ans + V[i][j]) % MOD;
            }
        }

        ans = (ans * 2) % MOD;
        return (int)ans;
    }
};