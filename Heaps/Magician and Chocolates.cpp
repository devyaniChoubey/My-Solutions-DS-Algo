https://www.interviewbit.com/problems/magician-and-chocolates/

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int>pq;
    
    for(int num:B) pq.push(num);
    
    long long totalChoco = 0;
    
    int mod = 1e9 + 7;
    
    while(A > 0 && !pq.empty()){
        int curChoco = pq.top();
        totalChoco += curChoco;
        pq.pop();
        
        pq.push(curChoco/2);
        A--;
    }
    
    return totalChoco % mod;
}
