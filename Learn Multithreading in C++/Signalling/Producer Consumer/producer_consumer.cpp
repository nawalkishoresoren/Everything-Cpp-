#include<iostream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>


using namespace std;

template<typename E>
class blocking_queue
{
    mutex _mtx;
    condition_variable _cond;
    
    int _max_size;
    queue<E>q;
    public:
    blocking_queue(int max_size):_max_size(max_size)
    {

    }
    void push(E e)
    {
        unique_lock<mutex> lock(_mtx);
        _cond.wait(lock,[this](){return q.size()<_max_size;});
        q.push(e);
        cout<<"Push "<<e<<endl;
        lock.unlock();
        _cond.notify_one();
    }

    E front()
    {
        unique_lock<mutex> lock(_mtx);
        _cond.wait(lock,[this](){return !q.empty();});
        E item = q.front();
        return item;
    }

    E pop()
    {
        unique_lock<mutex> lock(_mtx);
        _cond.wait(lock,[this](){return !q.empty();});
        E item = q.front();
        q.pop();
        cout<<"Pop "<<item<<endl;
        lock.unlock();
        _cond.notify_one();
        return item;
    }
    int size()
    {
        lock_guard<mutex> lock(_mtx);
        return q.size();
    }
};

int main()
{
    blocking_queue<int>qu(3);

    thread t1([&](){
        for(int i=0;i<10;i++)
        {
            qu.push(i);
            cout<<"queue ka size"<<qu.size()<<endl;
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