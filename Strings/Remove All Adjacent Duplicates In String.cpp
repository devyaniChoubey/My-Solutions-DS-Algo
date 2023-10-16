https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

class Solution {
public:
    string removeDuplicates(string s) {
        string dq;

        for(char c:s){
            if(dq.size() && dq.back() == c){
                dq.pop_back();
            }else dq.push_back(c);
        }

        return dq;
    }
};