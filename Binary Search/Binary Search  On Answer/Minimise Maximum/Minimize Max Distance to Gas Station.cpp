https://leetcode.com/problems/minimize-max-distance-to-gas-station/description/

//Brute Force TLE

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        int n = stations.size();

        vector<int>howMany(n, 0);
        for(int gasSt=0;gasSt < k;gasSt++){
            double maxDist = -1e9; int maxInd = -1;
            for(int i=0;i < n-1;i++){
                double diff = stations[i+1] - stations[i];
                double sectionLength = diff/((double)(howMany[i]+1));

                if(maxDist < sectionLength){
                    maxDist = sectionLength;
                    maxInd = i;
                }
            }

            howMany[maxInd]++;
        }
        double ans = DBL_MIN;
        for(int i=0;i < n-1;i++){
            double diff = stations[i+1] - stations[i];
            double sectionLength = diff/(double)(howMany[i] + 1);
            if(ans < (sectionLength)){
               ans = sectionLength;
            }
        }

        return ans;
    }
};





//Priority Queue TLE

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        int n = stations.size();
        priority_queue<pair<long double, int>>pq;

        vector<int>howMany(n, 0);

        for(int i=0;i < n-1;i++){
           long double diff = stations[i+1] - stations[i];
           long double sectionLength = diff/(long double)(howMany[i] + 1);
           pq.push({sectionLength , i});
        }
        
        for(int gasSt=0;gasSt < k;gasSt++){
            double maxDist = -1e9; int maxInd = -1;
             
            maxInd = pq.top().second;
            howMany[maxInd]++;
            pq.pop();

            long double diff = stations[maxInd+1] -  stations[maxInd];
            long double sectionLength = diff/(long double)(howMany[maxInd]+1);

            pq.push({sectionLength, maxInd});
        }

        return pq.top().first;
    }
};




//Binary Search
class Solution {
public:
    int cntGasStations(vector<int>& stations, double maxDist){
        int gasStationsCnt = 0;
        int n = stations.size();

        for(int i=0;i < n-1;i++){
            double diff = (double)(stations[i+1] - stations[i]);
            int numberInBetween = diff/maxDist;
            if(diff == maxDist*numberInBetween){
                numberInBetween--;
            }
            gasStationsCnt += numberInBetween;
        }

        return gasStationsCnt;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        int n = stations.size();
        double low = 0;
        double high = (double)(stations[n-1] - stations[0]);

        double diff = 1e-6;

        while(high - low > diff){
            double mid = (low+high)/2.0;

            if(cntGasStations(stations, mid) <= k){
                high = mid;
            }else{
                low = mid;
            }
        }

        return low;
    }
};