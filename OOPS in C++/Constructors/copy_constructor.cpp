#include<iostream>

using namespace std;

class Book{
    public:
    string title;
    string author;
    int* rates;
    int ratescounter;

    Book(string Title, string Author)
    {
        this->title = Title;
        this->author = Author;

        this->ratescounter = 2;
        rates = new int[ratescounter];
        rates[0] = 1;
        rates[1] = 2;
        cout<<"Constructor envoked for "<<this->title<<endl;
    }
    //COPY CONSTRUCTOR
    Book(const Book& original){
        this->title = original.title;
        this->author = original.author;
        this->ratescounter = original.ratescounter;

        this->rates = new int[this->ratescounter];
        for(int i=0;i<this->ratescounter;i++)
        {
            this->rates[i] = original.rates[i];
        }
    }

    //DECONSTRUCTOR
    ~Book()
    {
        delete [] rates;
        rates = nullptr;
        cout<<"Destructor envoked for "<<this->title<<endl;
    }
};

int main()
{
    Book book1("Harry Potther","J.K.Rolling");
    Book book2("C++ Book","Nawal");

    Book book3(book1);//COPY CONSTRUCTOR
    Book book4 = book1;//COPY CONSTRUCTOR

    return 0;
}