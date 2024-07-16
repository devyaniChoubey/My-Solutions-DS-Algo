https://leetcode.com/problems/single-threaded-cpu/description/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>processingOrder;

        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > task_queue;

        vector<vector<int>>sorted_tasks;

        int n = tasks.size();


        for(int i=0;i < n;i++){
            sorted_tasks.push_back({tasks[i][0] , tasks[i][1], i});
        }
        
        sort(sorted_tasks.begin() , sorted_tasks.end());

        long long int task_ind = 0, cur_time = 1;

        while(task_ind < n || !task_queue.empty()){
            if(task_queue.empty() && cur_time < sorted_tasks[task_ind][0]){
                cur_time = sorted_tasks[task_ind][0];
            }


            while(task_ind < n && cur_time >= sorted_tasks[task_ind][0]){
                task_queue.push({sorted_tasks[task_ind][1] , sorted_tasks[task_ind][2]});
                task_ind++;
            }

            auto it = task_queue.top();
            task_queue.pop();

            cur_time += it.first;

            processingOrder.push_back(it.second);
        }

        return processingOrder;
 
    }
};