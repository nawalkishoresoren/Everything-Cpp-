#include<iostream>
#include<mutex>


using namespace std;


class Singleton{

    Singleton(){
        cout<<"Singleton constructor called."<<endl;
    }
    static Singleton* instance;
    static mutex mtx;

    public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* get_instance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
    Singleton* s1 = Singleton::get_instance();
    Singleton* s2 = Singleton::get_instance();

    cout<<(s1==s2)<<endl;

    return 0;
}