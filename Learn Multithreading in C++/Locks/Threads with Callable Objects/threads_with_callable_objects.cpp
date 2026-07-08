#include<iostream>
#include<thread>
#include<chrono>
#include<atomic>
#include<mutex>


using namespace std;

//CREATE A MUTEX
mutex mtx;


class App{
    int count = 0;
    public:
    void operator()()
    {
        for(int i=0;i<1E6;i++)
        {
            const lock_guard<mutex> guard(mtx); //WORKS WITHIN SCOPE SO STARTS HERE AND ENDS AT THE END OF THE SCOPE.
            ++count;        //CRITICAL SECTION.
        }
    }
    int get_count()
    {
        return count;
    }
};

int main()
{
    App app;

    thread t1(ref(app));
    thread t2(ref(app));


    //WAITS UNTIL THE THREADS COMPLETES THEIR WORK.
    t1.join();
    t2.join();

    cout<<app.get_count()<<endl;

    return 0;
}