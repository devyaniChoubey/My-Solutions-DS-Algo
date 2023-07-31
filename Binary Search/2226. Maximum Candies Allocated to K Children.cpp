https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/


// Intuition
// Binary search


// Explanation
// Assume we want give each child m candies, for each pile of candies[i],
// we can divide out at most candies[i] / m sub piles with each pile m candies.

// We can sum up all the sub piles we can divide out, then compare with the k children.

// If k > sum,
// we don't allocate to every child,
// since the pile of m candidies it too big,
// so we assign high = mid - 1.

// If k <= sum,
// we are able to allocate to every child,
// since the pile of m candidies is small enough
// so we assign low = mid+1;

// We repeatly do this until low == high, and that's the maximum number of candies each child can get.





class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = -1e9;
        for(auto it:candies) high = max(high , it);
        int maxSize = 0;
        while(low <= high){
            int mid = (low+high)/2;
            long long noStudents = 0;
            for(auto it:candies){
                noStudents += (it/mid);
            }

            if(noStudents >= k){
                low = mid+1;
                maxSize = max(maxSize, mid);
            }else{
                high = mid-1;
            }
        }

        return maxSize;
    }
};