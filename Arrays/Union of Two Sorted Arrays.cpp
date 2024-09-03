https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays
Union of Two Sorted Arrays

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int a[], int b[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        
        int i = 0;
        int j = 0;
        
        vector<int>ans;
        
        while(i < n && j < m){
            if(a[i] <= b[j]) {
                if(ans.size() == 0 || ans.back() != a[i])ans.push_back(a[i]);
                i++;
            }else{
                if(ans.size() == 0 || ans.back() != b[j])ans.push_back(b[j]);
                j++;
            }
        }
        
        while(i < n){
            if(ans.size() == 0 || ans.back() != a[i])ans.push_back(a[i]);
            i++;
        }
        
        while(j < m){
            if(ans.size() == 0 || ans.back() != b[j])ans.push_back(b[j]);
            j++;
        }
  
        return ans;
        
        
    }
};