https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/

https://youtu.be/hVl2b3bLzBw

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            
            int left = n - 1, right = 0;
            
            while(left >= 0 && right < m){
                if(arr1[left] >= arr2[right]) {
                    swap(arr1[left], arr2[right]);
                    left--;right++;
                }
                else break; 
            }
            
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        } 
};


/*
The intuition behind this is SHELL SORT
*/


//Gap Method
class Solution{
    public:
        //Function to merge the arrays.
        
        void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
            if(arr1[ind1] > arr2[ind2]) swap(arr1[ind1], arr2[ind2]);
        }
        
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            
            int len = (n+m);
            
            int gap = len/2 + len%2;
            
            while(gap > 0){
                int left = 0, right = left + gap;
                
                while(right < len){
                    
                    if(left < n && right < n){
                        //arr1 arr1
                        swapIfGreater(arr1, arr1, left, right);
                        
                    }else if(left < n && right >= n){
                        //arr1 arr2
                        swapIfGreater(arr1, arr2, left, right - n);
                        
                    }else if(left >= n && right >= n){
                        //arr2 arr2
                        swapIfGreater(arr2, arr2, left - n, right - n);
                    }
                    
                    left++;right++;
                }
                
                if(gap == 1) break;
                
                gap = gap/2 + gap%2;
            }
        } 
};