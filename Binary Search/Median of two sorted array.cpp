https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n;
        int total = (n+m+1)/2;

        while(low <= high){
            int mid = (low + high)/2;
            int l1, l2, r1,r2;

            if(mid == 0) l1 = INT_MIN;
            else l1 = nums1[mid-1];

            if((total-mid) == 0) l2 = INT_MIN;
            else l2 = nums2[(total-mid) - 1];

            if(mid == n) r1 = INT_MAX;
            else r1 = nums1[mid];

            if((total-mid) == m) r2 = INT_MAX;
            else r2 = nums2[(total-mid)];

            if(l1 > r2) high = mid-1;
            else if(l2 > r1) low = mid + 1;
            else{
                if((n+m) % 2 == 0){
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }else{
                    return max(l1, l2);
                }
            }
        }
        
        return -1;

    }
};