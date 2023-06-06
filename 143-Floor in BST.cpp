#include <bits/stdc++.h> 

int floorInBST(TreeNode<int> * root, int X){
    int ans = INT_MAX;
    while(root!=NULL){
        if(root->val==X){
            return root->val;
        }
        if(root->val>X){
            root = root->left;
        }
        else{
            ans = root->val;
            root = root->right;
        }
    }
    return ans;
}