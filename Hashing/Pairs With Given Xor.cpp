https://www.interviewbit.com/problems/pairs-with-given-xor/

int Solution::solve(vector<int> &nums, int target) {
    int count = 0;
    unordered_map<int,int>freq;
    
    for(int num:nums){
        int complement = target^num;
        
        if(freq.find(complement) != freq.end()){
            count += freq[complement];
        }
        
        freq[num]++;
    }
    
    return count;
}
