https://www.naukri.com/code360/problems/count-total-set-bits_784?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

TLE Solution

int countSetBitsInN(int N){
    int setBits = 0;
    while(N != 1){
        
        setBits += (N % 2 == 1);
        
        N = N/2;
    }

    if(N == 1) setBits++;

    return setBits;
}

int countSetBits(int N)
{
    //Write your code here
    int ans = 0;
    
    for(int i=1;i <= N;i++)ans += countSetBitsInN(i);

    return ans;
}


//Solution 2

int countSetBitsInN(int N){
    int setBits = 0;
    while(N != 1){
        
        setBits += (N & 1);
        
        N = (N >> 1);
    }

    if(N == 1) setBits++;

    return setBits;
}

int countSetBits(int N)
{
    //Write your code here
    int ans = 0;
    
    for(int i=1;i <= N;i++)ans += countSetBitsInN(i);

    return ans;
}

//Solution 3

int countSetBitsInN(int N){
       int bits = 0;
        while(N != 0){
            N = N&(N-1);
            bits++;
        }

        return bits;
}

int countSetBits(int N)
{
    //Write your code here
    int ans = 0;
    
    for(int i=1;i <= N;i++)ans += countSetBitsInN(i);

    return ans;
}