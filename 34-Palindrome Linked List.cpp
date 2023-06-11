#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    LinkedListNode<int>* temp = head;
    vector<int> a1;
    while(temp!=NULL){
        a1.push_back(temp->data);
        temp = temp->next;
    }
    stack<int> st;
    for(int i=0;i<a1.size();i++){
        st.push(a1[i]);
    }
    vector<int> a2;
    while(!st.empty()){
        a2.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<a1.size()/2;i++){
        if(a1[i]!=a2[i]){
            return false;
        }
    }
    return true;
}