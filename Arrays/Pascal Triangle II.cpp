https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>row(rowIndex+1, 1);


        for(int i=0;i <= rowIndex;i++){
            for(int j=i-1;j >= 1;j--){
                row[j] += row[j-1];
            }
        }

        return row;
    }
};