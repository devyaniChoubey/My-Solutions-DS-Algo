https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    bool static sortBYEndTime(pair<int,int>&a, pair<int,int>&b){
        return (a.second < b.second);
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>meetTime;
        for(int i=0;i < n;i++){
            meetTime.push_back({start[i], end[i]});
        }
        
        sort(meetTime.begin(), meetTime.end(), sortBYEndTime);
        
        int lastEndTime = meetTime[0].second;
        int  meetCount = 1;
        for(int i=1;i < n;i++){
            if(meetTime[i].first > lastEndTime){
                meetCount++;
                lastEndTime = meetTime[i].second;
            }
        }
        
        return meetCount;
    }
};