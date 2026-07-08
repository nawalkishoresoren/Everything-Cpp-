#include<iostream>
#include<list>
#include<string>

using namespace std;

class YoutubeChannel{
    public:
    string name;
    int subscribers;

    YoutubeChannel(string Name, int Subscribers){
        this->name = Name;
        this->subscribers = Subscribers;
    }
    bool operator==(const YoutubeChannel& channel) const
    {
        return this->name == channel.name;
    }
};

//GLOBAL OPERATOR OVERLOADING
/*
This cant be used for + - = in global;
*/
ostream& operator<<(ostream& COUT,YoutubeChannel& channel)
{
    COUT<<"Name: "<<channel.name<<" "<<"Subscribers: "<<channel.subscribers<<endl;
    return COUT;
}

struct Mycollection{
    list<YoutubeChannel>myChannels;

    void operator+=(YoutubeChannel& channel)
    {
        this->myChannels.push_back(channel);
    }
    void operator-=(YoutubeChannel& channel)
    {
        this->myChannels.remove(channel);
    }
    

    void get_channels()
    {
        for(auto channel : myChannels)
        {
            cout<<"Channel name = "<<channel.name<<" subscribers = "<<channel.subscribers<<endl;
        }
    }

    
};
ostream& operator<<(ostream& COUT,Mycollection& mycollection)
{
    for(auto channel:mycollection.myChannels)
    {
        COUT<<channel<<endl;
    }
    return COUT;
}

int main()
{
    // YoutubeChannel* yt = new YoutubeChannel("Code with Nawal", 1000000);
    // cout<<yt;
    cout<<string(50,'=')<<endl;

    YoutubeChannel yt1 = YoutubeChannel("Code_with_Nawal", 1000000);
    YoutubeChannel yt2 = YoutubeChannel("Code_with_Nawal2", 2000000);

    //THERE ARE 2 METHODS TO CALL THE OPERATOR OVERLOAD

    //METHOD 1
    cout<<yt1<<yt2;

    //METHOD 2
    operator<<(cout,yt1);


    //OPERATOR OVERLOAD USING MENBER FUNCTION
    cout<<string(50,'=')<<endl;
    Mycollection mycollection = Mycollection();
    mycollection += yt1;
    mycollection.get_channels();
    mycollection += yt2;
    mycollection.get_channels();
    mycollection -= yt2;
    mycollection.get_channels();



    cout<<string(50,'=')<<endl;
    cout<<mycollection;

    
    return 0;
}