// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

/*
Given N activities with their start and finish day given in array start[ ] and end[ ]. 
Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
*/

/*
Same as classic non overlapping interval problem.

The greedy choice is to always pick the next activity whose finish time is least among the remaining activities 
and the start time is more than or equal to the finish time of previously selected activity. 
We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
4) If the start time of this activity is greater than to the finish time of previously selected activity then select this activity and print it.
*/



class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    bool static comp(vector<int>&a , vector<int>& b){
        return (a[1] < b[1]);
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<vector<int>>activities;
        
        for(int i=0;i < start.size();i++){
            activities.push_back({start[i] , end[i]});
        }
        
        sort(activities.begin() , activities.end() , comp);
        
        int lastEndDay = activities[0][1];
        
        int activitiesCnt = 1;
        
        for(int i=1;i < activities.size();i++){
            if(activities[i][0] > lastEndDay){
                lastEndDay = activities[i][1];
                activitiesCnt++;
            }
        }
        
        return activitiesCnt;
    }
};
