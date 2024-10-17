#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    // Constructor
    node(int data) {
        this->data = data;
        this->prev = NULL;
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
    head->prev = newnode;
    head = newnode;
}

void insertInBetwn(node* &head, int data, int index) {
    if (index == 1) {
        insertAtFirst(head, data);
        return;
    }
    node* node1 = new node(data);
    node* temp = head;
    int i = 1;
    while (i < index - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        cout << "Invalid index for insertion." << endl;
        return;
    }
    node1->next = temp->next;
    node1->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = node1;
    temp->next = node1;
}

void insertAtEnd(node* &head, int data) {
    node* newnode = new node(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void deleteNode(node* &head, int position) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (position == 1) {
        node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        return;
    }
    node* temp = head;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Invalid position for deletion." << endl;
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

void getLength(node* head) {
    int count = 0;
    for (node* temp = head; temp != NULL; temp = temp->next) {
        count++;
    }
    cout << "Length of the linked list is: " << count << endl;
}

void getLlData(node* head, int data) {
    int position = 1;
    for (node* temp = head; temp != NULL; temp = temp->next) {
        if (temp->data == data) {
            cout << "Data " << data << " found at position " << position << endl;
            return;
        }
        position++;
    }
    cout << "Data " << data << " not found in the linked list." << endl;
}

int main() {
    node* head = NULL;

    insertAtFirst(head, 22);
    insertAtFirst(head, 23);
    insertAtFirst(head, 24);
    insertAtFirst(head, 25);
    insertAtFirst(head, 26);
    insertAtFirst(head, 28);

    print(head);

    insertInBetwn(head, 27, 2);

    print(head);

    insertAtEnd(head, 20);

    print(head);

    getLength(head);

    deleteNode(head, 9);
    deleteNode(head, 8);
    deleteNode(head, 7);
    deleteNode(head, 6);
    deleteNode(head, 5);
    deleteNode(head, 4);
    deleteNode(head, 3);
    deleteNode(head, 2);
    deleteNode(head, 1);

    print(head);

  
    print(head);

    getLength(head);

    getLlData(head, 25);

    insertAtEnd(head, 2);

    print(head);

    return 0;
}
