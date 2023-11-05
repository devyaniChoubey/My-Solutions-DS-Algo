https://leetcode.com/problems/find-a-peak-element-ii/description/

class Solution {
public:
    int findMaxElInCurCol(vector<vector<int>>& mat, int col){
        int m = mat.size();
        int maxVal = mat[0][col], rowNo = 0;
        for(int i=0;i < m;i++){
            if(maxVal < mat[i][col]){
                maxVal = mat[i][col];
                rowNo = i;
            }
        }

        return rowNo;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low+high)/2;

            int row = findMaxElInCurCol(mat, mid);

            int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
            int right = mid+1 <= n-1 ? mat[row][mid+1] : -1;

            if(left < mat[row][mid] && mat[row][mid] > right) return {row, mid};
            else if(left > mat[row][mid]) high = mid-1;
            else low = mid+1;
        }

        return {};
    }
};