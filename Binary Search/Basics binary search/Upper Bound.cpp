
smallest index such that arr[ind] > target

STL 
int upperbound = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

int upperBound(vector<int> &arr, int target, int n){
	int low = 0, high = n-1;
	int upperbound = n;
	while(low <= high){
		int mid = (low+high)/2;

		if(arr[mid] > target){
			upperbound = mid;
			high = mid- 1;
		}else{
      low = mid + 1;
		}
	}	

	return upperbound;
}