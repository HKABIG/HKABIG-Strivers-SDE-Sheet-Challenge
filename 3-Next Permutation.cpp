#include <bits/stdc++.h> 

void swap(vector<int> &nums,int i,int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void reverse(vector<int> &nums,int i){
    int j = nums.size()-1;
    while(i<j){
        swap(nums,i,j);
        j--;
        i++;
    }
}

vector<int> nextPermutation(vector<int> &permutation, int n){
    int i = n-2;
    while(i>=0 && permutation[i+1]<=permutation[i]){
        i--;
    }
    if(i>=0){
        int j = n-1;
        while(permutation[j]<=permutation[i]){
            j--;
        }
        swap(permutation,i,j);
    }
    reverse(permutation,i+1);
    return permutation;
}
