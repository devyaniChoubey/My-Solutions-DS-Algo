https://leetcode.com/problems/flipping-an-image/description/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& images) {
        int n = images.size();
        for(auto &image:images){
            for(int i=0;2*i < n;i++){
                if(image[i] == image[n-i-1]){
                    image[i] = image[n-i-1]^=1;
                }
            }
        }

        return images;
    }
};

