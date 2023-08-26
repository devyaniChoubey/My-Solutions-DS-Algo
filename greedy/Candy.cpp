https://leetcode.com/problems/candy/description/

If we somehow manage to make sure that the child at higher rating is getting more candies than our problem is solved. 
For this we can make use of greedy (since we have to compare only the neighbors of current index). 
The approach is to do two traversals (in two directions), 
first one to make sure that the child at higher rating from left gets more candies
second one to make sure that the child at higher rating from the right gets more candies

Do it in two directions.
The first loop makes sure children with a higher rating get more candy than its left neighbor; the second loop makes sure children 
with a higher rating get more candy than its right neighbor.


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int>candies(n, 1);

        int totalCandies = 0;

        for(int i=1;i < n;i++){
            if(ratings[i] > ratings[i-1] && candies[i] <= candies[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }

        for(int i=n-2;i >= 0;i--){
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i + 1]){
                candies[i] = candies[i + 1] + 1;
            }

            totalCandies += candies[i];
        }

        totalCandies += candies[n-1];

        return totalCandies;
    }
};




https://leetcode.com/problems/candy/solutions/2234434/c-o-n-time-o-1-space-full-explanation/

not properly understood by me first reading

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 1;

        int candies = n;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            int peaks = 0;
            while(ratings[i] > ratings[i-1]){
                peaks++;
                candies += peaks;
                i++;
                if(i == n) return candies;
            }

            int valleys = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                valleys++;
                candies += valleys;
                i++;
            }

            candies -= min(peaks, valleys);
        }

        return candies;
    }
};