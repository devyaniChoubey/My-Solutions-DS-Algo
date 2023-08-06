https://leetcode.com/problems/russian-doll-envelopes/description/


Algorithm
We sort the array in increasing order of width. And if two widths are same, we need to sort height in decreasing order.
Now why we need to sort in decreasing order if two widths are same. By this practice, we're assuring that no width will get counted more than one time. Let's take an example
envelopes=[[3, 5], [6, 7], [7, 13], [6, 10], [8, 4], [7, 11]]
imageNow, if you see for a while,6 and 7 is counted twice while we're calculating the length of LIS, which will give the wrong ans. As question is asking, if any width/height are less than or equal, then, it is not possible to russian doll these envelopes.
Now, we know the problem. So, how can we tackle these conditions when two width are same, so that it won't affect our answer. We can simple reverse sort the height if two width are equal, to remove duplicacy.
Now, you may question, how reverse sorting the height would remove duplicacy? As the name itself says, Longest Increasing Subsequnce, the next coming height would be less than the previous one. Hence, forbidding it to increase length count.
imageIf you don't understand how LIS is calculated here, I strongly refer you to follow the prerequisite.
Now, we havesucessfully reduced the problem to LIS! All you need to apply classical LIS on heights, to calculate the ans. This would be the maximum number of envelopes can be russian doll.

//Refer for solution

https://leetcode.com/problems/russian-doll-envelopes/solutions/2071477/c-java-python-best-explanation-with-pictures/

class Solution {
public:
    bool static sortByWidHeight(vector<int>&a, vector<int>&b){
        if(a[0] < b[0]) return true;
        if(a[0] == b[0]) return (a[1] > b[1]);
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), sortByWidHeight);
        vector<int>dp(n, 1);
        int ans = 1;

        vector<int>lis;
        lis.push_back(envelopes[0][1]);
        for(int i=1;i < n;i++) {
            if(envelopes[i][1] > lis.back()) lis.push_back(envelopes[i][1]);
            else{
                int ind = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
                lis[ind] = envelopes[i][1];
            }
        }
        return lis.size();
    }
};



