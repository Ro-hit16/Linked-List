#include<iostream>
using namespace std;
class node{
     public:
     int data;
     node* next;

     //constructor
     node(int data){
        this->data =data;
        this->next = NULL;
     }
     ~node(){
        cout<<"deleted data ="<<data<<endl;
     }
};
node* reverselist(node* head){
    node* prev= NULL;
    node* curr = head;
    node* next =NULL;

    while(curr != NULL){
        next =curr-> next;
        curr->next = prev;
        prev =curr;
        curr = next;
    }
    return prev;
}
node* insertAtFirst(node* &head,int data){
    node* newnode =new node(data);
    newnode->data =data;
    newnode->next= head;
    head= newnode;


}
void printLL( node* head){
    node* temp = head;
    while( temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
}
node* insertAtEnd(node* &tail,int data){
    node* newnode = new node(data);
    newnode->data =data;
    tail->next = newnode;
    newnode->next = NULL;
}
int getmidLL(node* head){
        node* slow =head;
        node* fast =head->next;
        int count=1;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        count++;
    }
    return count;
}
int main(){
 node* new1 =new node(20);
 node* head = new1;
 node* tail =new1;
 printLL(head);
 insertAtFirst(head,21);
  insertAtFirst(head,22);
   insertAtFirst(head,23);
    insertAtFirst(head,24);
    insertAtEnd(tail,19);
   int size = getmidLL(head);
   cout<<"size of list: " << size<<endl;
 printLL(head);
 node* rev=reverselist(head);
 while(rev != NULL){
        cout<<rev->data<<" ";
        rev= rev->next;
 }

return 0;
}