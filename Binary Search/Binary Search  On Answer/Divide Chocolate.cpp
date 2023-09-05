https://leetcode.com/problems/divide-chocolate/description/

class Solution {
public:
    int noOfPartitions(vector<int>& sweetness, int minSweetness){
        int curSweetness = 0;
        int noOfPartition = 0;

        for(int i=0;i < sweetness.size();i++){
            if(curSweetness + sweetness[i] >= minSweetness){
                noOfPartition++;
                curSweetness = 0;
            }else{
                curSweetness = curSweetness + sweetness[i];
            }
        }

        return noOfPartition;
    }
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int low = *min_element(sweetness.begin() , sweetness.end());
        int high = 0;
        high = accumulate(sweetness.begin() , sweetness.end(), high);

        //because we have to divide chocolate in k+1 parts
        k++;

        while(low <= high){
            int mid = (low+high)/2;

            if(noOfPartitions(sweetness, mid) >= k){
                low = mid+1;
            }else high = mid-1;
        }

        return high;
    }
};