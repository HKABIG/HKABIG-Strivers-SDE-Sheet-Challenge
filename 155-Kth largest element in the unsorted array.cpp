#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K){
	priority_queue<int> pq;
	for(int i=0;i<size;i++){
		pq.push(arr[i]);
	}
	while(!pq.empty() && K>1){
		pq.pop();
		K--;
	}
	if(!pq.empty()) return pq.top();
	return -1;
}