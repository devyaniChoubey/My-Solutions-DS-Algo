https://leetcode.com/problems/maximum-performance-of-a-team/description/

/*
It is tough to maintain both sum of speed and minimum of efficiency and to find optimal answer
In this type of questions we have to fix a parameter, here we can fix minimum efficiency
If we sort {efficiency,speed} in decreasing efficiency, we know for ith efficiency, since everything from 1 to i-1
is more than it, ith is the minimum. So from 1 to i-1 if we have the sum of best k-1 speeds we can team them
with ith and we do this for every i and keep taking its maximum.
Note that to find topk sum we can use a heap and maintain its size as less than equal to k and also
keep track of sum of the elements present in heap
*/


class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>v;

        for(int i=0;i < n;i++){
            v.push_back({efficiency[i] , speed[i]});
        }
        
        // sorting in decreasing order of efficiency
        sort(v.rbegin(), v.rend());

        priority_queue <int, vector<int>, greater<int> > pq;


        // running top k sum
        long long speedSum = 0;

        long long ans = INT_MIN;

       
        for(int i=0;i < n;i++){
            pq.push(v[i].second);

            speedSum += v[i].second;
            
            if(pq.size() > k){
                speedSum -= pq.top();
                pq.pop();
            }

            ans = max(ans, speedSum*(long long)v[i].first);
        }

        // finally taking mod

        long long mod = 1e9 + 7;

        return ans % mod;
    }
};