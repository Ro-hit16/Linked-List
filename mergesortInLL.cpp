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

void insertAtFirst(node* &head, int data) {
    node* newnode = new node(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* getmidLL(node* &head) {
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    node* ans = new node(0); // Create a dummy node
    node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    // Attach remaining nodes if any
    if (left != NULL)
        temp->next = left;
    else if (right != NULL)
        temp->next = right;

    return ans->next; // Return the actual head of the merged list
}

node* mergesort(node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* mid = getmidLL(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergesort(left);
    right = mergesort(right);

    node* result = merge(left, right);
    return result;
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
    head = mergesort(head);
    print(head);

    return 0;
}
