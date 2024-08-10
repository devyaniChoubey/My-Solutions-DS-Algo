https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=company&envId=google&favoriteSlug=google-thirty-days&difficulty=EASY&status=TO_DO



class Solution {
public:
    bool isValid(string str1, string str2, int k){
        int len1 = str1.size(), len2 = str2.size();
        if(len1%k > 0 || len2%k > 0) return false;
        else{
            int n1 = len1/k;
            int n2 = len2/k;
            string base = str1.substr(0, k);
            string res1 = join(base, n1);
            string res2 = join(base, n2);

            return (res1 == str1 && res2 == str2);
        }
    }

    string join(string base, int n){
        string res = "";
        for(int i=0;i < n;i++){
            res += base;
        }

        return res;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() > str2.size()) return gcdOfStrings(str2, str1);

        int len = str1.size();

        for(int i=len;i >= 1;i--){
            if(isValid(str1, str2 , i)){
                return str1.substr(0, i);
            }
        }

        return "";
    }
};