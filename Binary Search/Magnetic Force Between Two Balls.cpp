https://leetcode.com/problems/magnetic-force-between-two-balls/description/

class Solution {
public:
    bool isPossibleToPlaceBalls(vector<int>& position, int minDist, int m){
        int ballsCount = 1;
        int prev = position[0];

        for(int j=1;j < position.size();j++){
            if(position[j] - prev >= minDist){
                ballsCount++;
                if(ballsCount == m) return true;
                prev = position[j];
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1, high = position[n-1] - position[0];
        int maxDistance = -1e9;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossibleToPlaceBalls(position, mid, m)){
                low = mid+1;
                maxDistance = max(maxDistance, mid);
            }else{
                high = mid-1;
            }
        }
        return maxDistance;
    }
};