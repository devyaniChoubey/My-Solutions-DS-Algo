https://leetcode.com/problems/shifting-letters-ii/?envType=daily-question&envId=2025-01-05

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int>diff(n, 0);

        for(int i=0;i < shifts.size();i++){
            int l = shifts[i][0] , r = shifts[i][1], shift = shifts[i][2];
            
            if(shift == 1){
                diff[l]++;

                if(r < n-1){
                    diff[r+1]--; 
                }
            }

            if(shift == 0){
                diff[l]--;

                if(r < n-1){
                    diff[r+1]++; 
                }
            }
        }

        int numOfShifts = 0;

        for(int i=0;i < s.length();i++){

            numOfShifts = (numOfShifts + diff[i])%26;
            numOfShifts += 26;

            
            s[i]  =  'a' + (s[i] - 'a' + numOfShifts) % 26;
        }

        return s;
    }
};