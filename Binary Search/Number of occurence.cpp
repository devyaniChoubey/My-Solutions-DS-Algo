https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
int count(vector<int>& arr, int n, int target) {
	// Write Your Code Here

	int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
	int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
	

	if(first == n || arr[first] != target) return 0;
	else return last-first;
}
