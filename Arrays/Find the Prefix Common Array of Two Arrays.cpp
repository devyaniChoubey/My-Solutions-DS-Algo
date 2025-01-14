https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>seen;
        vector<int>freq(A.size()+1, 0);
        int res = 0;

        vector<int>ans;

        for(int i=0;i < A.size();i++){
            freq[A[i]]++;
            freq[B[i]]++;

            if(A[i] == B[i]) res++;
            else {
                if(freq[A[i]] == 2) res++;
                if(freq[B[i]] == 2) res++;
            }

            ans.push_back(res);

        }

        return ans;


    }
};