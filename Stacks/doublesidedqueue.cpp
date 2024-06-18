#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int top1;
    int size;
    int top2;
    int *arr;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }
    void push1(int val)
    {
        if (top2 - top1 == 1)
        {
            cout << "Stack is full operation can't be performed" << endl;
        }
        else
        {
            top1++;
            arr[top1] = val;
        }
    }

    void push2(int val)
    {
        if (top2 - top1 == 1)
        {
            cout << "Stack is full operation can't be performed" << endl;
        }
        else
        {
            top2--;
            arr[top2] = val;
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Pop operation can't be performed" << endl;
        }
        else
        {
            arr[top1] = -1;
            top1--;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "Pop operation can't be performed" << endl;
        }
        else
        {
            arr[top2] = -1;
            top2++;
        }
    }
    void printstack()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int sizestack()
    {
        return top1 + size - top2 + 1;
    }

    void top1ele()
    {
        if (top1 != -1)
        {
            cout << endl
                 << "Value of top1" << arr[top1];
        }
        else
        {
            cout << endl
                 << "Value of top1 is unknown as stack is empty";
        }
    }

    void top2ele()
    {
        if (top2 != size)
        {
            cout << endl
                 << "Value of top2" << arr[top2];
        }
        else
        {
            cout << endl
                 << "Value of top2 is unknown as stack is empty";
        }
    }
};
int main()
{
    Stack *st = new Stack(10);
    st->push1(10);
    st->push2(20);
    st->push2(30);
    st->push2(40);
    st->push1(25);
    st->printstack();

    st->pop1();
    st->pop2();
    st->printstack();
    cout << st->sizestack() << endl;
    st->top1ele();
    cout<<endl;
    st->printstack();
    cout<<endl;

    st->top2ele();
    cout<<endl;
    st->printstack();


    return 0;
}