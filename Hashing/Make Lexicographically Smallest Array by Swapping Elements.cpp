https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/?envType=daily-question&envId=2025-01-25
https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/editorial/?envType=daily-question&envId=2025-01-25

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>numsSorted(nums);
        sort(numsSorted.begin() , numsSorted.end());
        int n = nums.size();

        unordered_map<int, int>numsToGrp;

        int curGrp = 0;
        numsToGrp[numsSorted[0]] = curGrp;

        unordered_map<int, list<int>> grpToList;
        grpToList[curGrp] = list<int>();
        grpToList[curGrp].push_back(numsSorted[0]);


        for(int i=1;i < n;i++){
            if(numsSorted[i] - numsSorted[i-1] > limit) curGrp++;
            numsToGrp[numsSorted[i]] = curGrp;

            if(grpToList.find(curGrp) == grpToList.end()){
                grpToList[curGrp] = list<int>();
            }

            grpToList[curGrp].push_back(numsSorted[i]);
        }

        for(int i=0;i < n;i++){
            int grpNo = numsToGrp[nums[i]];

            nums[i] = grpToList[grpNo].front();
            grpToList[grpNo].pop_front();
        }

        return nums;


    }
};