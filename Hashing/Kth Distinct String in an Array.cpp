https://leetcode.com/problems/kth-distinct-string-in-an-array/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>freq;

        for(string &s:arr) freq[s]++;

        int i=1;

        for(string &s:arr){
            if(freq[s] == 1){
                if(i == k) return s;
                i++;
            }
        }

        return "";
    }
};