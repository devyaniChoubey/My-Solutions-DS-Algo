https://leetcode.com/problems/permutation-in-string/?envType=company&envId=google&favoriteSlug=google-six-months

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26, 0);

        for(char &c:s1) freq1[c-'a']++;

        int right = 0, left = 0, n = s2.size();

        vector<int>freq2(26, 0);


        while(right < n){
            freq2[s2[right] - 'a']++;

            while(freq2[s2[right] - 'a'] > freq1[s2[right] - 'a']){
                freq2[s2[left] - 'a']--;
                left++;
            }


            for(int i=0;i < 26;i++){
                if(freq1[i] != freq2[i]) break;
                if(i == 25) return true;
            }
            right++;
        }

        return false;

    }
};