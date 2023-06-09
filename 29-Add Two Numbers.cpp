/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node* dummy = new Node();
    Node* temp = dummy;
    int carry = 0;
    while(l1!=NULL || l2!=NULL || carry==1){
        int sum = 0;
        if(l1!=NULL){
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2!=NULL){
            sum += l2->data;
            l2 = l2->next;
        }
        sum = sum + carry;
        carry = sum/10;
        Node* node = new Node(sum%10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}
