#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void function1(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"+";
    }
}

void function2(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"o";
    }
}

int main()
{
    thread t1(function1,10);
    thread t2(function2,10);

    t1.join();
    t2.join();

    return 0;
}