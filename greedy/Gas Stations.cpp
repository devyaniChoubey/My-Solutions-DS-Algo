https://leetcode.com/problems/gas-station/description/


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0;
        int cur_gas = 0;
        int starting_point = 0;

        int n = gas.size();

        for(int i=0;i < n;i++){
            total_gas += gas[i];
            total_cost += cost[i];

            cur_gas += (gas[i] - cost[i]);

            if(cur_gas < 0){
                starting_point = i+1;
                cur_gas = 0;
            }
        }

        if(total_cost > total_gas) return -1;
        else{
            return starting_point;
        }
    }
};