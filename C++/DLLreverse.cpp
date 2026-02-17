#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
    public: 
        Node(int data1, Node* next1, Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};
Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i< arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data << " ";
        head = head-> next;
    }
}

// Function to reverse DLL using stack
void reverseDLL(Node* head) {
    stack<int> st;
    Node* temp = head;

    // Step 1: Push all data into stack
    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Step 2: Replace data by popping from stack
    temp = head;
    while (temp != NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
}

Node* reverseDLLswap(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    while(current!=NULL){
        prev = current->back;
        current -> back = current->next;
        current->next = prev;

        current = current -> back;
    }
    // After loop, prev will be at node before new head
    if(prev != NULL){
        return prev->back;
    }

    return head;
}
int main(){
    vector<int> arr = { 2, 5,7,8,9,11,14,15,17, 20};
    Node* head = convertArr2DLL(arr);

    cout << "Original: ";
    print(head);
    cout << endl;

    head = reverseDLLswap(head);

    cout << "Reversed: ";
    print(head);

    return 0;
}