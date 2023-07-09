https://leetcode.com/problems/3sum/description/


//TLE solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int>mp;
        set<vector<int>>s;
        int n = nums.size();
        for(int i=0;i < n;i++){
            mp[nums[i]]++;
        }

        for(int i=0;i < n;i++){
            mp[nums[i]]--;
            for(int j=i+1;j < n;j++){
                mp[nums[j]]--;
                if(mp[-(nums[i] + nums[j])] > 0){
                    vector<int>trip = {nums[i], nums[j], -(nums[i] + nums[j])};
                    sort(trip.begin(), trip.end());
                    s.insert(trip);
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }

        vector<vector<int>>ans(s.begin(), s.end());
        return ans;
    }
};


//Accepted
//2 pointer 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i=0;i < nums.size()-2;i++){
            if(i == 0 || (i > 0 && (nums[i] != nums[i-1]))){
                int lo = i+1, hi = nums.size() - 1, sum = -nums[i];
                while(lo < hi){
                    if(sum == nums[lo] + nums[hi]){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        ans.push_back(temp);

                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo < hi && nums[hi-1] == nums[hi]) hi--;
                        lo++;hi--;
                    }else if(nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
                }
            }
        }

        return ans;
    }
};
