#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    

    // Constructor
    node(int data) {
        this->data = data;
        
        this->next = NULL;
    }

    // Destructor
    ~node() {
        cout << "Memory is freed for node with data: " << data << endl;
    }
};

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtFirst(node* &head, int data) {
    node* newnode = new node(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
   
    head = newnode;
}
node* remove_duplicate(node* &head) {
    if (head == NULL)
        return NULL;

    node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            node* next_next = temp->next->next;
            delete(temp->next);
            temp->next = next_next;
        } else {
            temp = temp->next;
        }
    }
    return head;
}



int main(){
     node* head = NULL;

    insertAtFirst(head, 22);
    insertAtFirst(head, 23);
    insertAtFirst(head, 23);
    insertAtFirst(head, 25);
    insertAtFirst(head, 25);
    insertAtFirst(head, 28);

    print(head);
     
     remove_duplicate(head);
     print(head);
return 0;
}