https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/

class Solution {
public:
    int minSteps(string original, string swapped){
        int i=0, j=0;
        int n = original.length();
        int result = 0;

        while(i < n){
            j = i;

            while(original[j] != swapped[i]) j++;

            while(i < j){
                swap(original[j] , original[j-1]);
                j--;
                result++;
            }


            i++;
        }
        return result;
    }
    int getMinSwaps(string num, int k) {
        string original = num;

        while(k > 0){
            next_permutation(num.begin() , num.end());
            k--;
        }

        return minSteps(original, num);
    }
}; 