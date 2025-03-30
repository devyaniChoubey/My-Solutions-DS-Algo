https://leetcode.com/problems/partition-labels/?envType=daily-question&envId=2025-03-30

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char,int>lastPlace;
            int n = s.length();
    
            for(int i=0;i < n;i++){
                lastPlace[s[i]] = i;
            }
    
            int last = 0;
            vector<int>ans;
    
            for(int i=0;i < n;i++){
                last = lastPlace[s[i]];
                int j = i;
    
                while(j <= last){
                    last = max(last, lastPlace[s[j]]);
                    j++;
                }
                ans.push_back(j-i);
                i = j-1;
            }
    
            return ans;
        }
    };