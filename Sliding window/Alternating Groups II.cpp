https://leetcode.com/problems/alternating-groups-ii/?envType=daily-question&envId=2025-03-09


class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            for(int i=0;i < k-1;i++){
                colors.push_back(colors[i]);
            }
    
            int left = 0, right = 1, n = colors.size(), ans = 0;
    
            while(right < n){
                if(colors[right] == colors[right-1]){
                    left = right;
                    right++;
                    continue;
                }
    
                if(right - left + 1 == k) {
                    left++;
                    ans++;
                }
    
                right++;
            }
    
            return ans;
        }
};






//space optimised

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
    
            int left = 0, right = 1, n = colors.size(), ans = 0;
    
            while(right < n+k-1){
                if(colors[right%n] == colors[(right-1)%n]){
                    left = right;
                    right++;
                    continue;
                }
    
                if(right - left + 1 == k) {
                    left++;
                    ans++;
                }
    
                right++;
            }
    
            return ans;
        }
};
