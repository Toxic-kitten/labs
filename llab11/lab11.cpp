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

bool increasing_sequence(Node* sent){
    Node* el = sent->next;
    while(el->next != sent){
        if(el->data < el->next->data){
            el = el->next;
        }
        else {
            return false;
        }
    }
    return true;
}

bool decreasing_sequence(Node* sent){
    Node* el = sent->next;
    while(el->next != sent){
        if(el->data > el->next->data){
            el = el->next;
        }
        else {
            return false;
        }
    }
    return true;
}

void Delete(Node* sent){
    Node* el = sent->next;
    while(el != sent){
        if(el->data % 15 == 0){
            Node* tmp = el;
            el = el->next;
            el->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            delete tmp;
        }
        else {
            el = el->next;
        }
    }
}

bool is_prime(int value){
    if(value < 2){
        return false;
    }
    for(int i=2; i<=sqrt(value); i++){
        if (value % i == 0){
            return false;
        }
    }
    return true;
}

void duplication_prime(Node* sent){
    Node* el = sent->next;
    while(el != sent){
        if(is_prime(el->data) == true){
            Node* new_el = new Node;
            new_el->data = el->data;
            new_el->prev = el->prev;
            el->prev->next = new_el;
            el->prev = new_el;
            new_el->next = el;
            el = el->next;
        }
        else {
            el = el->next;
        }
    }
}

int first_digit(int value){
    while(value > 9){
        value = value / 10;
    }
    return value;
}

void sort_for_down(Node* sent){
    Node* el = sent->next;
    while(el != sent){
        Node* next_el = el->next;
        while(next_el != sent){
            if(first_digit(el->data) < first_digit(next_el->data)){
                swap(el->data, next_el->data);
            }
            next_el = next_el->next;
        }
        el = el->next;
    }
}

void Clear(Node* sent){
    Node* el = sent->next;
    while(el != sent){
        Node* tmp = el;
        el = el->next;
        delete tmp;
    }
}

int main(){
    Node* sent = new Node;
    sent->next = sent;
    sent->prev = sent;

    int n;
    int ch;
    cout << "How many numbers do you want to enter?\n";
    cin >> n;
    cout << "Yout digits:\n";
    for(int i=0;i<n;i++){
        cin >> ch;
        AddBack(sent, ch);
    }

    if(increasing_sequence(sent) || decreasing_sequence(sent) == true){
        Delete(sent);
        duplication_prime(sent);
    }
    else{
        sort_for_down(sent);
    }
    
    Print(sent);
    
    Clear(sent);
    delete sent;
    return 0;
}