https://leetcode.com/problems/fruit-into-baskets/description/

same questions as longest substring with at most 2 characters

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int , int>mp;
        int right = 0 , left = 0;
        int maxFruits = 0;
        int n = fruits.size();
        
        while(right < n){
            mp[fruits[right]] = right;
            
            int del_idx = INT_MAX;
            while(mp.size() > 2){
                for(auto it:mp){
                    del_idx = min(del_idx, it.second);
                }
                
                left = del_idx + 1;
                mp.erase(fruits[del_idx]);
            }

            maxFruits = max(maxFruits , right - left + 1);

            right++;
        }

        return maxFruits;
    }
};