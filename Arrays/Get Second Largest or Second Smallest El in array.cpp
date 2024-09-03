
class Solution {
  public:
    int secondLargest(vector<int> &arr) {
        // code here
        
        int largest = arr[0], sLargest = -1;
        
        for(int i=1;i < arr.size();i++) {
          if(arr[i] > largest){
            sLargest = largest;
            largest = arr[i];
          }else if(arr[i] < largest && sLargest < arr[i]){
            sLargest = arr[i];
          }
        }
        
        return sLargest;
    }
};


class Solution {
  public:
    int secondSmallest(vector<int> &arr) {
        // code here
        
        int smallest = arr[0], sSmallest = 1e9;
        
        for(int i=1;i < arr.size();i++) {
          if(arr[i] < smallest){
            sSmallest = smallest;
            smallest = arr[i];
          }else if(arr[i] > smallest && sSmallest > arr[i]){
            sSmallest = arr[i];
          }
        }
        
        return sSmallest;
    }
};