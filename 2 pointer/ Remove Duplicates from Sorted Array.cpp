https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/


class Solution {
public:
    string removeDuplicates(string s) {
        string res;

        for(char& c:s){
           if(!res.empty() && res.back() == c) res.pop_back();
           else res.push_back(c);
        }

        return res;

    }
};





class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        
        for(char &c:s){
            if(!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }

        string ans;

        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;

    }
};





//Brute Force

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        int n = nums.size();
        for(int i=0;i < n;i++){
            s.insert(nums[i]);
        }

        int index = 0;
        for(auto it:s){
            nums[index] = it;
            index++;
        }
        return s.size();
    }
};



//2 pointer

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        for(int j=1;j < n;j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i+1;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for(int j=0;j < n;j++){
            if(j == 0 || (nums[j] != nums[j-1])){
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};