#include<iostream>
#include<memory>

using namespace std;

class Burger{
    public:
    virtual void prepare() = 0;
    virtual ~Burger(){
        cout<<"Burger destructor"<<endl;
    }
};

//TYPES OF BURGER

// 1.BASIC
class BasicBurger:public Burger{
    public:
    void prepare() override
    {
        cout<<"Basic Burger Preparing."<<endl;
    }
};

// 2.STANDARD
class StandardBurger:public Burger{
    public:
    void prepare() override
    {
        cout<<"Standard Burger Preparing."<<endl;
    }
};

// 3.PREMIUM
class PremiumBurger:public Burger{
    public:
    void prepare() override
    {
        cout<<"Premium Burger Preparing."<<endl;
    }
};



//FACTORY THAT IS CONCRETE
class BurgerFactory{
    public:
    virtual Burger* create_burger(const string& type) = 0;

    virtual ~BurgerFactory(){};
};


class BurgerSingh:public BurgerFactory{
    public:
    Burger* create_burger(const string& type) override
    {
        cout<<"THIS IS BURGER SINGH."<<endl;
        if(type == "BASIC")
            return new BasicBurger();
        else if(type == "STANDARD")
            return new StandardBurger();
        else if(type == "PREMIUM")
            return new PremiumBurger();
        else{
            cout<<"No such type of burger exists."<<endl;
            return nullptr;
        }
    }

};

class BurgerKing:public BurgerFactory{
    public:
    Burger* create_burger(const string& type) override
    {
        cout<<"THIS IS BURGER KING."<<endl;
        if(type == "BASIC")
            return new BasicBurger();
        else if(type == "STANDARD")
            return new StandardBurger();
        else if(type == "PREMIUM")
            return new PremiumBurger();
        else{
            cout<<"No such type of burger exists."<<endl;
            return nullptr;
        }
    }

};

int main()
{
    //1. Order standarad burger from burger sing.
    BurgerFactory* singhFactory = new BurgerSingh();
    Burger* burger_standard = singhFactory->create_burger("STANDARD");
    if(burger_standard)
        burger_standard->prepare();
    delete singhFactory;
    delete burger_standard;

    //2.Using smart pointers.
    unique_ptr<BurgerFactory> kingFactory = make_unique<BurgerSingh>();
    unique_ptr<Burger> burger_premium(kingFactory->create_burger("PREMIOUM"));
    if(burger_premium)
        burger_premium->prepare();
    
    return 0;
}