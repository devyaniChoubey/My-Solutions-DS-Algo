https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/


class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 10000000;
        int ans = 1e9;
        while(low <= high){
            int mid = (low+high)/2;
            double totalTime = 0;
            for(int i=0;i < dist.size()-1;i++){
                totalTime += ceil((double)(dist[i])/(double)(mid));
            }
            totalTime += (double)(dist[dist.size()-1])/(double)(mid);

            

            if(totalTime > hour){
                low = mid+1;
            }else{
                high = mid-1;
                ans = min(ans, mid);
            }
        }
        if(ans != 1e9)return ans;
        else return -1;
    }
};