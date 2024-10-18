#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        string name;
        Node* prev;
        Node* next;
        Node(string val, Node* p = nullptr, Node* = nullptr) {
            name = val;
            name = p;
            next = n;
        }
    };
   
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(const string& customer) {
        Node* newNode = new Node (customer);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    //func to print current lines
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }

    void add_initial_customers(const vector<string>& names) {
        cout << "Store opens: \n";
        for (int i = 0; i < 5; i++) {
            string customer = names[rand()% names.size()];
            cout << customer << " joins the line \n";
            push_back(customer);
        }
    };

   
int main() {
    srand(time(0));

    vector<string> customer_names = {"Jean","Iris","Omar","Andy","Drew", };

    DoublyLinkedList coffeeShopLine;
    coffeeShopLine.add_initial_customers(customer_names);
    
    return 0;
}