#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void AddBack(Node* head, int value){
    Node* p = head;
    while(p->next != nullptr){
        p = p->next;
    }
    Node* e = new Node;
    e->data = value;
    e->next = p->next;
    p->next = e;
    // p->data = value;
    // p->next = head->next;
    // head->next = p;
}

void print(Node* head) {
    Node* p = head->next;
    while (p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

bool check_condition(Node* head){
    Node* p = head->next;
    while (p != nullptr && p->next != nullptr){
        Node* r = p->next;
        if(p->data < r->data){
            return false;
        }
        r = r->next;
        p = p->next;
    }
    return true;
}

bool is_not_prime(int value){
    for(int i=2; i<value-1; i++){
        if (value % i == 0){
            return true;
        }
    }
    return false;
}

void Delete(Node* head){
    Node* p = head;
    while(p->next != nullptr){
        if(is_not_prime(p->next->data)){
            Node* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
        else{
            p = p->next;
        }
    }
}

int main(){
    Node* head = new Node;
    head->next = nullptr;
    int n;
    cout << "How many numbers do you want to add to the list?\n";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Your digits number " << i << ": ";
        int r;
        cin >> r;
        AddBack(head, r);
    }
    if(check_condition(head) == true){
        Delete(head);
    }
    print(head);
}