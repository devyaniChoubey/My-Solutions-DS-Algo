https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;

        vector<int>freq(26, 0);

        for(char &c:s) freq[c-'a']++;

        for(int i=0;i < 26;i++){
            if(freq[i] > 0)pq.push({freq[i] , i+'a'});
        }

        string res = "";

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            if(res.size() > 0 && res.back() == it.second){
                if(!pq.empty()) {
                    auto it1 = pq.top();
                    pq.pop();
                    res += char(it1.second);
                    if(it1.first - 1 > 0) pq.push({it1.first-1, it1.second});
                    pq.push({it.first, it.second});
                }else return "";
            }else{
                res += char(it.second);
                if(it.first - 1 > 0)pq.push({it.first-1, it.second});
            }
        }

        return res;
    }
};