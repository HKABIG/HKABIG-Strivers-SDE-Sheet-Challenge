#include <bits/stdc++.h>
#define ll long long int
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  for(int i=0;i<n;i++){
    vector<ll> res(i+1,1);
    for(int j=1;j<i;j++){
      res[j] = ans[i-1][j-1] + ans[i-1][j];
    }
    ans.push_back(res);
  }
  return ans;
}
