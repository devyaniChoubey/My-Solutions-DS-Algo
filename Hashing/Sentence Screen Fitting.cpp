https://leetcode.com/problems/sentence-screen-fitting/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();

        //total words on entire screen
        int totalWords = 0;

        //line starting with ith index word has cnt words mp[i] = cnt
        unordered_map<int,int>mp;

        for(int row=0;row<rows;row++){
            int startWordInd = totalWords%n;

            if(mp.find(startWordInd) != mp.end()){
                totalWords += mp[startWordInd];
                continue;
            }

            int col = 0;
            int curLineWordCnt = 0;
            int i = startWordInd;

            while(col + sentence[i].length() <= cols){
                curLineWordCnt++;
                col += sentence[i].length() + 1;
                i = (i+1)%n;
            }

            mp[startWordInd] = curLineWordCnt;
            totalWords += curLineWordCnt;
        }

        return totalWords/n;
    }
};