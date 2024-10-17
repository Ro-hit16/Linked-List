#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* random;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    ~node() {
        cout << "deleted node " << data << endl;
    }
};

node* insertAtTail(node* head, node*& tail, int data) {
    node* newnode = new node(data);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    return head;
}

node* cloneLL(node* head) {
    if (head == NULL) return NULL;
    
    node* original = head;
    unordered_map<node*, node*> nodeMap;

    while (original != NULL) {
        nodeMap[original] = new node(original->data);
        original = original->next;
    }

    original = head;
    while (original != NULL) {
        nodeMap[original]->random = nodeMap[original->random];
        original = original->next;
    }

    return nodeMap[head];
}
void printClonedLL(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << "Data: " << temp->data;
        if(temp->random != NULL) {
            cout << ", Random: " << temp->random->data;
        } else {
            cout << ", Random: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Creating original list
    node* head = NULL;
    node* tail = NULL;
    head = insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head->next->next->next->next;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head->next->next;

    // Cloning the list
    node* cloneHead = cloneLL(head);
    printClonedLL(cloneHead);

    return 0;
}
