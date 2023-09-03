https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/


/*
Problem:
You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.
You are allowed to choose exactly 1 element from each row to form an array. 
Return the Kth smallest array sum among all possible arrays.
*/

/*
To understand this problem, first look at - Find K Pairs with Smallest Sums (https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
The function kSmallestPairs can be taken directly from above problem.

So we start merging two rows at a time by using the function kSmallestPairs, m-1 times, keeping each time the size of the res at most k.

The time complexity of kSmallestPairs each time it is called is k * logk.
Since it is called m-1 times, so we have total time complexity = k * logk * (m-1) = O(m * k * logk)
*/



class Solution {
public:
    struct comparator{
        bool operator()(vector<int>&a, vector<int>&b){
            return !(a[0] + a[1] < b[0] + b[1]);
        }
    };
    
    vector<int>kthSmallestSum(vector<int>nums1, vector<int>nums2, int k){
        priority_queue <vector<int>, vector<vector<int>>, comparator > pq;

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>res;
        
        for(int i=0;i < n1;i++){
            pq.push({nums1[i] , nums2[0] , 0});
        }

        while(!pq.empty() && res.size() < k){
            auto it = pq.top();
            pq.pop();

            int idx = it[2];

            res.push_back(it[0] + it[1]);

            if(idx + 1 < n2) pq.push({it[0] , nums2[idx + 1], idx+1 });
        }

        return res;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int>row = mat[0];

        for(int i=1;i < mat.size();i++){
            row = kthSmallestSum(mat[i], row, k);
        }

        return row[k-1];
    }
};