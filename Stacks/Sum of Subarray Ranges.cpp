https://leetcode.com/problems/sum-of-subarray-ranges/description/

//Brute force



class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = -1e9, minVal = 1e9;
        long long sum = 0;
        for(int i=0;i < n;i++){
            maxVal = -1e9, minVal = 1e9;
            for(int j=i;j < n;j++){
                maxVal = max((int)maxVal, nums[j]);
                minVal = min((int)minVal, nums[j]);
                sum += (maxVal - minVal);
            }
        }

        return sum;
    }
};




/*
Let different subarrays be a1, a2, a3, ...
res = [max(a1) - min(a1)] + [max(a2) - min(a2)] + [max(a3) - min(a3)] + ...
res = [max(a1) + max(a2) + max(a3) + ...] - [min(a1) + min(a2) + min(a3) + ...]
*/


//Optimised

class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nle(n, n), ple(n, -1);

        stack<int>st;
        for(int i=0;i < n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()) ple[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i >= 0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) nle[i] = st.top();
            st.push(i);
        }

        long long sum = 0;
        int mod = 1e9 +7;

        for(int i=0;i < n;i++){
            long long numsLeft = i-ple[i];
            long long numsRight = nle[i] - i;

            sum = sum + arr[i]*numsLeft*numsRight;
        }

        return sum;
    }


    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int>nge(n, n), pge(n, -1);

        stack<int>st;
        for(int i=0;i < n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if(!st.empty()) pge[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i >= 0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        long long sum = 0;
        int mod = 1e9 +7;

        for(int i=0;i < n;i++){
            long long numsLeft = i-pge[i];
            long long numsRight = nge[i] - i;

            sum = (sum + arr[i]*numsLeft*numsRight);
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};