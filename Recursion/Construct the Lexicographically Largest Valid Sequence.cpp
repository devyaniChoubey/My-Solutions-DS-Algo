https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/?envType=daily-question&envId=2025-02-16

class Solution {
public:
    bool solve(int ind, int n, vector<int>&ans, unordered_set<int>&st){
        int size = ans.size();

        if(ind == size) return true;

        if(ans[ind] != 0) return solve(ind+1, n, ans, st);
        
        for(int i=n;i >= 1;i--){
            if(i == 1){
                if(st.count(i)){
                    ans[ind] = i;
                    st.erase(i);
                    if(solve(ind+1, n, ans, st)) return true;
                    else {
                        ans[ind] = 0;
                        st.insert(i);
                    }
                }else continue;
            }
            if(st.count(i) && ind+i < size && ans[ind+i] == 0){
                ans[ind] = i;
                ans[ind+i] = i;
                st.erase(i);

                if(solve(ind+1, n, ans, st)) return true;
                else {
                    ans[ind] = 0;
                    ans[ind+i] = 0;
                    st.insert(i);
                }
            }
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*(n - 1) + 1, 0);
        unordered_set<int>st;
        for(int i=1;i <= n;i++) st.insert(i);

        solve(0, n, ans, st);

        return ans;
    }
};



class Solution {
public:
    vector<int> constructDistancedSequence(int targetNumber) {
        // Initialize the result sequence with size 2*n - 1 filled with 0s
        vector<int> resultSequence(targetNumber * 2 - 1, 0);

        // Keep track of which numbers are already placed in the sequence
        vector<bool> isNumberUsed(targetNumber + 1, false);

        // Start recursive backtracking to construct the sequence
        findLexicographicallyLargestSequence(0, resultSequence, isNumberUsed,
                                             targetNumber);

        return resultSequence;
    }

private:
    // Recursive function to generate the desired sequence
    bool findLexicographicallyLargestSequence(int currentIndex,
                                              vector<int>& resultSequence,
                                              vector<bool>& isNumberUsed,
                                              int targetNumber) {
        // If we have filled all positions, return true indicating success
        if (currentIndex == resultSequence.size()) {
            return true;
        }

        // If the current position is already filled, move to the next index
        if (resultSequence[currentIndex] != 0) {
            return findLexicographicallyLargestSequence(
                currentIndex + 1, resultSequence, isNumberUsed, targetNumber);
        }

        // Attempt to place numbers from targetNumber to 1 for a
        // lexicographically largest result
        for (int numberToPlace = targetNumber; numberToPlace >= 1;
             numberToPlace--) {
            if (isNumberUsed[numberToPlace]) continue;

            isNumberUsed[numberToPlace] = true;
            resultSequence[currentIndex] = numberToPlace;

            // If placing number 1, move to the next index directly
            if (numberToPlace == 1) {
                if (findLexicographicallyLargestSequence(
                        currentIndex + 1, resultSequence, isNumberUsed,
                        targetNumber)) {
                    return true;
                }
            }
            // Place larger numbers at two positions if valid
            else if (currentIndex + numberToPlace < resultSequence.size() &&
                     resultSequence[currentIndex + numberToPlace] == 0) {
                resultSequence[currentIndex + numberToPlace] = numberToPlace;

                if (findLexicographicallyLargestSequence(
                        currentIndex + 1, resultSequence, isNumberUsed,
                        targetNumber)) {
                    return true;
                }

                // Undo the placement for backtracking
                resultSequence[currentIndex + numberToPlace] = 0;
            }

            // Undo current placement and mark the number as unused
            resultSequence[currentIndex] = 0;
            isNumberUsed[numberToPlace] = false;
        }

        return false;
    }
};