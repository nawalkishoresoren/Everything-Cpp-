#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class ISubscriber{
    public:
    virtual void update() = 0;
    virtual ~ISubscriber(){};
};

class IChannel{
    public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notify_all() = 0;

    virtual ~IChannel(){};

};

class Channel:public IChannel{
    vector<ISubscriber*> subscribers;
    string name;
    string latest_video;

    public:
    Channel(const string& Name){
        this->name = Name;
    }
    void subscribe(ISubscriber* subscriber) override
    {
        if(find(subscribers.begin(),subscribers.end(),subscriber) == subscribers.end())
            subscribers.push_back(subscriber);
    }
    void unsubscribe(ISubscriber* subscriber) override
    {
        auto it = find(subscribers.begin(),subscribers.end(),subscriber);
        if(it!=subscribers.end())
            subscribers.erase(it);
    }
    void notify_all()
    {
        for(auto subscriber:subscribers)
        {
            subscriber->update();
        }
    }

    void upload_video(const string& titlle)
    {
        latest_video = titlle;
        cout<<"New video uploaded on channel."<<endl;
        cout<<"Title : "<<latest_video<<endl;
        notify_all();
    }

    string get_channel_name()
    {
        return name;
    }

    string get_latest_video()
    {
        return latest_video;
    }

};

class Subscriber:public ISubscriber{
    private:
    string name;
    Channel* channel;
    public:
    Subscriber(string Name, Channel* Channel){
        this->name = Name;
        this->channel = Channel;
    }

    void update() override
    {
        cout<<"Hey "<<name<<" new vidoe uploaded by "<<channel->get_channel_name()<<endl;
        cout<<"Title : "<<channel->get_latest_video()<<endl;
    }
};


int main()
{
    //CREATING CHANNEL
    Channel* channel = new Channel("Codig with Nawal");


    //CRAETING SUBSCRIBERS
    Subscriber* varun = new Subscriber("Varun",channel);
    Subscriber* aryan = new Subscriber("Aryan",channel);

    //SUBSCRIBE TO CHANNEL.
    channel->subscribe(varun);
    channel->subscribe(aryan);

    //UPLOAD
    channel->upload_video("Learning C++.");

    return 0;
}