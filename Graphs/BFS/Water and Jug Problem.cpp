https://leetcode.com/problems/water-and-jug-problem/description/

Think this problem in terms of only one JUG given as the capacity of (JUG1 and JUG2) combined .
Then you just have to find out if the targetCapacity can be achieved with this JUG or not .

While solving common Graph problems we use something like dx and dy arrays to go in all possible directions . Try to think in that way only !!! Think how many operations can u perfrom !!! how many ?? and What are those????

If x=JUG1CAPACITY , y=JUG2CAPACITY , z=TOTALCAPACITY COMBINED
Simply we just have to go in 4 operations ::
i. ADD x to the JUG
ii. ADD y to the JUG
iii. SUBTRACT x from the JUG
iv. SUBTRACT y from the JUG

and dont forget their boundary checks too !
THE CODED IMPLEMENTATION :::



class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int jugCap = jug1Capacity + jug2Capacity;

        vector<int>vis(jugCap + 1, 0);

        queue<int>q;

        int steps[] = {-jug1Capacity, jug1Capacity, -jug2Capacity, jug2Capacity};

        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int curCap = q.front();
            q.pop();

            if(curCap == targetCapacity) return true;

            for(int i=0;i < 4;i++){
                int newCap = curCap + steps[i];

                if(newCap >= 0 && newCap <= jugCap && vis[newCap] == 0){
                    q.push(newCap);
                    vis[newCap] = 1;
                }
            }
        }

        return false;
    }
};