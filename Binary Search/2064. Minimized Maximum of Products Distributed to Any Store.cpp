
https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/

Intuition
The key is to find out it should solve with the binary search.
Very similar to

Find the Smallest Divisor Given a Threshold
Koko Eating Bananas
Explanation
Binary search the products distributed to every store.
The search range it between left = 1 and right = 100000.
We can also use right = max(A), no big difference.

For a products to distributed,
we needs ceil(A[i] / mid) store,
I use (a + mid - 1) / mid to calculate this.

We sum up the stores we needs and check whether we have that enough stores.
If we have enough stores,
mid is big enough.
then change high = mid-1

If we have no enough stores,
mid is too small,
then change low = mid + 1


class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = -1e9;
        for(auto it:quantities){
            high = max(it, high);
        }

        int minVal = 1e9;

        while(low <= high){
            int mid = (low+high)/2;
            int storesNo = 0;
            for(auto it:quantities){
               storesNo += (it-1)/mid;
                storesNo++;
            }

            if(storesNo > n){
                low = mid+1;
            }else{
                high = mid-1;
                minVal = min(minVal, mid);
            }
        }
        return minVal;
    }
};