#include <iostream>
#include <string>
using namespace std;
class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }
    ~LibraryItem()
    {
    }
    void setTitle(string newTitle)
    {
        title = newTitle;
    }
    string getTitle()
    {
        return title;
    }
    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }
    string getAuthor()
    {
        return author;
    }
    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }
    string getDueDate()
    {
        return dueDate;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

};
class Book : public LibraryItem
{
private:
    string ISBN;
    int quantity;

public:
    Book(string t, string a, string d, string isbn, int q) : LibraryItem(t, a, d)
    {
        ISBN = isbn;
        quantity = q;

        if (quantity <= 0)
        {
            cout << "Invalid quantity" << endl;
        }
        if (ISBN.length()!= 13)
        {
            cout << "ISBN must contain 13 characters" << endl;
        }
    }
    void checkOut()override{
        cout<<"Book checked out: "<<getTitle()<<endl;
    }
    void returnItem()override{
        cout<<"Book returned: "<<getTitle()<<endl;
    }
    void displayDetails()override{
        cout<<"---Book Details---"<<endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Quantity: " << quantity << endl;
    }
    
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur) : LibraryItem(t, a, d)
    {
        duration = dur;
    }
    int getduration()
    {
        return duration;
    }
    void checkOut() override
    {
        cout << "DVD checked out: " << getTitle() << endl;
    }
    void returnItem() override
    {
        cout << "DVD returned: " << getTitle() << endl;
    }
    void displayDetails() override
    {
        cout << "---DVD Details---" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << getduration() << endl;
    }
};
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int num) : LibraryItem(t, a, d)
    {
        issueNumber = num;
    }
    int getIssueNumber()
    {
        return issueNumber;
    }
    void checkOut() override
    {
        cout << "Magazine checked out: " << getTitle() << endl;
    }
    void returnItem() override
    {

        cout << "Magazine returned: " << getTitle() << endl;
    }
    void displayDetails() override
    {
        cout << "---Magazine Details---" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Issue Number: " << getIssueNumber() << endl;
    }
};
int main()
{
    int MAX_ITEMS = 100;
    int choice, count = 0;
    LibraryItem* libraryItems[MAX_ITEMS];

    do
    {
        cout << "---Library Management System---" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Add a DVD" << endl;
        cout << "3. Add a magazine" << endl;
        cout << "4. Display All Items" << endl;
        cout << "5. Checkout an item" << endl;
        cout << "6. Return an Item" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string t, a, d, isbn;
            int q;
            cout << "Enter the title: ";
            cin.ignore();
            getline(cin, t);

            cout << "Enter the Author name: ";
            getline(cin, a);

            cout << "Enter the duedate: ";
            getline(cin, d);

            cout << "Enter the ISBN number: ";
            getline(cin, isbn);

            cout << "Enter the quantity: ";
            cin >> q;

            libraryItems[count++] = new Book(t, a, d, isbn, q);
            cout << "Book Added Successfully!"<<endl;;
        }
        else if (choice == 2)
        {
            string t, a, d;
            int duration;
            cout << "Enter the title: ";
            cin.ignore();
            getline(cin, t);

            cout << "Enter the Author name: ";
            getline(cin, a);

            cout << "Enter the duedate: ";
            getline(cin, d);

            cout << "Enter duration: ";
            cin >> duration;

            libraryItems[count++] = new DVD(t, a, d, duration);
            cout << "DVD Added Successfully!"<<endl;
        }
        else if (choice == 3)
        {
            string t, a, d;
            int issuenumber;
            cout << "Enter the title: ";
            cin.ignore();
            getline(cin, t);

            cout << "Enter the Author name: ";
            getline(cin, a);

            cout << "Enter the duedate: ";
            getline(cin, d);

            cout << "Enter the Issue Number: ";
            cin >> issuenumber;

            libraryItems[count++] = new Magazine(t, a, d, issuenumber);
            cout << "Magazine Added Succesfully!"<<endl;
        }
        else if (choice == 4)
        {
            if (count == 0)
                cout << "Library is empty!";
            for (int i = 0; i < count; i++)
            {
                libraryItems[i]->displayDetails();
            }
        }
        else if (choice == 5 || choice == 6)
        {
            string t;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, t);

            for (int i = 0; i < count; i++)
            {
                if (choice == 5)
                    libraryItems[i]->checkOut();
                else
                    libraryItems[i]->returnItem();
            }
        }

    } while (choice != 0);

    return 0;
}