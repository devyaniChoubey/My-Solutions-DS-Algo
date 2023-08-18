https://leetcode.com/problems/sum-of-subarray-minimums/description/


How can the monotonous increase stack be applied to this problem?
For example:
Consider the element 3 in the following vector:

[2, 9, 7, 8, 3, 4, 6, 1]
 |                    |
 the previous less   the next less 
 element of 3        element of 3

After finding both NLE and PLE of 3, we can determine the
distance between 3 and 2(previous less) , and the distance between 3 and 1(next less).
In this example, the distance is 4 and 3 respectively.

How many subarrays with 3 being its minimum value?
The answer is 4*3.

9 7 8 3 
9 7 8 3 4 
9 7 8 3 4 6 
7 8 3 
7 8 3 4 
7 8 3 4 6 
8 3 
8 3 4 
8 3 4 6 
3 
3 4 
3 4 6
How much the element 3 contributes to the final answer?
It is 3*(4*3).


// The last thing that needs to be mentioned for handling duplicate elements:
// Method: Set strict less and non-strict less(less than or equal to) for finding NLE and PLE respectively. The order doesn't matter.

// For example, the above code for finding NLE is strict less, while PLE is actually non-strict less.




//Solution 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
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

           sum = (sum + arr[i]*numsLeft*numsRight)%mod;
        }

        return sum;
    }
};