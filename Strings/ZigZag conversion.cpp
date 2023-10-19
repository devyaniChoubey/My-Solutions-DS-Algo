https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;
        int n = s.length();

        int sections = ceil(n/(2*numRows - 2.0));
        int numCols = sections*(numRows - 1);
        vector<vector<char>>matrix(numRows , vector<char>(numCols, ' '));

        int curCol = 0, curRow = 0, curStrPos = 0;

        while(curStrPos < n){
            while(curRow < numRows && curStrPos < n){
                matrix[curRow][curCol] = s[curStrPos];
                curRow++;
                curStrPos++;
            }

            curCol++;
            curRow -= 2;

            while(curRow > 0 && curCol < numCols && curStrPos < n){
                matrix[curRow][curCol] = s[curStrPos];
                curCol++;
                curRow--;
                curStrPos++;
            }
        }

        string ans;

        for(auto &row:matrix){
            for(auto &ch:row){
                if(ch != ' ') ans += ch;
            }
        }

        return ans;
        
    }
};


//Method 2 optimised
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string ans;
        int n = s.length();
        int noOfCharInSection = 2*numRows - 2;

        for(int curRow = 0;curRow < numRows;curRow++){
            int index = curRow;

            while(index < n){
                ans += s[index];
                if(curRow != 0 && curRow != numRows-1){
                    int charsInBetween = noOfCharInSection - 2*curRow;
                    int secondIndex = index + charsInBetween;
                    if(secondIndex < n){
                        ans += s[secondIndex];
                    }
                }
                index += noOfCharInSection;
            }
        }

        return ans;
    }
};