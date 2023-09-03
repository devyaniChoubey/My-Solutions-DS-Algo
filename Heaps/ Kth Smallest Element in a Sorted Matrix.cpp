
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/


//min heap

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        
        for(int i=0;i < matrix.size();i++){
            pq.push({matrix[i][0] , i, 0});
        }

        int res;

        while(k--){
            auto it = pq.top();
            pq.pop();

            int i = it[1];
            int j = it[2];

            res = it[0];

            if(j+1 < matrix.size()) pq.push({matrix[i][j+1] , i , j+1});
        }

        return res;
        
    }
};



//Binary Search
class Solution {
public:
    int countLessThanOrEqualToTarget(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        
        int i = 0, j = n-1;

        int cnt = 0;

        while(i < n && j >= 0){
            if(matrix[i][j] <= target){
                cnt += (j+1);
                i++;
            }else j--;
        }

        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0] , high = matrix[n-1][n-1];

        while(low <= high){
            int mid = (low+high)/2;

            if(countLessThanOrEqualToTarget(matrix, mid) >= k){
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        return low;
    }
};