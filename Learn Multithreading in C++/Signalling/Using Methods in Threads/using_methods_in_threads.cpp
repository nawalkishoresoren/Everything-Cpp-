#include<iostream>
#include<thread>

using namespace std;

template<typename E>
class blocking_queue
{
    public:
    void push(E e)
    {
        cout<<"Push "<<e<<endl;
    }

    void pop()
    {
        cout<<"Pop"<<endl;
    }
};

int main()
{
    blocking_queue<int>q;

    thread t1(blocking_queue<int>::push, &q,7);
    thread t2(blocking_queue<int>::pop, &q);

    t1.join();
    t2.join();

    return 0;
}