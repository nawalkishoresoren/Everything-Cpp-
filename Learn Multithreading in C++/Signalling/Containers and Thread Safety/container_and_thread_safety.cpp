#include<iostream>
#include<thread>
#include<queue>

using namespace std;

template<typename E>
class blocking_queue
{
    int _max_size;
    queue<E>q;
    public:
    blocking_queue(int max_size):_max_size(max_size)
    {

    }
    void push(E e)
    {
        q.push(e);
        cout<<"Push "<<e<<endl;
    }

    E pop()
    {
        E item = q.front();
        q.pop();
        cout<<"Pop"<<endl;
        return item;
    }
};

int main()
{
    blocking_queue<int>qu(5);

    thread t1([&](){
        for(int i=0;i<10;i++)
        {
            qu.push(i);
        }

    });
    thread t2([&](){
        for(int i=0;i<10;i++)
        {
            int item = qu.pop();
            cout<<"consumer "<<item<<endl;
        }

    });

    t1.join();
    t2.join();

    return 0;
}