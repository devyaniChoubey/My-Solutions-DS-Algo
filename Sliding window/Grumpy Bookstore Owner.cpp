https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int rightCust = 0, windowCust = 0;

        for(int i=minutes;i < n;i++){
            if(!grumpy[i]) rightCust += customers[i];
        }

        for(int i=0;i < minutes;i++){
            windowCust += customers[i];
        }

        int leftCust = 0;

        int ans = windowCust + rightCust;

        int left = 0, right = minutes-1;

        while(right < n){
           ans = max(ans, leftCust+windowCust+rightCust);
           if(!grumpy[left])leftCust += customers[left];
           windowCust = windowCust - customers[left];
           if(right < n-1) windowCust += customers[right+1];
           if(right < n-1 && !grumpy[right+1])rightCust -= customers[right+1];
           left++;
           right++;
        }

        return ans;
    }
};