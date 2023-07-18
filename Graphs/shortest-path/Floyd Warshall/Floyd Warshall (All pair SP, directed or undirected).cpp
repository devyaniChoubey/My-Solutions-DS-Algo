https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int i=0;i < n;i++){
	        for(int j=0;j < n;j++){
	            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	            if(i == j) matrix[i][j] = 0;
	        }
	    }
	    
	    for(int via=0; via < n;via++){
	        for(int i=0;i < n;i++){
    	        for(int j=0;j < n;j++){
    	            matrix[i][j] = min(matrix[i][j] , (matrix[i][via] + matrix[via][j]));
    	        }
	        }
	    }
	    
       //to detect negative weight cycle
	   // for(int i=0;i < n;i++){
	   //     if(matrix[i][i] < 0) return -1;
	   // }
	    
	    for(int i=0;i < n;i++){
	        for(int j=0;j < n;j++){
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }   
	    
	}
};