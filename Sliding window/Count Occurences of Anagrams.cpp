https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution{
public:
	int search(string pat, string str) {
	    // code here
	    int i = 0, j = 0;
	    int k = pat.length();
	    int n = str.length();
	    vector<int>freqPat(26, 0), freqStr(26, 0);
	    
	    for(auto c:pat) freqPat[c - 'a']++;
	    
	    int res = 0;
	    
	    while(j < n){
	        freqStr[str[j] - 'a']++;
	        
	        if(j-i+1 < k){
	            j++;
	        }else{
	            if(freqPat == freqStr) res++;
	            freqStr[str[i] - 'a']--;
	            i++;
	            j++;
	        }
	    }
	    
	    return res;
	    
	}

};