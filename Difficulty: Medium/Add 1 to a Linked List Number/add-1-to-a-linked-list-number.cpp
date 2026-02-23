/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverseLL(head);

    int carry = 1;
    Node* temp = head;

    while(temp != NULL && carry){ 
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if(temp->next == NULL && carry){
            temp->next = new Node(carry);
            carry = 0;
            break;
        }

        temp = temp->next; 
    }

    head = reverseLL(head);
    return head;
}
};