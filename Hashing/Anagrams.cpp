https://www.interviewbit.com/problems/anagrams/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>>anagramGrp;
    for(int i=0;i < A.size();i++){
        string s = A[i];
        sort(s.begin() , s.end());
        anagramGrp[s].push_back(i+1);
    }
    
    vector<vector<int>>result;
    for(auto it:anagramGrp){
        result.push_back(it.second);
    }
    
    return result;
}