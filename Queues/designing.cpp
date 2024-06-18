#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int front;
    int back;
    int size;
    int *arr;
    Queue(int size)
    {
        this->size = size;
        front = 0;
        back = 0;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    void pushQ(int val)
    {
        if (back == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[back] = val;
            back++;
        }
    }

    void popQ()
    {
        if (back - front == 0)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[front] = 0;
            front++;
        }
    }
    void printQ()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void frontQ(){
        if(front==0){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Front element is "<<arr[front];
        }
    }
};

int main()
{
    Queue *q = new Queue(10);
    q->pushQ(10);
    q->pushQ(23);
    q->pushQ(20);
    q->printQ();
    q->popQ();
    q->printQ();
    q->frontQ();
    return 0;
}