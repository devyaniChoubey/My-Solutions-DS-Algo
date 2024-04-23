https://www.naukri.com/code360/problems/swap-two-numbers_1380853?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void swapNumber(int &a, int &b) {
	// Write your code here.

	a = a^b;
	b = a^b;
	a = a^b;
}