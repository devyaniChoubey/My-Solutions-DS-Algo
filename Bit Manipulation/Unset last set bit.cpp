
unset rightmost set bit

n = 16  10000   |||||    n = 40  10100   |||||  n = 84  1010100
n = 15  01111   |||||    n = 39  10011   |||||  n = 83  1010011
ans     00000            ans     10000          ans     1010000
int unsetLastSetBit(int n)
{
    // Write your code here.

    return n & (n-1);
}