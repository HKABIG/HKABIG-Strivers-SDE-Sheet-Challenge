#include <bits/stdc++.h> 

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    while(node!=NULL){
        if(node->data==x){
            return node->data;
        }
        if(node->data<x){
            node = node->right;
        }
        else{
            ans = node->data;
            node = node->left;
        }
    }
    return ans;
}