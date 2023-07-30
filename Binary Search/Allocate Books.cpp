https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int StudentCnt(int A[],int N, int maxPages){
        long long pages = 0;
        int studentCnt = 1;
        for(int i=0;i < N;i++){
            if(pages+A[i] > maxPages){
                studentCnt++;
                pages = A[i];
            }else pages += A[i];
        }
        return studentCnt;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N) return -1;
        int high = 0, low = -1e9;
        for(int i=0;i < N;i++){
            high += A[i];
            low = max(A[i], low);
        }
        
        while(low <= high){
            int mid = (low+high)/2;
            if(StudentCnt(A,N, mid) > M){
               low = mid+1;
            }else if(StudentCnt(A,N, mid) <= M){
                high = mid-1;
            }
        }
        return low;
    }
};