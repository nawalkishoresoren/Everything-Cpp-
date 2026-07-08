#include<iostream>
#include<future>
#include<chrono>
#include<thread>


using namespace std;

int work(int id)
{
    for(int i=0;i<5;i++)
    {
        cout << "Runnning "<< id << endl;
        this_thread::sleep_for(chrono::microseconds(1000));
    }
    return id*7;
}

int main()
{
    // auto f1 = async(launch::deferred,work, 5); //Runs in 2 mode.
    // f1.get();

    // future<void>f = async(launch::async,work, 1); //Runs in 2 mode.

    future<int>f1 = async(launch::async,work, 0);
    future<int>f2 = async(launch::async,work, 1);

    cout<<f1.get()<<endl;
    cout<<f2.get()<<endl;
    

    return 0;
}