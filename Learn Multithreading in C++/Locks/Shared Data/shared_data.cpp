#include<iostream>
#include<thread>
#include<chrono>
#include<atomic>

using namespace std;

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
    //int count = 0; //This is not atomic in nature.
    atomic<int>count = 0; //This is not atomic in nature. Thus only one threar can access it at a time.
    const int ITERATIONS = 1E6;


    thread t1([&count](){
        for(int i=0;i<ITERATIONS;i++)
        {
            ++count;
        }
    });
    thread t2([&count](){
        for(int i=0;i<ITERATIONS;i++)
        {
            ++count;
        }
    });


    //WAITS UNTIL THE THREADS COMPLETES THEIR WORK.
    t1.join();
    t2.join();

    cout<<count<<endl;

    return 0;
}