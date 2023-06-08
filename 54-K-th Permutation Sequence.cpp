#include <bits/stdc++.h>
void permutationHelper(string &s,int index,vector<string>& res){
    if(s.length()==index){
        res.push_back(s);
        return;
    }
    for(int i=index;i<s.length();i++){
        swap(s[i],s[index]);
        permutationHelper(s,index+1,res);
        swap(s[i],s[index]);
    }
}

string kthPermutation(int n, int k) {
    // Brute Force O(N!*N)+O(NLogN)
    // string s = "";
    // vector<string> res;
    // for(int i=1;i<=n;i++){
    //     s.push_back(i+'0');
    // }
    // permutationHelper(s,0,res);
    // sort(res.begin(),res.end());
    // auto it = res.begin() + (k-1);
    // return *it;

    // Optimal Approach 
    vector<int> numbers;
    int fact = 1;
    for(int i=1;i<n;i++){
        fact = fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k = k-1;
    string ans = "";
    while(true){
        ans += to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0){
            break;
        }
        k = k%fact;
        fact = fact/numbers.size();
    }
    return ans;
}
