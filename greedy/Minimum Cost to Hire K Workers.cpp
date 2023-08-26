// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
// https://youtu.be/o8emK4ehhq0

/*
There are n workers. You are given two integer arrays quality and expWage where quality[i] is the quality of the ith worker and 
expWage[i] is the minimum expWage expectation for the ith worker.
We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
a) Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
b) Every worker in the paid group must be paid at least their minimum expWage expectation.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. 

Example 1:
Input: quality = [10,20,5], expWage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.

Example 2:
Input: quality = [3,1,10,10,1], expWage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
*/



/*
Let offer[i] is the money given to i'th worker

Given rules can be written as:
a) offer[i] / offer[j] = quality[i] / quality[j]
   or
   offer[i] / quality[i] = offer[j] / quality[j]
b) offer[i] >= expWage[i]

NOTE:
-------
There will be atleast one worker in the k workers group that is paid equal to his expected expWage 
(i.e. offer[i] = expWage[i] for some i and let's call this i'th worker captain)

offer[captain] = expWage[captain]                                    -------------- (i)

offer[i] / offer[captain] = quality[i] / quality[captain]
offer[i] = (quality[i] / quality[captain]) * offer[captain]       -------------- (ii)

From (i), (ii):
offer[i] = (quality[i] / quality[captain]) * expWage[captain]

offer[i] = quality[i] * (expWage[captain] / quality[captain])
offer[i] = quality[i] * captainsRatio

Thus once the captain is decided, total sum can be calculated as:
total = (quality[i1] * captainsRatio) + (quality[i2] * captainsRatio) + ... + (quality[ik] * captainsRatio)
total = (quality[i1] + quality[i2] + ... + quality[ik]) * captainsRatio


Condition for any worker to be captain:
offer[i] >= expWage[i]
quality[i] * captainsRatio >= expWage[i]
captainsRatio >= expWage[i] / quality[i]
captainsRatio >= workersRatio

Thus the captain is one having the highest worker ratio among the k workers.
*/


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& expWage, int k) {
        int n = quality.size();

        double ans = DBL_MAX;

        vector<pair<double, double>>workers;
 
        for(int i=0;i < n;i++){
            workers.push_back({(double)expWage[i]/quality[i], (double)quality[i]});
        }

        sort(workers.begin() , workers.end());


        priority_queue<int> pq;
        double qualitySum = 0;

        for(auto it:workers){
            qualitySum += it.second;
            pq.push(it.second);

            if(pq.size() > k){
                qualitySum -= pq.top();
                pq.pop();
            }

            double captainRatio = it.first;

            if(pq.size() == k) {
                ans = min(ans, captainRatio*qualitySum);
            }
        }

        return ans;
    }
};