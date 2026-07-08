#include<iostream>
#include<thread>
#include<chrono>
#include<atomic>
#include<mutex>


using namespace std;

//CREATE A MUTEX
mutex mtx;

void work(int &count, mutex &mtx)
{
    for(int i=0;i<1E6;i++)
    {
        // lock_guard<mutex> guard(mtx); //WORKS WITHIN SCOPE SO STARTS HERE AND ENDS AT THE END OF THE SCOPE.
        unique_lock<mutex> guard(mtx);
        ++count;        //CRITICAL SECTION.
    }
}

int main()
{
    int count = 0; //This is not atomic in nature.

    thread t1(work,ref(count),ref(mtx));
    thread t2(work,ref(count),ref(mtx));


    //WAITS UNTIL THE THREADS COMPLETES THEIR WORK.
    t1.join();
    t2.join();

    cout<<count<<endl;

    return 0;
}