https://leetcode.com/problems/kth-missing-positive-number/description/

https://www.youtube.com/watch?v=uZ0N_hZpyps&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=17


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            //missedNo on left of mid
            int missedNo = arr[mid] - (mid+1);

            if(k > missedNo){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        //k - (arr[high] - (high+1)) + arr[high]
        return k + (high+1);
    }
};