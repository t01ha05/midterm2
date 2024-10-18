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

    //function to push customer to back of line
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
    
    //added function to push vip customers to front of line
    void push_front(const string& customer){
        Node* newNode = new Node(customer);
        if(!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head-> prev = newNode;
            head = newNode;
        }
    }

    //now i need func to pop the customer from front of the line
    void pop_front(){
        if(!head) {
            cout << "Line is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head-> next;
        if (head) head->prev=nullptr;
        else tail = nullptr;
        delete temp;
    }

    //now i need one to pop back
    void pop_back(){
        if(!tail) {
            cout << "Line is empty." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail-> next;
        if (tail) tail->next=nullptr;
        else head = nullptr;
        delete temp;    
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
    //func to add initial customers
    void add_initial_customers(const vector<string>& names) {
        cout << "Store opens: \n";
        for (int i = 0; i < 5; i++) {
            string customer = names[rand()% names.size()];
            cout << customer << " joins the line \n";
            push_back(customer);
        }
        cout << "Resulting line: \n";
        print();
    }

    // now i need to write a fucntion to simulate the events
    void simulate_events(const vector<string>& names, int time_step) {
        cout << "TIME STEP #" << time_step << ":\n";

        //40% chance to help customer
        int prob = rand() % 100 + 1;
        if(prob <= 40) {
            if (head) {
                cout << head->name << "is served\n"
                pop_front();
            }
        }

        //60% chance for new customer to join line
        int prob = rand() % 100 + 1;
        if(prob <= 60) {
            string new_customer = names[rand()% names.size()];
            cout << new_customer << " joins the line\n";
            push_back(new_customer)a;
        }

        //20% chance for customer at rear leaves the line
        prob = rand() % 100 + 1;
        if (prob <= 20 && tail) {
            cout << tail->name << " (at the rear) left the line\n";
            pop_back();
        }
        //10% chance for random customer to leave the line 
        prob = rand() % 100 + 1;
        if (prob <= 10){
            cout << "A random customer leaves the line \n";
        }
        //10% Chance for a vip customer to join front
        prob = rand()% 100 + 1;
        if (prob <= 10) {
            string vip_customer = names[rand()% names.size()];
            cout << vip_customer << " (VIP) joins front of the line\n";
            push_front(vip_customer);
        }
        //print resulting line
        cout << "Resulting line: \n";
        print():
    }
};

int main() {
    srand(time(0));

    vector<string> customer_names = {"Jean","Iris","Omar","Andy","Drew", };

    DoublyLinkedList coffeeShopLine;
    coffeeShopLine.add_initial_customers(customer_names);

    //simulate for 20 steps
    for (int time_step = 1; time_step <= 20; time_step++) {
        coffeeShopLine.simulate_events(customer_names, time_step);
        cout << "--------------------------------\n"
    }
    
    return 0;
}