https://leetcode.com/problems/sliding-window-maximum/description/


//Solution 1

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0, j = 0;
        deque<int>dq;
        int n = nums.size();

        vector<int>ans;
        
        while(j < n){
            while(!dq.empty() && nums[dq.back()] <= nums[j]) dq.pop_back();
            dq.push_back(j);

            if(j-i+1 < k) j++;
            else{
                ans.push_back(nums[dq.front()]);
                if(dq.front() == i) dq.pop_front();

                i++;
                j++;
            }
            
        }

        return ans;
    }
};


//Solution 2

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        for(int i=0;i < nums.size();i++){
            while(!dq.empty() && dq.front() < i-k+1){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            dq.push_back(i);

            if(i >= k-1)ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};


