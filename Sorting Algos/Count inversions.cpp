https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long cnt = 0;
    void merge(long long arr[], long long start,long long mid, long long end){
       long long temp[end-start+1];
        
        long long i = start;
        long long j = mid+1;
        
        long long k = 0;
        
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                cnt += mid - i + 1;
                temp[k++] = arr[j++];
            }
        }
        
        while(j <= end){
            temp[k++] = arr[j++];
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        
        k = 0;
        
        for(int i=start;i <= end;i++){
            arr[i] = temp[k++];
        }
    }
    
    void mergeSort(long long arr[], long long start, long long end){
         long long mid = (start+end)/2;

         if(start >= end) return;
         
         mergeSort(arr, start, mid);
         mergeSort(arr, mid+1, end);
         merge(arr, start, mid, end);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        cnt = 0;
        mergeSort(arr,0, N-1);
        return cnt;
    }

};