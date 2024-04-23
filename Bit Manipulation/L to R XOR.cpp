https://www.naukri.com/code360/problems/l-to-r-xor_8160412?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

int xorFrom1toN(int n){
      if(n % 4 == 1) return 1;
      else if(n % 4 == 2) return n+1;
      else if(n % 4 == 3) return 0;
      else return n;
}

int findXOR(int L, int R){
    // Write your code here.
    
   return xorFrom1toN(L-1) ^ xorFrom1toN(R);
}