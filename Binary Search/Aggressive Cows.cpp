https://practice.geeksforgeeks.org/problems/aggressive-cows/1

class Solution {
public:
    int isPossibleToPlaceCow(vector<int> &stalls ,int minDist, int k){
        int prev = stalls[0];
        int noCows = 1;
        
        for(int i=1;i < stalls.size();i++){
            if(stalls[i] - prev >= minDist){
                noCows++;
                if(noCows == k) return true;
                prev = stalls[i];
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin() , stalls.end());
        int maxDistance = -1e9;
        int low = 1, high = stalls[n-1] - stalls[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossibleToPlaceCow(stalls,mid, k)){
                low = mid+1;
                maxDistance = max(mid, maxDistance);
            }else{
                high = mid-1;
            }
        }
        return maxDistance;
    }
};