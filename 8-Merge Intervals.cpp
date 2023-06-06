#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;
    int index = 0;
    for(int i=0;i<intervals.size();i++){
        if(intervals[index][1] >= intervals[i][0]){
            intervals[index][1] = max(intervals[index][1],intervals[i][1]);
        }
        else{
            index = index + 1;
            intervals[index] = intervals[i];
        }
    }
    for(auto it:intervals){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    for(int i=0;i<index+1;i++){
        res.push_back(intervals[i]);
    }
    return res;
}
