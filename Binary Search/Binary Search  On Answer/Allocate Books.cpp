https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution 
{
    public:
    int noOfStudents(int A[], int maxPages,int N){
        int studentsCnt = 1;
        int curPagesCnt = 0;
        
        for(int i=0;i < N;i++){
            if(curPagesCnt + A[i] <= maxPages){
                curPagesCnt = curPagesCnt + A[i];
            }else{
                studentsCnt++;
                curPagesCnt = A[i];
            }
        }
        
        return studentsCnt;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N) return -1;
        int low = *max_element(A, A+N);
        int high = 0;
        high = accumulate(A, A+N, high);
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(noOfStudents(A, mid,N) <= M){
                high = mid-1;
            }else low = mid+1;
        }
        
        return low;
        
        
    }

};
