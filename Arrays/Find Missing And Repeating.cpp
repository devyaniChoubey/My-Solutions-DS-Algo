https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1


class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {

        vector<int>freq(n+1, 0);
        
        
        for(auto it:arr){
            freq[it]++;
        }
        
        int missingEl, repeatingEl;
        
        for(int i=1;i <= n;i++){
            if(freq[i] == 0) missingEl = i;
            if(freq[i] == 2) repeatingEl = i;
        }
        
        return {repeatingEl ,  missingEl};
    }
};




class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int N) {
        long long int n = arr.size();
        
        long long int SN = (n * (n+1) ) /2 , S2N = (n * (n +1) *(2*n +1) ) / 6;
        
         long long int S = 0, S2 = 0;
        
        for(int i=0;i < n;i++){
            S += ( long long int) arr[i];
            S2 += ( long long int) arr[i]*( long long int)arr[i];
        }
        
        long long int val1 = (S-SN);
        long long int val2 = (S2-S2N);
        
        long long int repeatingEl =  ((val2)/(val1)) + (val1);
        
        repeatingEl = repeatingEl/2;
        
        long long int missing = repeatingEl - val1;
        return {(int)repeatingEl, (int)missing};
        
    }
};