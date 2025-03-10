https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10
https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/editorial/?envType=daily-question&envId=2025-03-10

class Solution {
    public:
        bool isVowel(char ch){
           if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    
           return false;
        }
        long long countOfSubstrings(string word, int k) {
            long long ans = 0;
    
            int left = 0, right = 0, n = word.size();
            unordered_map<char,int>vCount;
            int consonantCnt = 0;
    
            vector<int> nextConsonant(word.size());
            int nextConsonantIndex = word.size();
            for (int i = word.size() - 1; i >= 0; i--) {
                nextConsonant[i] = nextConsonantIndex;
                if (!isVowel(word[i])) {
                    nextConsonantIndex = i;
                }
            }
    
            while(right < n){
                char ch = word[right]; 
    
                if(isVowel(ch)) vCount[ch]++;
                else {
                    consonantCnt++;
                    while(consonantCnt > k){
                        char lCh = word[left];
    
                        if(isVowel(lCh)) {
                            vCount[lCh]--;
                            if(vCount[lCh] == 0) vCount.erase(lCh);
                        }
                        else consonantCnt--;
    
                        left++;
                    }
                }
    
                while(left < word.size() && vCount.size() == 5 && consonantCnt == k){
    
                    ans += nextConsonant[right] - right;
                    char lCh = word[left];
    
                    if(isVowel(lCh)) {
                        vCount[lCh]--;
                        if(vCount[lCh] == 0) vCount.erase(lCh);
                    }
                    else consonantCnt--;
    
                    
                    left++;
                }
                
    
                right++;
            }
    
            return ans;
        }
    };