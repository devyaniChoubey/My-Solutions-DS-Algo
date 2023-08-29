https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        
        sort(arr, arr+n);
        
        int l=0, r = n-1;
        
        int res = 0;
        
        while(l < r){
            if(arr[l] + arr[r] > k) r--;
            else if(arr[l] + arr[r] < k) l++;
            else{
                if(arr[l] != arr[r]){
                    l++;r--;
                    int a = 1, b = 1;
                    while(l <= r && arr[l] == arr[l-1]) {l++;a++;}
                    while(l <= r && arr[r] == arr[r+1]) {r--;b++;}
                    
                    //cout << a << " " << b << endl;
                    res += a*b;
                }else{
                    int temp = r-l+1;
                    
                    res += (temp * (temp - 1) / 2);
                    break;
                }
            }
        }
        
        return res;
    }
};

//Method 2

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        
       unordered_map<int, int>mp;
        
        int cnt = 0;

        
        for(int i=0;i < n;i++) {
            cnt += mp[k - arr[i]];
            mp[arr[i]]++;
        }
        
        return cnt;
    }
};