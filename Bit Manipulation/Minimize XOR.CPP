https://leetcode.com/problems/minimize-xor/
https://leetcode.com/problems/minimize-xor/editorial/


class Solution {
public:
    void setCurBit(int curBitPos, int &num){
       num = (1 << curBitPos) | num;
    }

    void unSetCurBit(int curBitPos, int &num){
       num = num & ~(1 << curBitPos);
    }

    int checkIfBitIsSet(int curBitPos, int num){
       return ((num & (1 << curBitPos)) != 0);
    }


    int minimizeXor(int num1, int num2) {
        int requiredSetBit = __builtin_popcount(num2);
        int x = num1;
        int curSetBit = __builtin_popcount(num1);

        int curBitPos = 0;

        while(curSetBit != requiredSetBit){
            if(curSetBit > requiredSetBit){
                if(checkIfBitIsSet(curBitPos, x)){
                    unSetCurBit(curBitPos, x);
                    curSetBit--;
                }
                curBitPos++;
            }else if(curSetBit < requiredSetBit){
                if(!checkIfBitIsSet(curBitPos, x)){
                    setCurBit(curBitPos, x);
                    curSetBit++;
                }
                curBitPos++;
            }
        }

        return x;
    }
};