#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {

        data = 0;
        next = NULL;
    }
    Node(int data)
    {

        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    int lengght()
    {
        int i = 0;
        if (head == NULL or tail == NULL)
        {
            return 0;
        }

        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                i++;
                temp = temp->next;
            }
            return i;
        }
    }

    void printLinkList()
    {
        if (head == NULL)
        {
            cout << "The LinkList is empty";
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void insertathead(int v)
    {
        Node *n = new Node(v);
        n->next = head;
        if (head == NULL)
        {
            tail = n;
        }
        head = n;
    }

    void insertattail(int v)
    {
        Node *n = new Node(v);
        if (tail == NULL)
        {
            head = n;
        }
        else
        {
            tail->next = n;
        }
        tail = n;
    }

    void insertmiddle(int v, int position)
    {
        Node *insertionNode = new Node(v);
        Node *temp = head;
        int i = 0;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        Node *curr = temp->next;
        temp->next = insertionNode;
        insertionNode->next = curr;
    }

    void deletehead()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deletetail()
    {
        int i = 0;
        Node *temp = 0;
        while (i < lengght() - 1)
        {
            temp = temp->next;
            i++;
        }
        tail = temp;
        temp = temp->next;
        tail->next = NULL;
        delete (temp);
    }
    void deletingNode(int pos)
    {
        int leng = lengght();
        if (pos == 0)
        {
            deletehead();
        }
        else if (pos == leng)
        {
            deletetail();
        }
        else
        {
            Node *temp = head;
            int i = 0;
            while (i<pos-1)
            {
                i++;
                temp = temp->next;
            }
            Node *curr = temp->next;
            temp->next = curr->next;
            curr->next = NULL;
            delete (curr);
        }
    }
};

int main()
{
    // Node *n1 = new Node(10);
    // Node *n2 = new Node(20);
    // Node *n3 = new Node(30);
    // Node *n4 = new Node(40);
    // Node *n5 = new Node(50);
    // Node *n6 = new Node(60);
    // Node *n7 = new Node(70);

    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n6;
    // n6->next = n7;
    LinkedList ll;
    ll.insertathead(20);
    ll.insertathead(40);
    ll.insertathead(30);
    ll.insertathead(40);
    ll.insertathead(20);
    ll.insertattail(70);
    ll.insertmiddle(100, 3);
    ll.printLinkList();
    int i = ll.lengght();
    cout << "fffffff" << i<<endl;
    ll.deletingNode(6);
    ll.printLinkList();

    // cout<<Node::head->data;
    // cout<<endl<<Node::tail->data;
    return 0;
}