https://leetcode.com/problems/top-k-frequent-words/description/


class Solution {
public:
    struct comparator{
        bool operator()(const pair<int, string>&a,const pair<int, string>&b){
            if(a.first != b.first){
                return (a.first > b.first);
            }

            return (a.second < b.second);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>freq;

        for(auto it:words){
            freq[it]++;
        }

        priority_queue <pair<int, string>, vector<pair<int,string>>, comparator > pq;
        
        for(auto it:freq){
            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string>res;

        while(!pq.empty()){
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }

        return res;



    }
};  