

class Solution {
    public:
        long long carsRepaired(vector<int>& ranks, long long time){
            long long cars = 0;
            int n = ranks.size();
    
            for(int i=0;i < n;i++){
                cars += (long long)sqrt(time/ranks[i]);
            }
    
            return cars;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long low = 0, high = LONG_MAX;
    
            while(low <= high){
                long long mid = (low + high)/2;
    
                if(carsRepaired(ranks, mid) >= cars){
                    high = mid-1;
                }else low = mid+1;
            }
    
            return low;
        }
    };