#include <bits/stdc++.h>
using namespace std;
class literature  // Base class for literature
{
    long int unique_id;
    string title;

protected:
    void getdata()    // Method to get literature data from user
    {
        cout << "Enter Unique Id of Book :";
        cin >> unique_id;
        cout << "Enter Title Of the Book :";
        fflush(stdin);
        getline(cin, title);
    }
    void putdata()    // Method to display literature data
    {
        cout<<left<<setw(12)<<unique_id<<setw(35)<<title;
    }
};
class e_literature : virtual protected literature   // Class for electronic literature, inheriting from literature
{
    string DOI;

protected:
    void getdata()    // Method to get electronic literature data from user
    {
        literature::getdata();
        cout << endl
             << "Enter DOI of the book :";

            fflush(stdin);
        getline(cin,DOI);

    }
    void putdata()    // Method to display electronic literature data
    {
        cout<<left<<setw(50)<<DOI<<endl;
    }
};
class hard_bound : virtual protected literature // Class for hardbound literature, inheriting from literature
{
    int NumberOfCopies;

protected:
    void getdata()    // Method to get hardbound literature data from user
    {
        literature::getdata();
        cout << "Enter Number of copies :";
        cin >> NumberOfCopies;
    }
    void putdata()    // Method to display hardbound literature data
    {
        cout<<left<<setw(15)<<NumberOfCopies<<endl;
    }
};
class book : protected e_literature, protected hard_bound   // Class for book, inheriting from electronic literature and hardbound
{
    int ISBN;
    char ch;

public:
    void getdata()    // Method to get book data from user
    {
        cout << "Enter ISBN of Book :";
        cin >> ISBN;

        cout << "(E)copy or (H)ardbound :";
        cin >> ch;

         if (ch == 'h' || ch == 'H')
        {
            hard_bound::getdata();
        }
        else
        {
            e_literature::getdata();
        }

    }
    void putdata()    // Method to display book data
    {
        literature::putdata();
        cout<<left<<setw(12)<<ISBN;
         if (ch == 'h' || ch == 'H')
        {
            hard_bound::putdata();
        }
        else
        {
            e_literature::putdata();
        }

    }
};

// Class for magazine, inheriting from electronic literature and hardbound

class magazine : protected e_literature, protected hard_bound
{
    int ISSN;
    char ch;

public:
    void getdata()    // Method to get magazine data from user
    {
        cout << "Enter ISSN of Book :";
        cin >> ISSN;

        cout << "(E)copy or (H)ardbound :";
        cin >> ch;


         if (ch == 'h' || ch == 'H')
        {
            hard_bound::getdata();

        }
        else
        {
            e_literature::getdata();

        }

    }
    void putdata()    // Method to display magazine data
    {
        literature::putdata();
        cout<<left<<setw(12)<<ISSN;
         if (ch == 'h' || ch == 'H')
        {
            hard_bound::putdata();
        }
        else
        {
            e_literature::putdata();
        }
      

    }
};
int main()
{
    book B[100];    // Method to display magazine data
    magazine M[100]; // Array to store magazines
   int btop=0,mtop=0;// Variables to track the top of each array

A:
    int choice;
    cout << "Enter 1 : Add book data" << endl;
    cout << "Enter 2 : Add magazine data" << endl;
    cout << "Enter 3 : List all books" << endl;
    cout << "Enter 4 : List all Magazines" << endl;
    cout << "Enter 5 : Exit"<<endl;
    cout << "Enter your choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
        B[btop].getdata();
        btop++;

        break;
    case 2:
        M[mtop].getdata();
        mtop++;
        break;

    case 3:
        cout<<setw(50)<<"*******List of All Books*******"<<endl;

        for (int  i = 0; i <btop; i++)
        {
            B[i].putdata();
        }
        break;

    case 4:
        cout<<setw(50)<<"*******List of All Magazines*******"<<endl;
        for (int  i = 0; i <mtop; i++)
        {
            M[i].putdata();
        }
        break;
    case 5:
        return 0;
    default:
    cout << "Enter valid choice ....";
        goto A;
        break;
    }

    goto A;

    return 0;
}