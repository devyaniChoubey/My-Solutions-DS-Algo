https://www.codingninjas.com/studio/problems/rotation_7449070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

int findKRotation(vector<int> &nums){
    // Write your code here. 

    //no. of rotations = index of min. element in rotated sorted array

    int low = 0, high = nums.size() - 1;
    int minVal = 1e9, minValInd = 0;
    while(low <= high){
        int mid = (low+high)/2;

        if(nums[low] <= nums[mid]){
            if(nums[low] < minVal){
                minVal = nums[low];
                minValInd = low;
            }
            low = mid+1;
        }else{
            if(nums[mid] < minVal){
                minVal = nums[mid];
                minValInd = mid;
            }
            high = mid-1;
        }
    }  

    return minValInd;
}