https://leetcode.com/problems/magnetic-force-between-two-balls/description/

class Solution {
public:
    int noOfBalls(vector<int>& position, int minDist){
        int ballCnt = 1;
        int lastBallPos = position[0];

        for(int i=1;i < position.size();i++){
            if(position[i] >= lastBallPos + minDist) {
                ballCnt++;
                lastBallPos = position[i];
            }
        }

        return ballCnt;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin() , position.end());
        int n = position.size();
        int low = 1, high = position[n-1] - position[0];

        while(low <= high){
            int mid = (low+high)/2;

            if(noOfBalls(position,mid) >= m){
                low = mid+1;
            }else high = mid-1;
        }

        return high;
    }
};