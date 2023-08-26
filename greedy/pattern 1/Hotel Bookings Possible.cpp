https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin() , arrive.end());
    sort(depart.begin() , depart.end());
    
    int arrive_ptr = 0, depart_ptr = 0;
    int n = arrive.size();
    
    int rooms = 0;
    
    while(arrive_ptr < n){
        if(arrive[arrive_ptr] <= depart[depart_ptr]) rooms++;
        else depart_ptr++;
        
        arrive_ptr++;
        
    }
    
    if(rooms <= K) return true;
    return false;
    
}