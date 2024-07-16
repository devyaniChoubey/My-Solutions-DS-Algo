https://leetcode.com/problems/average-waiting-time/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = customers[0][1];

        int endTime = customers[0][0] + customers[0][1];

        for(int i=1;i < customers.size();i++){
            int startTime = max(endTime, customers[i][0]);
            endTime = startTime + customers[i][1];

            sum += endTime - customers[i][0];
        }

        return sum/customers.size();
    }
};