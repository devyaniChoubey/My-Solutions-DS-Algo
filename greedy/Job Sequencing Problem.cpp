https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool compare(Job &j1, Job &j2){
        return j1.profit > j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // Sort all jobs according to decreasing order of profit 
        sort(arr, arr+n, compare);
        
        int maxDeadline = 0;
        for(int i=0;i < n;i++){
            if(maxDeadline < arr[i].dead) maxDeadline = arr[i].dead;
        }
        
        vector<int>slots(maxDeadline + 1, 0);// To keep track of free time slots 
        
        int maxProfit = 0, jobsDone = 0;
        for(int i=0;i < n;i++){
            // Find a free slot for this job (Note that we start from the last possible slot) 
            for(int j=arr[i].dead; j>=1;j--){
                if(slots[j] == 0){
                    slots[j] = 1;//make this slot occupied
                    maxProfit += arr[i].profit;
                    jobsDone++;
                    break;
                }
            }
        }
        
        return {jobsDone, maxProfit};
    } 
};