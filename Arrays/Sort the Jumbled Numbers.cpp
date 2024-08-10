https://leetcode.com/problems/sort-the-jumbled-numbers/

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int,int>>temp;

        for(int i=0;i < nums.size();i++){
            string s = to_string(nums[i]);
            string formed = "";
            for(char &c:s) formed += to_string(mapping[int(c-'0')]);
            temp.push_back({stoi(formed) , i});
        }

        sort(temp.begin() , temp.end());
        vector<int>ans(nums.size(), 0);
        int k = 0;

        for(int i=0;i < temp.size();i++){
            ans[k++] = nums[temp[i].second];
        }

        return ans;
    }
};



class Solution {
public:
    int calculateMapping(int x,vector<int>& mapping){
        int sum = 0;
        int multi = 1;

        if(x == 0) return mapping[x];

        while(x != 0){
            int rem = x%10;
            
            sum += (mapping[rem]*multi);

            multi *= 10;

            x = x/10;
        }

        return sum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int,int>>temp;

        for(int i=0;i < nums.size();i++){
            temp.push_back({calculateMapping(nums[i], mapping) , i});
        }

        sort(temp.begin() , temp.end());
        vector<int>ans(nums.size(), 0);
        int k = 0;

        for(int i=0;i < temp.size();i++){
            ans[k++] = nums[temp[i].second];
        }

        return ans;
    }
};