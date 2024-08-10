https://leetcode.com/problems/count-number-of-teams/

class Solution {
public:
    int countIncreasingTeams(int ind, vector<int>& rating, int size, vector<vector<int>>&dpIncreasing){
        int n = rating.size();

        if(ind >= n) return 0;

        if(size == 3) return 1;

        int teams = 0;

        if(dpIncreasing[ind][size] != -1) return dpIncreasing[ind][size];

        for(int j=ind+1;j < n;j++){
            if(rating[j] > rating[ind]){
                teams += countIncreasingTeams(j, rating, size+1, dpIncreasing);
            }
        }

        return dpIncreasing[ind][size] = teams;
    }
    

    int countDecreasingTeams(int ind, vector<int>& rating, int size, vector<vector<int>>&dpDecreasing){
        int n = rating.size();

        if(ind >= n) return 0;

        if(size == 3) return 1;

        int teams = 0;

        if(dpDecreasing[ind][size] != -1) return dpDecreasing[ind][size];

        for(int j=ind+1;j < n;j++){
            if(rating[j] < rating[ind]){
                teams += countDecreasingTeams(j, rating, size+1, dpDecreasing);
            }
        }

        return dpDecreasing[ind][size] = teams;
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<int>>dpIncreasing(n+1, vector<int>(4, -1));
        vector<vector<int>>dpDecreasing(n+1, vector<int>(4, -1));

        int teams = 0;

        for(int i=0;i < n-2;i++){
            teams += countIncreasingTeams(i, rating, 1, dpIncreasing);
            teams += countDecreasingTeams(i, rating, 1, dpDecreasing);
        }

        return teams;
    }
};