https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int cntF = 0, cntT = 0;
        int left = 0, right = 0, n = answerKey.size();
        int ans = 0;

        while(right < n){
            if(answerKey[right] == 'F') cntF++;
            
            if(cntF > k){
               if(answerKey[left] == 'F') cntF--;
               left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }


        left = 0, right = 0;

        while(right < n){
            if(answerKey[right] == 'T') cntT++;
            
            if(cntT > k){
               if(answerKey[left] == 'T') cntT--;
               left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;


    }
};