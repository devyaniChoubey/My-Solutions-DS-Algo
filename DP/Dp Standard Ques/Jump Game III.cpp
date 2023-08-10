https://leetcode.com/problems/jump-game-iii/description/

class Solution {
public:
    int solve(int i, vector<int>& arr){
        int n = arr.size();
        if(i >= n || i < 0 || arr[i] < 0) return 0;
        if(arr[i] == 0) return 1;

        // mark visited by making negative
        arr[i] = -arr[i];

        return solve(i - arr[i], arr) || solve(i + arr[i], arr);
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(start, arr);
    }
};