https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m) return kthElement(arr2, arr1, m , n , k);
        
        int low = max(0, k-m), high = min(n, k);
        
        while(low <= high){
            int mid = (low+high)/2;
            
            int l1, l2, r1, r2;
            
            if(mid == 0) l1 = INT_MIN;
            else l1 = arr1[mid-1];
            
            if((k-mid) == 0) l2 = INT_MIN;
            else l2 = arr2[(k-mid-1)];
            
            if(mid == n) r1 = INT_MAX;
            else r1 = arr1[mid];
            
            if((k-mid) == m) r2 = INT_MAX;
            else r2 = arr2[(k-mid)];
            
            if(l1 > r2){
                high = mid-1;
            }else if(l2 > r1){
                low = mid+1;
            }else{
                return max(l1, l2);
            }
        }
        
        return -1;
    }
};