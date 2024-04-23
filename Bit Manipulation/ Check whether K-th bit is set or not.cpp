https://www.naukri.com/code360/problems/check-whether-k-th-bit-is-set-or-not_5026446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

left shift solution

bool isKthBitSet(int n, int k)
{
    // Write your code here.

    if((n & (1 << k-1)) != 0){
        return true;
    }else return false;
}


right shift solution

bool isKthBitSet(int n, int k)
{
    // Write your code here.

    if((n >> k-1) & 1 == 1){
         return true;
    }else return false;
}

  
  