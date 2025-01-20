https://leetcode.com/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-01-17

https://leetcode.com/problems/neighboring-bitwise-xor/editorial/?envType=daily-question&envId=2025-01-17
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int>original = {0};
        int n = derived.size();

        for(int i=0;i < n-1;i++){
            original.push_back(derived[i]^original[i]);
        }

        bool ans = (derived[n-1] == (original[n-1]^original[0]));

        original = {1};

        for(int i=0;i < n-1;i++){
            original.push_back(derived[i]^original[i]);
        }

        ans |= (derived[n-1] == (original[n-1]^original[0]));

        return ans;
    }
};