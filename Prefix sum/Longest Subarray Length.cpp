https://www.interviewbit.com/problems/longest-subarray-length/

int Solution::solve(vector<int> &A) {
    unordered_map<int, int>prefixSumMap;  
    int prefixSum = 0;  //will store difference between count of 1 and count of 0
    int maxLen = 0;

    for (int i = 0; i < A.size(); ++i) {
        if(A[i] == 1) prefixSum++;
        else if(A[i] == 0) prefixSum--;
        
        if(prefixSum == 1) maxLen = max(maxLen, i+1);
        
        if(prefixSumMap.find(prefixSum - 1) != prefixSumMap.end()){
            maxLen = max(maxLen, i - prefixSumMap[prefixSum - 1]);
        }
        
        if(prefixSumMap.find(prefixSum) == prefixSumMap.end()) prefixSumMap[prefixSum] = i;
    }

    return maxLen;
}
