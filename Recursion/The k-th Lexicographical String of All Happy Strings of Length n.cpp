https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution {
public:
    string solve(int n, int ind, string &temp, int &k){
        if(ind >= n){
            k--;
            if(k == 0) return temp;
            return "";
        }

        for(char c='a';c <= 'c';c++){
            if(ind > 0 && temp[ind-1] == c) continue;

            temp.push_back(c);
            string ans = solve(n, ind+1, temp, k);
            if(ans != "") return ans;
            
            temp.pop_back();
        }

        return "";
    }
    string getHappyString(int n, int k) {
        string temp = "";
        return solve(n, 0, temp,k);
    }
};