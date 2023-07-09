https://leetcode.com/problems/assign-cookies/description/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0;int j = 0;
        while(i < g.size()){
            if(j >= s.size()) break;
            if(s[j]>= g[i]){
                i++;
                j++;
            }else j++;
        }

        return i;
    }
};