https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &mat) {
    if(mat.empty()) return {};

    int m = mat.size(), n = mat[0].size();

    vector<vector<int> >ans;

    for(int s=0;s <= (n+m-2);s++){
        vector<int>temp;
        for(int x=0;x <= s;x++){
            int i = x;
            int j = s - i;

            if(i >= m || j >= n) continue;

            temp.push_back(mat[i][j]);
        }
        ans.push_back(temp);
    }

    return ans;
}
