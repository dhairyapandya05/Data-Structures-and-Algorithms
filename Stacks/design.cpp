#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int top;
    int size;
    int *arr;
    Stack(int size)
    {
        arr = new int[size];
        top = -1;
        size = 0;
    }
    void push(int val)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = val;
            // this->top=val;
        }
        else
        {
            cout << "The stack is full" << endl;
        }
    }

    void printstack()
    {
        int i=top;
        while (i >= 0)
        {
            cout << arr[i] << " ";
            i--;
        }
        cout << endl;
    }
    void topEle()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "The top element is " << arr[top]<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            top--;
        }
    }
    int getSize(){
        return top+1;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    Stack *st = new Stack(10);
    st->push(1);
    st->push(12);
    st->push(22);
    st->push(20);
    st->push(30);
    st->printstack();
    st->topEle();
    st->pop();
    st->printstack();
    st->topEle();
    cout<<endl<<st->getSize();
    cout<<endl<<st->isEmpty()<<endl;
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->printstack();
    cout<<st->isEmpty()<<endl;
    // cout<<"Hello World"<<endl;
    return 0;
}