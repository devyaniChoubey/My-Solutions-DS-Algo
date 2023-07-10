https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
    public:
    void solve(int ind, vector<int> &arr, vector<int>&ans, int sum){
        int n = arr.size(); 
        if(ind >= n){
            ans.push_back(sum);
            return;
        }
        
        solve(ind+1, arr, ans, sum+arr[ind]); //take element present at ith index
        solve(ind+1, arr, ans, sum); //not take element present at ith index
    }
    vector<int> subsetSums(vector<int> arr, int N)
    { 
        vector<int>ans;
        solve(0, arr, ans, 0);
        sort(arr.begin(), arr.end());
        return ans;
    }
}