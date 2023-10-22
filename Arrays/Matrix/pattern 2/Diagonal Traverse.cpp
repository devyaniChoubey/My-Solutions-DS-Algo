https://leetcode.com/problems/diagonal-traverse/description/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty()) return {};

        int m = mat.size(), n = mat[0].size();

        vector<int>ans;

        for(int s=0;s <= (n+m-2);s++){
            for(int x=0;x <= s;x++){
                int i = x;
                int j = s - i;

                if(s % 2 == 0) swap(i, j);

                if(i >= m || j >= n) continue;

                ans.push_back(mat[i][j]);
            }
        }

        return ans;
    }
};