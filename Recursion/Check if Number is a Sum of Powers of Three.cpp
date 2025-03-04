https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/?envType=daily-question&envId=2025-03-04

class Solution {
public:
    bool solve(int n, int sum){
        if(sum == 0) return true;

        if(pow(3, n) > sum) return false;

        bool includePower = solve(n+1, sum - pow(3, n));
        bool skipPower = solve(n+1, sum);
        

        return includePower || skipPower;
    }
    bool checkPowersOfThree(int n) {
        return solve(0, n);
    }
};