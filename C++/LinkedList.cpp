#include <bits/stdc++.h>
using namespace std;

class Node { //can be written struct instead of class
    public: 
        int data;
        Node * next;

    public:    
    // Node(int data1, Node * next1){  //constructor
    //     data = data1;
    //     next = next1;
    // }
    Node(int data1){  //constructor
        data = data1;
        next = nullptr;
    }
};

Node* convertArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next =  temp;
        mover = temp;
    }
    return head;
};

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

int checkIfPresent(Node* head, int target){
    Node* temp = head;
    while(temp){
        if(temp->data == target) return 1;
        temp = temp -> next;
    }
    return 0;
}


Node* deleteHead(Node* head){
    if (head == NULL) return head;
    Node * temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node * deleteLast(Node * head){
    if (head  == NULL || head->next == NULL) return head;
    Node * temp = head;
    while(temp->next->next != NULL){
        temp = temp-> next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head-> next;
    }
    cout<< endl;
}

int main(){
    // Node x = Node(2, nullptr );
    // Node *y = &x;

    // Node *y = new Node (2, nullptr);

    vector<int> arr = {2,5,7,9,11,13};
    Node* head = convertArrToLL(arr);
    // //Method 1: 
    // Node* y = new Node( arr[0], nullptr);
    // cout<< y-> data;

    // //Method 2: 
    // Node a = Node(arr[1], nullptr); //object
    // cout<< a.data;

    
    //cout<< head->data;
    // Node* temp = head;
    // while(temp){
    //     cout<< temp-> data<< " ";
    //     temp = temp->next;
    // }
    // cout<<endl;
    // cout<< lengthOfLL(head)<<endl;
    // cout<< checkIfPresent(head, 11)<<endl;

    head = deleteLast(head);
    print(head); //2 5 7 9 11 , 13 deleted

    
    






    return 0;
}
