https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTab=1



vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(), a.end());
    vector<int>res;
    for(int i=n-2;i >=0;i--){
        if(a[i] != a[i+1]){
            res.push_back(a[i]);
            break;
        }
    }

    for(int i=1;i < n;i++){
        if(a[i] != a[i-1]){
            res.push_back(a[i]);
            break;
        }
    }

    return res;
}








//optimised

int findSecondLargest(vector<int> a, int n){
    int largest = a[0];
    int sLargest = -1;
    for(int i=0;i < n;i++){
        if(a[i] > largest){
            sLargest = largest;
            largest = a[i];
        }else if(largest > a[i] && sLargest < a[i]){
            sLargest = a[i];
        }
    }
    return sLargest;
}

int findSecondSmallest(vector<int> a, int n){
    int smallest = a[0];
    int sSmallest = INT_MAX;
    for(int i=0;i < n;i++){
        if(a[i] < smallest){
            sSmallest = smallest;
            smallest = a[i];
        }else if(a[i] != smallest && a[i] < sSmallest){
            sSmallest = a[i];
        }
    }
    return sSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int sLargest = findSecondLargest(a, n);
    int sSmallest = findSecondSmallest(a, n);

    return {sLargest, sSmallest};
}
