//CONSTRUCTORS
/*

1.Constructor need to have the same name of the class.
2.It does not have a return type.
3.Almost always in public area (EXCEPT ->SINGLETON class)
4.Default constructor has no parameters.
5.C++ automatically creates a constructor if not defined by the user.
6.Constructor is called when object is created.

*/
#include<iostream>

using namespace std;

class User{
    public:
    string FirstName;
    string LastName;
    int age;

    //DEFAULT CONSTRUCTOR
    User(){
        this->FirstName = "nn";
        this->LastName = "nn";
        this->age = 0;

        cout<<"DEFAULT CONSTRUCTOR Constructor Invoked"<<endl;
    }

    //PARAMETERISED CONSTRUCTOR
    User(string f_name,string l_name,int age){
        this->FirstName = f_name;
        this->LastName = l_name;
        this->age = age;
        cout<<"PARAMETERISED CONSTRUCTOR Constructor Invoked"<<endl;
    }

};

void get_user_function(User u)
{
    cout<<"First Name = "<<u.FirstName<<endl;
    cout<<"Last Name = "<<u.LastName<<endl;
    cout<<"Age = "<<u.age<<endl;
}

int main()
{
    //THIS IS CALLING DEFAULT CONSTRUCTOR.
    cout<<string(50,'=')<<endl;
    User user1;
    cout<<string(50,'=')<<endl;

    get_user_function(user1);

    

    //THIS IS CALLING PARAMETERISED CONSTRUCTOR.
    cout<<string(50,'=')<<endl;
    User user2("Nawal","Soren",25);
    cout<<string(50,'=')<<endl;

    get_user_function(user2);
    
    return 0;
}