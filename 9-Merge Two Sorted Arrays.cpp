#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	priority_queue<int,vector<int>, greater<int>> pq;
	for(int i=0;i<m;i++){
		pq.push(arr1[i]);
	}
	for(int i=0;i<n;i++){
		pq.push(arr2[i]);
	}
	vector<int> ans;
	while(!pq.empty()){
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}