#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class Linklist
{
public:
    Node *head;
    Node *tail;
    Linklist()
    {
        head = NULL;
        tail = NULL;
    }

    int lengthll()
    {
        if (head == 0 or tail == 0)
        {
            return 0;
        }
        else
        {
            Node *temp = head;
            int i = 0;
            while (temp != NULL)
            {
                i++;
                temp = temp->next;
            }
            return i;
        }
    }

    void insertathead(int val)
    {
        Node *n1 = new Node(val);

        if (head == NULL)
        {
            head = n1;
            tail = n1;
        }
        else
        {
            n1->next = head;
            head->prev = n1;
            head = head->prev;
        }
    }
    void insertattail(int val)
    {
        Node *n1 = new Node(val);
        if (tail == NULL)
        {
            head = n1;
            tail = n1;
        }
        else
        {
            tail->next = n1;
            n1->prev = tail;
            tail = n1;
        }
    }

    void printll()
    {
        if (head == NULL)
        {
            cout << "Linklist is empty" << endl;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertmiddle(int val, int pos)
    {
        Node *newNode = new Node(val);
        int i = 0;
        Node *temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        Node *curr = temp->next;
        temp->next = newNode;
        newNode->next = curr;
        curr->prev = newNode;
        newNode->prev = temp;
    }

    void deleteHead()
    {
        head = head->next;
        head->prev = NULL;
        delete (head->prev);
    }

    void deletetail()
    {
        tail = tail->prev;
        tail->next = NULL;
        delete (tail->next);
    }
    void deleteNode(int pos)
    {
        if (pos == 0)
        {
            deleteHead();
        }
        else if (pos == lengthll()-1)
        {
            deletetail();
        }
        else
        {
            int i = 0;
            Node *temp = head;
            while (i < pos )
            {
                temp = temp->next;
                i++;
            }
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete (temp);
        }
    }
};

int main()
{

    Linklist ll;
    ll.insertathead(20);
    ll.insertathead(21);
    ll.insertathead(22);
    ll.insertathead(23);
    ll.printll();
    ll.insertattail(100);
    ll.insertmiddle(200, 3);
    ll.printll();
    cout<<ll.lengthll()<<endl;
    ll.deleteNode(5);
    ll.printll();

    return 0;
}