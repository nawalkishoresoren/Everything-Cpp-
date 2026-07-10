#include<iostream>

using namespace std;

class ICharacter{
    public:
    virtual void get_abilities() = 0;
    virtual ~ICharacter(){};
};

class Mario:public ICharacter{
    string name;
    public:
    Mario(){
        this->name = "Mario";
    }
    void get_abilities() override
    {
        cout<<name<<"'s ";
    }
    string get_name()
    {
        return name;
    }
};

class Luigie:public ICharacter{
    string name;
    public:
    Luigie(){
        this->name = "Luigie";
    }
    void get_abilities() override
    {
        cout<<name<<"'s ";
    }
    string get_name()
    {
        return name;
    }
};


class CharacterDecorator:public ICharacter{
    protected:
    ICharacter* wrapped_character;

    public:
    CharacterDecorator(ICharacter* character): wrapped_character(character) {};


    void get_abilities() override
    {
        wrapped_character->get_abilities();
    }

};

class HeightUP:public CharacterDecorator{
    public:
    HeightUP(ICharacter* character):CharacterDecorator(character){};
    void get_abilities() override
    {
        CharacterDecorator::get_abilities();
        cout<<"Height increased."<<endl;
    }
};

class PowertUP:public CharacterDecorator{
    public:
    PowertUP(ICharacter* character):CharacterDecorator(character){};
    void get_abilities() override
    {
        CharacterDecorator::get_abilities();
        cout<<"Power increased."<<endl;
    }
};

class HealthUP:public CharacterDecorator{
    public:
    HealthUP(ICharacter* character):CharacterDecorator(character){};
    void get_abilities() override
    {
        CharacterDecorator::get_abilities();
        cout<<"Health increased."<<endl;
    }
};

int main()
{
    ICharacter* player1 = new Mario();

    player1 = new HeightUP(player1);
    player1 = new HealthUP(player1);
    player1->get_abilities();

    return 0;
}