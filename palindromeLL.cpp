#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;

     //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
     //destructor
 
    ~node(){
        cout<<"deleted element"<<data<<endl;
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
void printLL(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
}
class solution{

    private:

    bool checkpalindrome(vector<int>arr){
        int n=arr.size();
        int s=0;
        int l=n-1;

        while(s<=l){
            if(arr[s] != arr[l]){
                return 0;
            }
            s++;
            l--;
        }
        return 1;

    }

    public:

    bool palindromeLL(node* head){
        
        vector<int>arr;
        node* temp =head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp=temp->next;

        }
        return checkpalindrome(arr);

    }
};


int main(){
    node* new1 = new node(1);
    node* head = new1;
 insertAtFirst(head, 4);
    insertAtFirst(head, 1);
    insertAtFirst(head, 1);
    insertAtFirst(head, 4);
    insertAtFirst(head, 1);
    
    printLL(head);
    
    solution sol;
    bool isPalindrome = sol.palindromeLL(head);
    if (isPalindrome)
        cout << "Linked list is a palindrome." << endl;
    else
        cout << "Linked list is not a palindrome." << endl;

return 0;
}