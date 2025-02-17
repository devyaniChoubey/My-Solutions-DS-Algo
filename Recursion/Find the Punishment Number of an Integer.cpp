https://leetcode.com/problems/find-the-punishment-number-of-an-integer/?envType=daily-question&envId=2025-02-15

class Solution {
public:
    bool isValid(int ind,string num, int target){
        if(ind == num.size() && target == 0) return true;
        int leftNum = 0;

        for(int i=ind;i < num.size();i++){
            leftNum = leftNum*10 + (num[i] - '0');

            bool canPartition = isValid(i+1, num, target - leftNum);

            if(canPartition){
                return true;
            }
        }

        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i <= n;i++){
            if(isValid(0,to_string(i*i), i)){
                ans += (i*i);
            }
        }

        return ans;
    }
};