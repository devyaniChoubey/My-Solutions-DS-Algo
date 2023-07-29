lowerbound smallest index such that arr[ind] >= target

STL 
int lowerbound = lower_bound(arr.begin(), arr.end() , target) - arr.begin();

class Solution {
public:
    int lowerBound(vector<int> arr, int n, int target) {
        int low = 0, high = n-1;
        int lowerbound = n;

        while(low <= high){
            int mid = (low+high)/2;

            if(arr[mid] >= target){
                lowerbound = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return lowerbound;
    }

};
