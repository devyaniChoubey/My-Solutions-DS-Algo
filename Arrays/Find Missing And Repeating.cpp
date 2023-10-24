https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

https://www.interviewbit.com/problems/repeat-and-missing-number-array/

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



vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    long long n = arr.size();
    long long SN = ((n)*(n+1))/2;

	long long S2N = ((n)*(n+1)*(2*n + 1))/6;

	long long S = 0, S2 = 0;

	for(int i=0;i < n;i++){
		S += (long long) arr[i];
		S2 += (long long) arr[i] * (long long) arr[i];
	}

	long long val1 = S - SN;
	long long val2 = S2 - S2N;

    val2 = val2/val1;

	long long r = (val2 + val1)/2;


	return {(int)r , (int)(r - val1)};
}
