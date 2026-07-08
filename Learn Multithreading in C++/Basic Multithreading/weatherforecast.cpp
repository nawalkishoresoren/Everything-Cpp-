#include<iostream>
#include<map>
#include<thread>
#include<chrono>

using namespace std;


//REFRESH THE TEMP EVERY 2SEC IN AN INFINITE TIMER.
void refresh_forecast(map<string,int> forecast_map)
{
    cout<<string(50,'=')<<endl;
    while(1)
    {
        for(auto& item:forecast_map)
        {
            item.second ++;
            cout<<item.first<<" - "<<item.second<<endl;
        }
        this_thread::sleep_for(chrono::seconds(2));
        cout<<string(50,'=')<<endl;
    }
    
}

int main()
{
    map<string,int>forecast_map = {
        {"New York",15},
        {"Mumbai",20},
        {"Berlin",18},
    };

    //CREATE A THREAD.
    thread t1(refresh_forecast,forecast_map);

    t1.join();

    return 0;
}