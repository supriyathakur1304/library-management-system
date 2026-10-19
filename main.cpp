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

    virtual void checkOut(){
        cout<<getTitle()<<endl;
    }
    virtual void returnItem(){
        cout<<getTitle()<<endl;
    }
    virtual void displayDetails()
    {
        cout << getTitle() << endl;
        cout << getAuthor() << endl;
        cout << getDueDate() << endl;
    }
};
class Book : public LibraryItem
{
    public:
    Book(string t, string a, string d) : LibraryItem(t, a, d)
    {
    }
    void checkOut() override{
        cout<<getTitle()<<endl;
    }
    void returnItem() override{
        cout<<getTitle()<<endl;
    }
    void displayDetails() override
    {
        cout << getTitle() << endl;
        cout << getAuthor() << endl;
        cout << getDueDate() << endl;
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
    void checkOut() override{
        cout<<getTitle()<<endl;
    }
    void returnItem() override{
        cout<<getTitle()<<endl;
    }
    void displayDetails() override
    {
        cout << getTitle() << endl;
        cout << getAuthor() << endl;
        cout << getDueDate() << endl;
        cout << getduration() << endl;
    }
};
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int num) : LibraryItem(t, a, d)
    {
        issueNumber=num;
    }
    int getissueNumber(){
        return issueNumber;
    }
    void checkOut() override{
        cout<<getTitle()<<endl;
    }
    void returnItem() override{
        cout<<getTitle()<<endl;
    }
    void displayDetails() override
    {
        cout << getTitle() << endl;
        cout << getAuthor() << endl;
        cout << getDueDate() << endl;
        cout << getissueNumber() << endl;
    }
};
int main()
{
    int MAX_ITEMS=100;
    int choice,count=0;
    LibraryItem* libraryItems[MAX_ITEMS];

    

do{
    cout << "---Library Management System---" << endl;
    cout << "1. Add a book: " << endl;
    cout << "2. Add a DVD: " << endl;
    cout << "3. Add a magazine: " << endl;
    cout<<"4. Add for checkout: "<<endl;
    cout<<"5. Add for return: "<<endl;
    cout<<"6. Add for display: "<<endl;
    cout<<"7. Exit"<<endl;

    cout << "Enter your choice: " << endl;
    cin >> choice;

    if(choice==1){
        string t,a,d;
        cout<<"Enter the title: "<<endl;
        cin.ignore();
        getline(cin,t);
        
        cout<<"Enter the Author name: "<<endl;
        getline(cin,a);

        cout<<"Enter the duedate: "<<endl;
        getline(cin,d);

        libraryItems[count]=new Book(t,a,d);
    }
    else if(choice==2){
        int duration;
        cout<<"Enter DVD duration in minutes: "<<endl;
        cin>>duration;
        cin.ignore();
       

    }
    else if(choice==3){

    }

   }
   while(choice!=0);


    return 0;
}