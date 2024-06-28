https://leetcode.com/problems/number-of-lines-to-write-string/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int i=0, curWidth = 0, lines = 1;

        while(i < s.length()){
            if(curWidth + widths[s[i] - 'a'] <= 100){
                curWidth += widths[s[i] - 'a'];
                i++;
            }else{
                lines++;
                curWidth = 0;
            }
        }

        return {lines,curWidth};
    }
};