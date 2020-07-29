#include <iostream>

using namespace std;

void header_bar()
{
    cout<<"___________________________________________________________";
}
void header_equal()
{
    cout<<"\t   ===============================================================================================";
}
void menu()
{
    cout<<"\nPress a number to open that window\n\n"<<endl;
    header_equal();
    cout<<"\n\n\t        1. Buy a book \t2. Update Price \t3. Add new book \t4. Display Stats\n"<<endl;
    header_equal();
    cout<<"\n\nYour Choice: ";
}
void header(string s)
{
    header_bar();
    cout<<"\n\n\t\t\t"<<s<<"\n"<<endl;
    header_bar();
    cout<<"\n\n";
}
void book_header(int n)
{
    header_bar();
    cout<<"\n\n\t\t   Book Number: "<<n<<"\n"<<endl;
    header_bar();
    cout<<"\n\n";
}

class Books
{
private:
    string Author;
    string Title;
    double Price;
    string Publisher;
    int Stock_Position; //I am assuming it is how many books are in stock
    static int Book_Number;   //Using this to make total numbers
    int Book_Num;             //Using this for individual books
public:
    Books()
    {
        Author=" ";
        Title=" ";
        Price=0.0;
        Publisher= " ";
        Stock_Position=0;
        //setBooknum(getBook_Number()+1);
        Book_Num=0;
    }
    Books(string A, string T, double P, string PU, int S)
    {
        setAuthor(A);
        setTitle(T);
        setPrice(P);        //this is a different data type i.e double
        setPublisher(PU);    //this is a string type P.
        setStockPosition(S);
        setBooknum(getBook_Number()+1);
    }



    void setAuthor(string AU)       {Author=AU;}
    void setTitle (string TI)       {Title=TI;}
    void setPrice (double PR)       {Price=PR;}
    void setPublisher (string PU)   {Publisher=PU;}
    void setStockPosition (int SP)  {Stock_Position=SP;}
    void setBooknum(int bn)         {Book_Num=bn;}

    string getAuthor()              {return Author;}
    string getTitle()               {return Title;}
    double getPrice()               {return Price;}
    string getPublisher()           {return Publisher;}
    int getBooknum()                {return Book_Num;}

    int getBook_Number()            {return Book_Number;}
    void setBook_Number(int n)      {Book_Number=n;}
    int getStockPosition()          {return Stock_Position;}

    void display_info()
    {
        book_header(Book_Num);
        cout<<"Title: "<<getTitle()<<endl;
        cout<<"Author: "<<getAuthor()<<endl;
        cout<<"Price: "<<getPrice()<<endl;
        cout<<"Publisher: "<<getPublisher()<<endl;
        cout<<"Stock Position: "<<getStockPosition()<<endl;
    }
    void Book_Number_Generator()
    {
        setBooknum(getBook_Number()+1);
        Book_Number++;
    }
    void input_data()
    {
        Book_Number_Generator();
        book_header(Book_Num);
        cout<<"Enter Title: "<<endl;
        cin>>Title;
        cout<<"Enter Author: "<<endl;
        cin>>Author;
        cout<<"Enter Price: "<<endl;
        cin>>Price;
        cout<<"Enter Publisher: "<<endl;
        cin>>Publisher;
        cout<<"Enter Stock Position: "<<endl;
        cin>>Stock_Position;
    }

};

int Books::Book_Number=100;

class Inventory
{
    Books books[10];
    static int Successful_Transactions;
    static int Unsuccessful_Transactions;
    string Search_Title;
    int Copies;
    static int Index;
public:
    Inventory()
    {
        //we cannot initialize static members here
    }
    Inventory(Books a, Books b, Books c, Books d)
    {
        books[0].setAuthor(a.getAuthor());
        books[0].setPrice(a.getPrice());
        books[0].setPublisher(a.getPublisher());
        books[0].setStockPosition(a.getStockPosition());
        books[0].setTitle(a.getTitle());
        books[0].Book_Number_Generator();
        //books[0].setBook_Number(a.getBook_Number() );

        books[1].setAuthor(b.getAuthor());
        books[1].setPrice(b.getPrice());
        books[1].setPublisher(b.getPublisher());
        books[1].setStockPosition(b.getStockPosition());
        books[1].setTitle(b.getTitle());
        books[1].Book_Number_Generator();
        //books[1].setBook_Number(b.getBook_Number() +1 );

        books[2].setAuthor(c.getAuthor());
        books[2].setPrice(c.getPrice());
        books[2].setPublisher(c.getPublisher());
        books[2].setStockPosition(c.getStockPosition());
        books[2].setTitle(c.getTitle());
        books[2].Book_Number_Generator();
        //books[2].setBook_Number(c.getBook_Number() +1);

        books[3].setAuthor(d.getAuthor());
        books[3].setPrice(d.getPrice());
        books[3].setPublisher(d.getPublisher());
        books[3].setStockPosition(d.getStockPosition());
        books[3].setTitle(d.getTitle());
        books[3].Book_Number_Generator();
        //books[3].setBook_Number(d.getBook_Number() +1 );

    }

    int getUNS_T() {return Unsuccessful_Transactions;}
    int getS_T()   {return Successful_Transactions;}

    void Search_Book()
    {
        header("Buy Book");
        char choice;
        bool Result=false;
        double price;
        cout<<"Enter the Title of the book: ";
        cin>>Search_Title;
        for (int i=0 ; i<=9 ; i++)
        {
            if(Search_Title==books[i].getTitle())
            {
                cout<<"Book found"<<endl;
                Result=true;
                books[i].display_info();
                cout<<"\nNumber of Copies Required: ";
                cin>>Copies;
                if(Copies<=books[i].getStockPosition())
                {
                    price=Copies * books[i].getPrice();
                    cout<<"Total Price: "<<price<<endl;
                    cout<<"Would you like to complete the transaction?[Y/N] "<<endl;
                    cin>>choice;
                    if (choice=='Y' || choice=='y')
                    {
                        books[i].setStockPosition(books[i].getStockPosition()-Copies);
                        cout<<"Remaining Stock left: "<<books[i].getStockPosition();
                        Successful_Transactions++;
                    }
                    else if (choice=='N' || choice=='n')
                    {
                        cout<<"Book not bought!"<<endl;
                        cout<<"Stock Position: "<<books[i].getStockPosition();
                        Unsuccessful_Transactions++;
                    }
                    else
                        cout<<"Wrong choice!"<<endl;
                }
                else
                    cout<<"Not enough copies available"<<endl;
            }
        }
        if(Result==false)
            cout<<"Book not found"<<endl;
    }

    void Update_Price()
    {
        header("Update Price");
        char Choice;
        int Price;
        bool Result=false;
        cout<<"Would you like to update a book's price? [Y/N]"<<endl;
        cin>>Choice;
        if (Choice=='Y')
        {
            cout<<"Enter Book Title name: "<<endl;
            cin>>Search_Title;
            for (int i=0 ; i<=9 ; i++)
            {
                if (Search_Title==books[i].getTitle())
                {
                    Result=true;
                    books[i].display_info();
                    cout<<"Enter new price: ";
                    cin>>Price;
                    books[i].setPrice(Price);
                    cout<<"Book's price successfully updated"<<endl;
                    books[i].display_info();
                }
            }
            if (Result==false)
                cout<<"Book not found!"<<endl;
        }
        else if (Choice=='N')
        {
            cout<<"Closing book update window!"<<endl;
        }
        else
        {
            cout<<"Wrong choice!"<<endl;
        }
    }
    void Add_New_Book()
    {
        header("Add a new book");
        cout<<"Please enter the details of the new book."<<endl;
        books[Index].input_data();
        cout<<"Book added successfully!"<<endl;
        Index++;

    }
    void Display_Stats()
    {
        header("Statistics");
        cout<<"Unsuccessful Transactions: "<<getUNS_T()<<endl;
        cout<<"Successful Transactions: "<<getS_T()<<endl;
    }
};

int Inventory::Successful_Transactions=0;
int Inventory::Unsuccessful_Transactions=0;
int Inventory::Index=4;

int main()
{
    header_equal();
    cout<<"\n\t\t\t\t\t   Program Book Shop Inventory"<<endl;
    header_equal();
    cout<<"\n\n";

    Books book_1 ( "Caroline" , "Calculus" , 500 , " Textbook Board" , 50);
    Books book_2 ("Anna" , "How_to_cook_sushi" , 1000 , "Chinese Publisher" , 50);    //we can use concatentation here
    Books book_3 ("Picasso" , "How_to_draw" , 5000 , "French company" , 25);            //which is addition of two strings
    Books book_4 ("J.K_Rowling" , "Harry_Potter" , 250 , "American" , 100);      //But I am using underscore to avoid complication
    Inventory Inv ( book_1, book_2, book_3, book_4);

    char exit;
    int Option;
    while (1) //always true untill we press exit
    {
        menu();
        cin>>Option;
        switch (Option)
        {
        case 1:
            Inv.Search_Book();
            break;
        case 2:
            Inv.Update_Price();
            break;
        case 3:
            Inv.Add_New_Book();
            break;
        case 4:
            Inv.Display_Stats();
            break;
        default:
            cout<<"Wrong option!"<<endl;
            break;
        }

        cout<<"\nPress 'e' or 'E' to quit or press any key to continue"<<endl;
        cin>>exit;
        if (exit=='e' || exit=='E')
        {
            break;
        }
        cout<<"Continue"<<endl;
    }


    return 0;
}
