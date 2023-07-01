https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

//Recursive
class Solution{
public:
    int solve(int i, int j, bool isTrue, string &s){
        if(i > j) return 0;
        if(i == j){
            if(isTrue){
                return (s[i] == 'T');
            }else return (s[i] == 'F');
        }
        
        int ans = 0;
        for(int k=i+1; k <= j-1;k+=2){
            int lT = solve(i, k-1, 1, s);
            int lF = solve(i, k-1, 0, s);
            int rT = solve(k+1, j, 1, s);
            int rF = solve(k+1, j, 0, s);
            
            if(s[k] == '|'){
                if(isTrue){
                    ans += lT*rF + lF*rT + lT*rT;
                }else ans += lF*rF;
            }
            
            if(s[k] == '^'){
                if(isTrue){
                    ans += lT*rF + lF*rT;
                }else ans += lF*rF + rT*lT;
            }
            
            if(s[k] == '&'){
                if(isTrue){
                    ans +=  lT*rT;
                }else ans += lT*rF + lF*rT + lF*rF;
            }
        } 
        
        return ans;
        
    }
    int countWays(int N, string S){
        return solve(0,N-1, 1, S);
    }
};



//Memoisation

// User function Template for C++

class Solution{
public:
    int solve(int i, int j, bool isTrue, string &s, vector<vector<vector<int>>>&dp){
        if(i > j) return 0;
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        if(i == j){
            if(isTrue){
                return dp[i][j][isTrue] = (s[i] == 'T');
            }else return dp[i][j][isTrue] = (s[i] == 'F');
        }
        
        int mod = 1003;
        
        int ans = 0;
        for(int k=i+1; k <= j-1;k+=2){
            int lT = solve(i, k-1, 1, s,dp);
            int lF = solve(i, k-1, 0, s,dp);
            int rT = solve(k+1, j, 1, s,dp);
            int rF = solve(k+1, j, 0, s,dp);
            
            if(s[k] == '|'){
                if(isTrue){
                    ans += (lT*rF + lF*rT + lT*rT)%mod;
                }else ans += (lF*rF)%mod;
            }
            
            if(s[k] == '^'){
                if(isTrue){
                    ans += (lT*rF + lF*rT)%mod;
                }else ans += (lF*rF + rT*lT)%mod;
            }
            
            if(s[k] == '&'){
                if(isTrue){
                    ans +=  (lT*rT)%mod;
                }else ans += (lT*rF + lF*rT + lF*rF)%mod;
            }
        } 
        
        return dp[i][j][isTrue] = ans%mod;
        
    }
    int countWays(int n, string S){
       vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
       return solve(0,n-1, 1, S,dp);
    }
};