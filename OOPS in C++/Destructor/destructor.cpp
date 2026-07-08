#include<iostream>

using namespace std;

class Book{
    public:
    string title;
    string author;

    Book(string Title, string Author)
    {
        this->title = Title;
        this->author = Author;
        cout<<"Constructor envoked for "<<this->title<<endl;
    }

    //DECONSTRUCTOR
    ~Book()
    {
        cout<<"Destructor envoked for "<<this->title<<endl;
    }
};

int main()
{
    Book book1("Harry Potther","J.K.Rolling");
    Book book2("C++ Book","Nawal");

    return 0;
}