//Khizar Ali Shah
//2020196
#include <iostream>
using namespace std;

class node // singly linked node
{
    private:
        int data;
        node* next;
        static node* head;
        static int count;
    public:
        node(int val) { this->next = nullptr; this->data = val; }

        static void insertAtTail(int);
        static void print();
        static void evenOdd(); // time complexity O(n) and space complexity O(1)
};

node* node::head = nullptr;
int node::count = 0;

int mainMenu();

int main()
{   // commented out a test case and ran the other one, vise-versa
    //test case 1
    for(int i=1; i<=5; ++i)
        node::insertAtTail(i);

    //test case 2
    // node::insertAtTail(2);
    // node::insertAtTail(1);
    // node::insertAtTail(3);
    // node::insertAtTail(5);
    // node::insertAtTail(6);
    // node::insertAtTail(4);
    // node::insertAtTail(7);

    while(mainMenu()) // function runs 0 (false) when user wants to exit
    {
    }

    return 0;
}

void node::insertAtTail(int val)
{
    if(head == nullptr)
    {
        head = new node(val);
        ++count;
        return;
    }

    node* temp = head;

    while(temp->next != nullptr) // can also be done using tail pointer (I did not use it)
        temp = temp->next;

    temp->next = new node(val);
    ++count;
}

void node::print()
{
    node* temp = head;

    cout << "List: ";

    if(head == nullptr)
        cout << "Empty!";

    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void node::evenOdd()
{
    if(head == nullptr || head->next == nullptr)
        return;

    node* temp = head;
    node* nextNode = nullptr;
    node* newHead = head->next;

    while(temp->next->next != nullptr)
    {
        nextNode = temp->next;
        temp->next = nextNode->next;
        temp = nextNode;
    }
    

    if(count % 2 != 0)
    {
        temp->next = head;
    }
    else
    {
        temp->next->next = head;
        temp->next = nullptr;
    }

    head = newHead;

    cout << "\n\nList Successfully converted to EVEN ODD LIST!!\n\n";
}

int mainMenu()
{
    cout << "\n\n------Main Menu------\n1. Insert node\n2. Print list\n3. Converted into even/odd\n4. Exit program\n\nYour choice: ";
    int choice, val;
    cin >> choice;

    if( !cin || choice < 1 || choice > 4)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\n\nPlease enter a valid choice\n\n";
        return 1;
    }

    switch(choice)
    {
        case 1:
            cout << "Value: ";
            cin >> val;
            node::insertAtTail(val);
            break;
        case 2:
            node::print();
            break;
        case 3:
            node::evenOdd();
            break;
        case 4:
            return 0;
    }

    return 1;
}