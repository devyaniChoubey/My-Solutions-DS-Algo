https://leetcode.com/problems/sort-an-array/description/

https://www.youtube.com/watch?v=ogjf7ORKfd8

class Solution {
public:
    void merge(vector<int>& nums, int start,int mid, int end){
        int i = start, j = mid+1;
        vector<int>temp(end-start+1);

        int k = 0;

        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i];
                i++;
            }else{
               temp[k++] = nums[j];
               j++;
            }
        }

        while(i <= mid){
            temp[k++] = nums[i];
            i++;
        }

        while(j <= end){
            temp[k++] = nums[j];
            j++;
        }

        k = 0;
        for(int i=start;i <= end;i++){
            nums[i] = temp[k];
            k++;
        }


    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start >= end) return;

        int mid = (start+end)/2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);

        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};