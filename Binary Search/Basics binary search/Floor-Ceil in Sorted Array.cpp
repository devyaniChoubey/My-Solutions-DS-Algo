https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401?leftPanelTab=1

floor -> largest element in array <= x 
ceil -> smallest element in array >= x (ceil is same as lower bound in sorted array)

pair<int, int> getFloorAndCeil(int arr[], int n, int target) {
	// Write your code here.
	sort(arr, arr+n);
	int ceil = -1, floor = - 1;
	int low = 0, high = n-1;
	while(low <= high){
		int mid = (low+high)/2;

		if(arr[mid] >= target){
			high = mid-1;
			ceil = arr[mid];
		}else low = mid+1;
	}

    low = 0, high = n-1;
	while(low <= high){
		int mid = (low+high)/2;

		if(arr[mid] <= target){
			low = mid+1;
		    floor = arr[mid];
		}else high = mid-1;
	}

	return {floor, ceil};
}
