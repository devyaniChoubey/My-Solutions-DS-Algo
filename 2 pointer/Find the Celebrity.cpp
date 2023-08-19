https://leetcode.com/problems/find-the-celebrity/description/



//BRUTE FORCE

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int noOfPeople;
    bool isCelebrity(int j){
        for(int i=0;i < noOfPeople;i++){
            if(i == j) continue;
            else{
                if(!knows(i, j) || knows(j, i)) return false;
            }
        }

        return true;
    }
    int findCelebrity(int n) {
        noOfPeople = n;
        for(int j=0;j < n;j++){
            if(isCelebrity(j)){
                return j;
            }
        }

        return -1;
    }
};




//2 POINTER


/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    //Function to find if there is a celebrity in the party or not.
    int findCelebrity(int n) {
        
        int i=0, j = n-1;

        while(i < j){
            // i knows j, thus i cannot be celebrity
            if(knows(i, j)) i++;
            // i does not know j, thus j cannot be celebrity
            else j--;
        }

        // i points to our celebrity candidate
        int celebrity = i;

        // Now, all that is left is to check that whether
        // the candidate is actually a celebrity i.e: he is
        // known by everyone but he knows no one

        for(int j=0;j < n;j++){
            if(i == j) continue;
            else{
                if(knows(i, j) || !knows(j, i)){
                    return -1;
                }
            }
        }

        // if we reach here this means that the candidate
        // is really a celebrity
        return celebrity;
    }
};