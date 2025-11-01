#include <iostream>
#include <string>
using namespace std;

struct node 
{
    int prn;
    string name;
    node* next;
};

node *temp,*temp1,*temp2;

class SLLPin 
{
public:
    node *head,*tail,*nnode;

    SLLPin()  
    {
        head = tail = NULL;
    }

    void crt();
    void dplay();
    void insertAtBeginning();
    void insertAtEnd();
    void intermediate();
    void dltbegin();
    void dltlast();
    void dltintermediate();
    void count();
    void concatenation(SLLPin &L2);  
};

void SLLPin::crt() 
{
    char ch;
    do 
    {
        nnode = new node;
        nnode->next = NULL;
        cout << endl << "Enter PRN number: ";
        cin >> nnode->prn;
        cout << "Enter name of user: ";
        cin >> nnode->name;

        if (head == NULL) 
        {
            head = tail = nnode;
        } 
        else 
        {
            tail->next = nnode;
            tail = nnode;
        }
        cout << "Do you want to continue (y/n): ";
        cin >> ch;
    } while(ch == 'y' || ch == 'Y');

    dplay();
}

void SLLPin::dplay() 
{
    temp = head;
    if (temp == NULL) 
    {
        cout << endl << "Club is empty!";
        return;
    }

    cout << endl << "Club Members:";
    while (temp != NULL) 
    {
        cout << endl << "PRN: " << temp->prn << "  Name: " << temp->name;
        temp = temp->next;
    }
    cout << endl;
}

void SLLPin::insertAtBeginning() 
{ 
    nnode = new node;
    nnode->next = NULL;
    cout << endl << "Enter president name: ";
    cin >> nnode->name;
    cout << "Enter PRN of president: ";
    cin >> nnode->prn;

    nnode->next = head;
    head = nnode;
    dplay();
}

void SLLPin::insertAtEnd() 
{
    nnode = new node;
    nnode->next = NULL;
    cout << endl << "Enter secretary name: ";
    cin >> nnode->name;
    cout << "Enter PRN of secretary: ";
    cin >> nnode->prn;

    if (tail != NULL)
    {
        tail->next = nnode;
        tail = nnode;
    }
    else
    {
        head = tail = nnode;
    }

    dplay();
}

void SLLPin::intermediate() 
{
    cout << endl << "Intermediate insertion";
    int key;
    cout << endl << "Enter the PRN of club member after which you want to insert: ";
    cin >> key;

    nnode = new node;
    nnode->next = NULL;
    cout << "Enter PRN number to insert: ";
    cin >> nnode->prn;
    cout << "Enter name of user: ";
    cin >> nnode->name;

    temp = head;
    while (temp != NULL && temp->prn != key) 
    {
        temp = temp->next;
    }
    if (temp == NULL) 
    {
        cout << "PRN not found!";
        delete nnode;
        return;
    }

    nnode->next = temp->next;
    temp->next = nnode;
    if (temp == tail) tail = nnode;

    dplay();
}

void SLLPin::dltbegin() 
{
    if (head == NULL) return;

    temp = head;
    cout << endl << "You deleted president = " << temp->name;
    head = temp->next;
    delete temp;

    if (head == NULL) tail = NULL;

    dplay();
}

void SLLPin::dltlast() 
{
    if (head == NULL) return;

    if (head == tail) 
    {
        cout << endl << "You deleted secretary = " << tail->name;
        delete tail;
        head = tail = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != tail) 
        {
            temp = temp->next;
        }
        cout << endl << "You deleted secretary = " << tail->name;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    dplay();
}

void SLLPin::dltintermediate() 
{
    int key;
    cout << endl << "Enter the member prn that you want to delete: ";
    cin >> key;

    temp = head;
    while (temp->next != NULL && (temp->next->prn) != key) 
    {
        temp = temp->next;
    }

    temp1 = temp->next;
    temp2 = temp1->next;

    cout << endl << "You deleted member = " << temp1->prn;
    delete temp1;
    temp->next = temp2;

    if (temp2 == NULL) tail = temp;

    dplay();
}

void SLLPin::count() 
{
    int c = 0;
    temp = head;
    while (temp != NULL) 
    {
        c++;
        temp = temp->next;
    }
    cout << endl << "Total number of members: " << c << endl;
}

void SLLPin::concatenation(SLLPin &L2) 
{
    if (L2.head == NULL) return; 
    if (head == NULL) 
    {
        head = L2.head;
        tail = L2.tail;
    } 
    else 
    {
        tail->next = L2.head;
        tail = L2.tail;
    }
}

int main() 
{
    SLLPin l1;
    cout << endl << "Welcome to club 1" << endl;
    l1.crt();
    l1.insertAtBeginning();
    l1.insertAtEnd();
    l1.intermediate();
    l1.dltbegin();
    l1.dltlast();
    l1.dltintermediate();

    // second club
    SLLPin l2;
    cout << endl << "Welcome to club 2" << endl;
    l2.crt();
    l2.insertAtBeginning();
    l2.insertAtEnd();
    l2.intermediate();
    l2.dltbegin();
    l2.dltlast();
    l2.dltintermediate();

    // concatenation
    cout << endl << "Concatenating club 2 into club 1..." << endl;
    l1.concatenation(l2);

    l1.count();
    l1.dplay();
}
