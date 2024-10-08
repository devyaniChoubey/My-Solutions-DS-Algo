https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/


//Space O(2*N)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>frontPrefixSum(n+1, 0);
        vector<int>backPrefixSum(n+1, 0);
        for(int i=1;i <= n;i++){
            frontPrefixSum[i] = cardPoints[i-1] + frontPrefixSum[i-1];
        }

        for(int i=n-1;i >= 0;i--){
            backPrefixSum[n-i] = cardPoints[i] + backPrefixSum[n-i-1];
        }

        int maxPoints = 0;

        for(int i=0;i <= k; i++){
            maxPoints = max(maxPoints, frontPrefixSum[i] + backPrefixSum[k-i]);
        }

        return maxPoints;
    }
};


//Space O(N)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>frontPrefixSum(n+1, 0);

        for(int i=1;i <= n;i++){
            frontPrefixSum[i] = cardPoints[i-1] + frontPrefixSum[i-1];
        }

        int maxPoints = 0;

        for(int i=0;i <= k; i++){
            maxPoints = max(maxPoints, frontPrefixSum[i] + frontPrefixSum[n] - frontPrefixSum[n - (k - i)]);
        }

        return maxPoints;
    }
};

//O(1) Space

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int startingIndex = 0;
        int presentSubarrayScore = 0;
        int n = cardPoints.size();
        int totalScore = 0;
        int requiredSubarrayLength = n-k;

        int minSubarrayScore = 1e9;

        for(int point:cardPoints) totalScore += point;

        if(k == n) return totalScore;

        for(int i=0;i < n;i++){
            presentSubarrayScore += cardPoints[i];
            if(i - startingIndex + 1 == requiredSubarrayLength){
                minSubarrayScore = min(minSubarrayScore, presentSubarrayScore);
                presentSubarrayScore -= cardPoints[startingIndex++];
            }
        }

        return totalScore - minSubarrayScore;

    }
};