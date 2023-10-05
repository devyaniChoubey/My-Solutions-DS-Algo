https://www.interviewbit.com/problems/diffk/

int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    int i = 0, j = 0; // Initialize two pointers at the start of the array

    while (i < n && j < n) {
        if (i != j && A[j] - A[i] == B) {
            return 1; // Found a pair with the given difference
        } else if (A[j] - A[i] < B) {
            j++; // Move the right pointer to increase the difference
        } else {
            i++; // Move the left pointer to decrease the difference
        }

        // Ensure that i is always less than j and they are not the same
        if (i == j) {
            j++;
        }
    }

    return 0; // No such pair found
}
