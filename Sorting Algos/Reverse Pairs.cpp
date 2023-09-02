https://leetcode.com/problems/reverse-pairs/


class Solution {
public:
    int res = 0;
    void merge(vector<int>& nums, int start,int mid, int end){
        int i = start, j = mid+1;
        int temp[end-start+1];

        int k = 0;

        while(i <= mid && j <= end){
            if(nums[i] <= 2LL*nums[j]){
                i++;
            }else{
                res += (mid - i + 1);
                j++;
            }
        }


        i = start, j = mid+1;
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
            }
        }

        while(i <= mid){
            temp[k++] = nums[i++];
        }

        while(j <= end){
            temp[k++] = nums[j++];
        }

        k = 0;
        for(int i=start;i <= end;i++){
            nums[i] = temp[k++];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start >= end) return;

        int mid = (start+end)/2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);

        merge(nums, start, mid, end);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        res = 0;
        mergeSort(nums, 0, n-1);
        return res;
    }



};