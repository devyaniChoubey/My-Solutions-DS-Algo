https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

//Priority Queue
long double minimiseMaxDistance(vector<int> &stations, int K){
	// Write your code here.	
	int n = stations.size();
      vector<int> howMany(n-1, 0);
      priority_queue<pair<long double,int>> pq;
      for(int i=1;i < n;i++){
          pq.push({stations[i] - stations[i-1], i-1});
      }
      for(int k=1;k <= K;k++){
          //int maxIndex = -1; double maxVal = 0;
          int index = pq.top().second;
          howMany[index]++;
          long double diff = (stations[index+1] - stations[index]);
          long double newDist = diff/(long double)(howMany[index] + 1);
          pq.pop();
          pq.push({newDist, index});
      }
      
      return pq.top().first;
}


//Binary Search
int countStations(vector<int> &stations, long double maxDist){
    int cnt = 0;
	int n = stations.size();
    
	for(int i=1;i < n;i++){
		int numberInBetween = (stations[i] - stations[i-1])/maxDist;
		if ((stations[i] - stations[i - 1]) == maxDist * numberInBetween) {
			numberInBetween--;
		}
        cnt += numberInBetween;
	}

	return cnt;
}
long double minimiseMaxDistance(vector<int> &stations, int K){
	// Write your code here.
	int n = stations.size();	
	long double low = 0; long double high = 0;
	for(int i=1;i < n;i++){
		high = max(high , (long double)(stations[i] - stations[i-1]));
	}

    long double diff = 1e-6;
	while(high-low > diff){
		long double mid = (low+high)/(2.0);
        int cnt = countStations(stations, mid);
		if(cnt > K){
            low  = mid;
		}else{
            high = mid;
		}
	}

	return high;
}