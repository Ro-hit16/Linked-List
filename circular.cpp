#include <iostream>
using namespace std;
class node {
public:
  int data;
  node *next;

  // constructor
  node(int data) {
    this->data = data;
    this->next = NULL;
  }

  // destructor
  ~node() {
    int value = this->data;
    if (this->next != NULL) {
      this->next = NULL;
      delete next;
    }
  }
};

void insertatfirsttt(node *&tail, node *&head, int data) {
  if (tail == NULL) {
    node *newnode = new node(data);
    newnode->next = newnode;
    tail = newnode;
    head = newnode;
  } else {
    node *newnode = new node(data);
    newnode->next = head;
    tail->next = newnode;
    head = newnode;
  }
}
void print(node *tail, node *head) {
  if (tail == NULL) {
    cout << "list is empty";
    return;
  }
  node *temp = tail->next;
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}

void insertatPosition(node *&tail, node *&head, int data, int index) {
  if (index < 0) {
    cout << "Invalid index\n";
    return;
  }

  node *newnode = new node(data);
  if (tail == NULL) {
    newnode->next = newnode;
    tail = newnode;
    head = newnode;
    return;
  }

  if (index == 0) {
    newnode->next = tail->next;
    tail->next = newnode;
    return;
  }

  node *temp = tail;
  for (int i = 0; i < index; i++) {
    if (temp->next == tail) {
      // If the index is out of bounds, insert at the end of the list
      newnode->next = tail->next;
      tail->next = newnode;
      tail = newnode;
      return;
    }
    temp = temp->next;
  }

  // Insert at the specified position
  newnode->next = temp->next;
  temp->next = newnode;
}
void deletenode(node *&tail, int position) {
  if (tail == NULL) {
    cout << "List is empty\n";
    return;
  }

  if (position < 0) {
    cout << "Invalid position\n";
    return;
  }

  if (position == 0) {
    // Deleting the first node
    if (tail->next == tail) {
      // Only one node in the list
      delete tail;
      tail = NULL;
      return;
    }
    node *temp = tail->next;
    tail->next = temp->next;
    delete temp;
    return;
  }

  int count = 0;
  node *temp = tail;
  while (count < position - 1 && temp->next != tail) {
    temp = temp->next;
    count++;
  }

  if (count != position - 1) {
    cout << "Position out of bounds\n";
    return;
  }

  if (temp->next == tail) {
    cout << "Position out of bounds\n";
    return;
  }

  node *toDelete = temp->next;
  temp->next = temp->next->next;
  if (toDelete == tail) {
    tail = temp;
  }
  delete toDelete;
}

int main() {

  node *head = NULL;
  node *tail = NULL;

  insertatfirsttt(tail, head, 33);
  insertatfirsttt(tail, head, 43);
  print(tail, head);
  insertatPosition(tail, head, 44, 1);
  print(tail, head);
  deletenode(tail, 3);
  print(tail, head);
}