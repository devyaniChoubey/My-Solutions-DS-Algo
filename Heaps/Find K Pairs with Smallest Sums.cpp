//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation


/*
Basic idea: 
Use min_heap to keep track on next minimum pair sum, 
and we only need to maintain K possible candidates in the data structure.

Think with respect to i variable and not both i, j variables

Some observations: 
i) For every numbers in nums1, its best partner (yields min sum) always strats from nums2[0] since arrays are all sorted.
ii) And for a specific number in nums1, its next candidate sould be [this specific number] + nums2[current_index + 1]

The run time complexity is O(kLogk) since que.size <= k and we do at most k loop.
The above solution is essentially a multiple-way merge sort
*/


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

        vector<vector<int>>res;
        
        // insert initial pair in priority queue
        pq.push({nums1[0] + nums2[0] , 0, 0});

        int n1 = nums1.size();
        int n2 = nums2.size();

        // pq.size() is necessary coz k can be larger than m*n
        while(!pq.empty() && res.size() < k){
            auto it = pq.top();
            pq.pop();

            int i = it[1];
            int j = it[2];

            // insert smallest pair in res vector
            res.push_back({nums1[i] , nums2[j]});

            // very important part in whole solN

            if(i+1 < n1 && j == 0) pq.push({nums1[i+1] + nums2[0] , i+1, 0});

            if(i < n1 && j + 1 < n2) pq.push({nums1[i] + nums2[j+1] , i, j+1});
        }

        return res;
    }
};