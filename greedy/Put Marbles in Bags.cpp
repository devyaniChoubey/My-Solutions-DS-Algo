https://leetcode.com/problems/put-marbles-in-bags/?envType=daily-question&envId=2025-03-31

class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = weights.size();
    
            vector<int>pairsSum(n-1, 0);
    
            for(int i=0;i < n-1;i++){
                pairsSum[i] += (weights[i] + weights[i+1]);
            }
    
            sort(pairsSum.begin() , pairsSum.end());
    
            long long answers = 0;
    
            for(int i=0;i < k-1;i++){
                answers += pairsSum[n-2-i] - pairsSum[i];
            }
    
            return answers;
        }
    };