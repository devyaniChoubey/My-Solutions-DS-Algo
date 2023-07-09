https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems


int isSorted(int n, vector<int> a) {
    for(int i=1;i < n;i++){
        if(a[i] < a[i-1]) return false;
    }

    return true;
}
