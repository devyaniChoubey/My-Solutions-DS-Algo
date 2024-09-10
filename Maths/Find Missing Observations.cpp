https://leetcode.com/problems/find-missing-observations/description/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;

        for(int i=0;i < m;i++) sum += rolls[i];

        int totalSum = (m+n)*mean;

        int remainingSum = totalSum - sum;

        if(remainingSum < n || remainingSum > 6*n) return {};

        int remainingMean =  remainingSum/n;
        int remainingMod = remainingSum%n;

        vector<int>ans(n , remainingMean);
        
        for(int i=0;i < remainingMod;i++){
            ans[i] += 1;
        }

        return ans;
    }
};