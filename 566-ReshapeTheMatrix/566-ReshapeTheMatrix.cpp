// Last updated: 6/20/2026, 5:07:38 PM
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        if (r*c != row*col) return mat;

        vector<vector<int>> ans(r,vector<int>(c));
        int index = 0;
        for (int i = 0;i<r;i++){
            for (int j=0;j<c;j++){
                ans[i][j]=mat[index/col][index%col];
                index++;
            }
        }
        return ans;
    }
};