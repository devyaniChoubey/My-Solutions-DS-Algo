https://leetcode.com/problems/3sum/description/


//Brute Force

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        set<vector<int>>st;
        for(int i=0;i < n;i++){
            for(int j=i+1;j < n;j++){
                for(int k=j+1;k < n;k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int>temp({nums[i] , nums[j] , nums[k]});
                        sort(temp.begin() , temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>>ans(st.begin() , st.end());

        return ans;
    }
};



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


//TLE Hashing

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        map<int ,int>mp;
        
        for(int i=0;i < n;i++){
            mp[nums[i]] = i+1;
        }

        set<vector<int>>st;
        for(int i=0;i < n;i++){
            for(int j=i+1;j < n;j++){
                int sum = -(nums[i] + nums[j]);

                if(mp[sum] > 0 && mp[sum] - 1 != i && mp[sum] - 1 != j){
                    vector<int>temp({nums[i] , nums[j] , sum});
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
                
            }
        }

        vector<vector<int>>ans(st.begin() , st.end());

        return ans;
    }
};


//Accepted
//2 pointer 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        vector<vector<int>>ans;
        int n = nums.size();

        for(int i=0;i < n - 2;i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int low = i + 1, high = n - 1;
            
                while(low < high){
                    if(nums[low] + nums[high] + nums[i] > 0){
                        high--;
                    }else if(nums[low] + nums[high] + nums[i] < 0) low++;
                    else{
                        ans.push_back({nums[low] , nums[high], nums[i]});
                        low++;high--;
                        while(low < high && nums[low] == nums[low-1]) low++;
                        while(low < high && nums[high] == nums[high+1]) high--;
                    }
                }
            }
        }

        return ans;
    }
};