#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    Kthlargest(int k, vector<int> &arr) {
        size = k;
       for(int i=0;i<k;i++){
           pq.push(arr[i]);
           if(pq.size()>k) pq.pop();
       }
    }

    void add(int num) {
        pq.push(num);
        if(pq.size()>size) pq.pop();
    }

    int getKthLargest() {
       if(pq.size()>size) pq.pop();
        return pq.top();
    }

};