https://leetcode.com/problems/buildings-with-an-ocean-view/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>ans;

        stack<int>st;

        int n = heights.size();


        for(int i=n-1;i >= 0;i--){
            if(!st.empty() && st.top() >= heights[i]){}
            else{
                ans.push_back(i);
                st.push(heights[i]);
            }
        }

        sort(ans.begin() , ans.end());

        return ans;
    }
};


//method 2

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>ans;

        int maxHeight = 0;

        int n = heights.size();


        for(int i=n-1;i >= 0;i--){
            if(heights[i] > maxHeight) ans.push_back(i);
            maxHeight = max(maxHeight, heights[i]);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};