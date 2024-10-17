#include <iostream>
#include <map>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  // constructor
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }

  // destructor
  ~Node() {
    int value = this->data;
    // memory free
    if (this->next != NULL) {
      delete next;
      this->next = NULL;
    }
    cout << "Memory is freed for node with data " << value << endl;
  }
};

void insertAtHead(Node *&head, int d) {
  // new node create
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}

void insertAtTail(Node *&tail, int d) {
  // new node create
  Node *temp = new Node(d);
  if (tail == NULL) {
    tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void print(Node *head) {
  if (head == NULL) {
    cout << "List is empty " << endl;
    return;
  }
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d) {
  // Insert at Start
  if (position == 1) {
    insertAtHead(head, d);
    if (tail == NULL) {
      tail = head;
    }
    return;
  }

  Node *temp = head;
  int cnt = 1;

  while (temp != NULL && cnt < position - 1) {
    temp = temp->next;
    cnt++;
  }

  if (temp == NULL || temp->next == NULL) {
    insertAtTail(tail, d);
    return;
  }

  Node *nodeToInsert = new Node(d);

  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head) {

  if (position == 1) {
    Node *temp = head;
    head = head->next;
    // Memory free start node-----
        temp->next = NULL;
    delete temp;
  }
   else {

    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;
    while (curr != NULL && cnt < position) {
      prev = curr;      
      curr = curr->next;
      cnt++;
    }

    if (curr == NULL) {
      cout << "Position out of range" << endl;
      return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

bool isCircularList(Node *head) {
  // Empty list
  if (head == NULL) {
    return true;
  }

  Node *temp = head->next;
  while (temp != NULL && temp != head) {
    temp = temp->next;
  }

  return temp == head;
}

bool detectLoop(Node *head) {
  if (head == NULL)
    return false;

  map<Node *, bool> visited;
  Node *temp = head;

  while (temp != NULL) {
    // Cycle is present
    if (visited[temp] == true) {
      cout << "Present on element " << temp->data << endl;
      return true;
    }
    visited[temp] = true;
    temp = temp->next;
  }
  return false;
}

Node *floydDetectLoop(Node *head) {
  if (head == NULL)
    return NULL;

  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      cout << "Loop detected at node with data: " << slow->data << endl;
      return slow;
    }
  }

  return NULL;
}

Node *getStartingNode(Node *head) {
  Node *intersection = floydDetectLoop(head);
  if (intersection == NULL)
    return NULL;

  Node *slow = head;
  while (slow != intersection) {
    slow = slow->next;
    intersection = intersection->next;
  }                  
  return slow;
}

void removeLoop(Node *head) {
  Node *startOfLoop = getStartingNode(head);
  if (startOfLoop == NULL)
    return;

  Node *temp = startOfLoop;
  while (temp->next != startOfLoop) {
    temp = temp->next;
  }
  temp->next = NULL;
  cout << "loop is remove" << endl;
}

int main() {
  // Created a new node
  Node *node1 = new Node(10);
  // Head pointed to node1
  Node *head = node1;
  Node *tail = node1;

  insertAtTail(tail, 12);
  insertAtTail(tail, 15);
  insertAtPosition(head, tail, 4, 22);

  tail->next = head->next;

  cout << "Head: " << head->data << endl;
  cout << "Tail: " << tail->data << endl;

  if (floydDetectLoop(head) != NULL) {
    cout << "Cycle is present " << endl;
  } else {
    cout << "No cycle" << endl;
  }

  removeLoop(head);
  print(head);

  return 0;
}
