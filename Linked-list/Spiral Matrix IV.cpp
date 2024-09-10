https://leetcode.com/problems/spiral-matrix-iv/?envType=daily-question&envId=2024-09-09


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m , vector<int>(n, -1));
        int left = 0, top = 0, right = n-1, bottom = m-1;
        int dir = 0;

        while(left <= right && top <= bottom){
            if(head == NULL) return ans;
            if(dir == 0){
                for(int j=left;j <= right;j++){
                    if(head == NULL) return ans;
                    ans[top][j] = head->val;
                    head = head->next;
                }
                top++;
            }else if(dir == 1){
                for(int i = top;i <= bottom;i++){
                    if(head == NULL) return ans;
                    ans[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }else if(dir == 2){
                for(int j=right;j >= left;j--){
                    if(head == NULL) return ans;
                    ans[bottom][j] = head->val;
                    head = head->next;
                }
                bottom--;
            }else{
                for(int i = bottom;i >= top;i--){
                    if(head == NULL) return ans;
                    ans[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            dir++;
            dir = dir%4;
        }

        return ans;

        
    }
};