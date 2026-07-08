#include<iostream>
#include<future>
#include<chrono>
#include<thread>
#include<vector>
#include<mutex>
#include<cmath>

#include<queue>

using namespace std;

mutex mtx;


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
        cout<<"Push "<<endl;
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
        cout<<"Pop "<<endl;
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

int work(int id)
{
    unique_lock<mutex> lock(mtx);
    cout<<"Starting "<<id<<endl;
    lock.unlock();
    int seconds = (5.0*rand())/RAND_MAX + 3;
    this_thread::sleep_for(chrono::seconds(3));
    
    return id;
}
int main()
{
    blocking_queue<shared_future<int>>futures(2);

    thread t([&](){
        for(int i=0;i<20;i++)
        {
            shared_future<int>f = async(launch::async,work,i);
            futures.push(f);
        }
    });

    for(int i=0;i<20;i++)
    {
        shared_future<int>f = futures.pop();
        cout<<"Returned "<<f.get()<<endl;
    }
    t.join();
    return 0;
}