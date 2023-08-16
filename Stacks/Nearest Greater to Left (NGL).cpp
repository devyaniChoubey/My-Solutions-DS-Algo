

class Solution {
public:
  vector<int>nearestGreaterToLeft(vector <int> nums) {
    int n = nums.size();
    vector<int>ngl(n, -1);
    stack<int>st;

    for(int i=0;i < n;i++){
        while(!st.empty() && st.top() <= nums[i]) st.pop();

        if(!st.empty()) ngl[i] = st.top();

        st.push(nums[i]);
    }

    return ngl;
  }
};