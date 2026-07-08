#include<iostream>
#include<thread>
using namespace std;

int main()
{
    cout<<thread::hardware_concurrency()<<endl; //NO OF THREAD THAT CAN BE USED.
    return 0;
}