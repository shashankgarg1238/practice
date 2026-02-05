#include <bits/stdc++.h>
using namespace std;

class Node { //can be written struct instead of class
    public: 
        int data;
        Node * next;

    public:    
    Node(int data1, Node * next1){  //constructor
        data = data1;
        next = next1;
    }
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
void print(Node* head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head-> next;
    }
    cout<< endl;
}

Node* insertHead( Node* head, int val){
    Node* temp = new Node(val, head); //value and memory address
    return temp;
} 

Node* insertTail(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp-> next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head; 
}

Node * insertPos(Node* head, int element, int k){
    if(head==NULL){
        if(k==1){
            return new Node(element);
        }else{
            return head;
        }
    }
    if(k==1){
        return new Node(element, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(element,temp->next);
            temp->next = x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//insert element before the value x
Node* insertBeforevalue(Node* head, int element, int val){
    if(head==NULL)return NULL;
    
    if(head->data==val){
        return new Node(element, head);
    }
    
    Node* temp = head;
    while(temp->next !=NULL){
        if(temp->next->data == val){
            Node* x = new Node(element,temp->next);
            temp->next = x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {2,5,7,9,11,13};
    Node* head = convertArrToLL(arr);
    //head = insertHead(head,100);

    //head = insertTail(head,55);  
    //head = insertPos(head,250,3);
    //head = insertBeforevalue(head, 500,5);
    print(head);
    
    return 0;
}
