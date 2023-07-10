// struct Item{
//     int value;
//     int weight;
// };



class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    // sort Item according to val / weight ratio
    static bool compare(Item a, Item b){
        return ((double)a.value/(double)a.weight > (double)b.value/(double)b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       
        sort(arr, arr+n, compare);
        double ans = 0;
        int i=0;
        while(W > 0){
            if(i >= n) break;
            if(arr[i].weight <= W){
                ans += arr[i].value;
                W -= arr[i].weight;
            }else{
                ans += ((double)arr[i].value/(double)arr[i].weight)*W;
                W = 0;
            }
            i++;
        }
        
        return ans;
        
    }
        
};