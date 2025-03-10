https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=daily-question&envId=2025-03-08

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int ans = 1e9, right = 0, left = 0;
            int n = blocks.size();
            int b = 0, w = 0;
    
            for(int i=0;i < k;i++){
                if(blocks[i] == 'W') w++;
                else b++;
            }
    
            ans = min(ans, w);
    
            right = k;
    
            while(right < n){
                if(blocks[left] == 'W') w--;
                else b--;
    
                if(blocks[right] == 'W') w++;
                else b++;
    
                ans = min(ans, w);
                left++;
                right++;
            }
    
            return ans;
        }
    };