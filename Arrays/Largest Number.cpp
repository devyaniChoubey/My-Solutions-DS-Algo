https://leetcode.com/problems/largest-number/description/

string Solution::largestNumber(const vector<int> &nums) {
    vector<string>arr;

    for(auto num:nums){
        arr.push_back(to_string(num));
    }

    sort(arr.begin() , arr.end()  , [](string &s1, string &s2) {
        return s1 + s2 > s2 + s1;
    });

    string res;

    for(string &s:arr){
        res += s;
    }

    while(res.size() > 1 && res[0] == '0'){
        res.erase(res.begin());
    }

    return res;
}


Find Permutation


class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.length();

        vector<int>res(n+1);

        for(int i=0;i <= n;i++) res[i] = i+1;

        int i = 1, j;

        while(i <= n+1){
            j = i;

            while(i <= n && s[i-1] == 'D') i++;

            reverse(res.begin() + j - 1, res.begin() + i);

            i++;
        }

        return res;
    }
};


