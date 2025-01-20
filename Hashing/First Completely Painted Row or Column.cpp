https://leetcode.com/problems/first-completely-painted-row-or-column/?envType=daily-question&envId=2025-01-20

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>rowCount(n, 0), colCount(m, 0);
        vector<pair<int,int>>seen(n*m+1);


        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                seen[mat[i][j]] = {i, j};
            }
        }

        for(int i=0;i < m*n;i++){
            int row = seen[arr[i]].first;
            int col = seen[arr[i]].second;
            rowCount[row]++;
            colCount[col]++;

            if(rowCount[row] == m || colCount[col] == n) return i;
        }

        return -1;
    }
};