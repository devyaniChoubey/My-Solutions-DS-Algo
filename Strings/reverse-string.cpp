https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(left <= right){
            swap(s[left++] , s[right--]);
        }
    }
};