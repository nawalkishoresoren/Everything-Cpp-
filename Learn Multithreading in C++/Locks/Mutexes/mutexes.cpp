#include<iostream>
#include<thread>
#include<chrono>
#include<atomic>
#include<mutex>


using namespace std;


//CREATE A MUTEX
mutex mtx;

void work()
{
    for(int i=0;i<10;i++)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"Loop "<<i<<endl;
    }
}

int main()
{
    int count = 0; //This is not atomic in nature.

    const int ITERATIONS = 1E6;

    auto func = [&](){
        for(int i=0;i<ITERATIONS;i++)
        {
            mtx.lock();     //ONLY 1 THREAD CAN GO PAST AT A TIME.
            ++count;        //CRITICAL SECTION.
            mtx.unlock();   //REMOVE THE LOCK
        }
    };


    thread t1(func);
    thread t2(func);


    //WAITS UNTIL THE THREADS COMPLETES THEIR WORK.
    t1.join();
    t2.join();

    cout<<count<<endl;

    return 0;
}