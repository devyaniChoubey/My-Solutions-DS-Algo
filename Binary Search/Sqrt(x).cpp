https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        long long low = 1, high = x;
        while(low <= high){
            long long mid = (low+high)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid > x) high = mid-1;
            else{
                if(mid > ans) ans = mid;
                low = mid+1;
            }
        }

        return ans;
    }
};