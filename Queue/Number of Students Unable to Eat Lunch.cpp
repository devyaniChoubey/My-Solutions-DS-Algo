https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        int n = sandwiches.size();

        for(int i=0;i < n;i++){
            q.push(students[i]);
        }

        int i = 0;

        while(!q.empty()){
            int size = q.size();
            int prevSize = size;

            while(size--){
                int studentPref = q.front();
                q.pop();

                if(sandwiches[i] == studentPref) i++;
                else q.push(studentPref);
            }

            if(prevSize == q.size()) return q.size();
        }

        return 0;
    }
};