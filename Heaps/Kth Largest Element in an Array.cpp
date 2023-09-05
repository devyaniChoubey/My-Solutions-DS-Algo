https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;

        for(auto it:nums) {
           pq.push(it);
           if(pq.size() > k) pq.pop();
        }

        
        return pq.top();
    }
};




//Using quickSelect  gives TLE


class Solution {
public:
    int quickSort(vector<int>& nums,int start, int end, int k){
        
        int pivot = nums[end];
        int pIndex = start;

        for(int i=start;i < end;i++){
            if(nums[i] <= pivot){
                swap(nums[pIndex] , nums[i]);
                pIndex++;
            }
        }

        swap(nums[pIndex] , nums[end]);

        int count = end - pIndex + 1;

        if(count == k) return nums[pIndex];

        if(count > k) return quickSort(nums, pIndex + 1, end, k);

        return quickSort(nums, start, pIndex - 1, k-count);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size() - 1, k);
    }
};