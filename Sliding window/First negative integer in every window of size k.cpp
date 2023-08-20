https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    
      long long i=0, j = 0;
      queue<long long>q;
      vector<long long>ans;
      
      while(j < n){
          if(arr[j] < 0) q.push(j);
          
          if(j - i + 1 < k){
              j++;
          }else{
              if(!q.empty()) ans.push_back(arr[q.front()]);
              else ans.push_back(0);
              if(!q.empty() && i == q.front()) q.pop();
              
              i++;j++;
          }
      }
      
      return ans;
 }