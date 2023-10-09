https://www.interviewbit.com/problems/connect-ropes/

int Solution::solve(vector<int> &A) {

    // Create a min-heap to store the rope lengths
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto num:A) pq.push(num);
    int totalCost = 0;
    
    while(pq.size() > 1){
        int l1 = pq.top();
        pq.pop();
        int l2 = pq.top();
        pq.pop();
        
        totalCost += l1 + l2;
        
        pq.push(l1 + l2);
    }
    
    return totalCost;
}
