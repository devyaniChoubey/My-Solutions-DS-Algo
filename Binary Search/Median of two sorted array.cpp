https://leetcode.com/problems/median-of-two-sorted-arrays/

//2 pointers merge sort

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>merged(n1+n2);

        int k = 0;

        int i=0, j=0;

        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                merged[k++] = nums1[i];
                i++;
            }else{
                merged[k++] = nums2[j];
                j++;
            }
        }

        while(i < n1){
            merged[k++] = nums1[i];
            i++;
        }

        while(j < n2){
            merged[k++] = nums2[j];
            j++;
        }

        int n = n1 + n2;


        if(n % 2 == 0){
            return ((merged[n/2] + merged[(n/2) - 1])/2.0);
        }else return (double)merged[n/2];
    }
};


//2 pointer merge sort without extra space

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>merged(n1+n2);

        int k = 0;

        int n = n1 + n2;

        int ind1 = n/2;
        int ind2 = (n/2) - 1;

        int el1, el2;

        int i=0, j=0;

        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                if(k == ind1) el1 = nums1[i];
                if(k == ind2) el2 = nums1[i];
                i++;
            }else{
                if(k == ind1) el1 = nums2[j];
                if(k == ind2) el2 = nums2[j];
                j++;
            }

            k++;
        }

        while(i < n1){
            if(k == ind1) el1 = nums1[i];
            if(k == ind2) el2 = nums1[i];
            i++;
            k++;
        }

        while(j < n2){
            if(k == ind1) el1 = nums2[j];
            if(k == ind2) el2 = nums2[j];
            j++;
            k++;
        }

        if(n % 2 == 0){
            return ((el1+el2)/2.0);
        }else return (double)el1;
    }
};




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