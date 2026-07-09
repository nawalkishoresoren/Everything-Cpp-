#include<iostream>

using namespace std;

class IPayment_Strategy{
    public:
    virtual void pay(const float& amount) = 0;
    virtual ~IPayment_Strategy(){};
};

class UPI:public IPayment_Strategy{
    public:
    void pay(const float& amount)
    {
        cout<<"Rs."<<amount<<" payed using UPI."<<endl;
    }
};
class CardPayment:public IPayment_Strategy{
    public:
    void pay(const float& amount)
    {
        cout<<"Rs."<<amount<<" payed using Credit/Debit card."<<endl;
    }
};
class NetBanking:public IPayment_Strategy{
    public:
    void pay(const float& amount)
    {
        cout<<"Rs."<<amount<<" payed using Net Banking."<<endl;
    }
};

class PaymentService{
    IPayment_Strategy* payment_strategy;
    public:
    PaymentService(IPayment_Strategy* strategy = nullptr): payment_strategy(strategy) {};

    void set_strategy(IPayment_Strategy* strategy)
    {
        payment_strategy = strategy;
    }

    void pay(const float& amount)
    {
        payment_strategy->pay(amount);
    }

};



int main()
{
    //PAYMENT SERVIC
    PaymentService payment_service;

    IPayment_Strategy* upi = new UPI();
    IPayment_Strategy* card = new CardPayment();
    IPayment_Strategy* net = new NetBanking();

    // 1. Pay using UPI
    payment_service.set_strategy(upi);
    payment_service.pay(200);

    // 2. Dynamically switch to Card at runtime
    payment_service.set_strategy(card);
    payment_service.pay(500);
    return 0;
}