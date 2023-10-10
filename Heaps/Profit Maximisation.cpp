https://www.interviewbit.com/problems/profit-maximisation/

int Solution::solve(vector<int> &nums, int target) {
    priority_queue<int>pq;
    
    for(int num:nums) pq.push(num);
    
    int totalProfit = 0;
    
    while(target > 0 && !pq.empty()){
        int curCost = pq.top();
        totalProfit += curCost;
        pq.pop();
        target--;
        pq.push(curCost - 1);
    }
    
    return totalProfit;
}
