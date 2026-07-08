#include<iostream>
#include<future>
#include<chrono>
#include<thread>
#include<vector>
#include<mutex>

using namespace std;

mutex mtx;
int work(int id)
{
    unique_lock<mutex> lock(mtx);
    cout<<"Starting "<<id<<endl;
    lock.unlock();
    this_thread::sleep_for(chrono::seconds(3));
    
    return id;
}
int main()
{
    vector<shared_future<int>>futures;

    for(int i=0;i<thread::hardware_concurrency();i++)
    {
        shared_future<int>f = async(launch::async,work,i);
        futures.push_back(f);
    }

    for(auto f:futures)
    {
        cout<<"Returned "<<f.get()<<endl;
    }
    return 0;
}