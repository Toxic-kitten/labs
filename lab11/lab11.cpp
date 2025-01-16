#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void AddBack(Node* sent, int value){
    Node* el = new Node;
    el->data = value;
    el->prev = sent->prev;
    el->next = sent;
    sent->prev->next = el;
    sent->prev = el;

}

void Print(Node* sent){
    Node* el = sent->next;
    while(el != sent){
        cout << el->data << " ";
        el = el->next;
    }
    
}

int main(){
    Node* sent = new Node;
    sent->next = sent;
    sent->prev = sent;

    AddBack(sent, 1);
    AddBack(sent, 2);
    Print(sent);
    
    delete sent;
    return 0;
}