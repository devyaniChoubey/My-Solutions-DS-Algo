https://leetcode.com/problems/relative-ranks/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>ans(n);
        
        priority_queue<pair<int,int>>pq;

        for(int i=0;i < n;i++){
            pq.push({score[i], i});
        }

        int i=0;

        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();

            if(i == 0) ans[ind] = "Gold Medal";
            else if(i == 1) ans[ind] = "Silver Medal";
            else if(i == 2) ans[ind] = "Bronze Medal";
            else{
                ans[ind] = to_string(i+1);
            }

            i++;
        }

        return ans;
    }
};


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>ans(n);

        int M = 0;

        for(int val:score) M = max(M, val);

        vector<int>scoreToIndex(M+1, 0);

        for(int i=0;i < n;i++){
            scoreToIndex[score[i]] = i+1;
        }

        int j = 0;

        for(int i=M;i >= 0;i--){
            if(scoreToIndex[i] != 0){
                int orgInd = scoreToIndex[i] - 1;
                if(j == 0) ans[orgInd] = "Gold Medal";
                else if(j == 1) ans[orgInd] = "Silver Medal";
                else if(j == 2) ans[orgInd] = "Bronze Medal";
                else{
                    ans[orgInd] = to_string(j+1);
                }
                j++;
            }
        }
        
        
        return ans;
    }
};