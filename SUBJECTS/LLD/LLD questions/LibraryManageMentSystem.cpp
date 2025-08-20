#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    string title, author, ISBN;
    bool isAvailable;

public:
    Book(string title, string author, string ISBN)
    {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        this->isAvailable = true;
    }

    bool checkedOut()
    {
        if (this->isAvailable)
        {
            this->isAvailable = false;
            return true;
        }
        else
        {
            return false;
        }
    }

    void returned()
    {
        if (this->isAvailable)
        {
            cout << "Book has not been checked out" << endl;
        }
        else
        {
            this->isAvailable = true;
            cout << "Book has been returned" << endl;
        }
    }

    string getTitle()
    {
        return this->title;
    }

    string getAuthor()
    {
        return this->author;
    }

    string getISBN()
    {
        return this->ISBN;
    }

    bool getAvailable()
    {
        return this->isAvailable;
    }
};

class Library
{
private:
    vector<Book *> books;

public:
    Library() = default;

    void addBook(Book *book)
    {
        books.push_back(book);
        cout << "Book has been added to the Library" << endl;
    }

    void removeBook(Book *book)
    {
        for (auto it = books.begin(); it != books.end(); it++)
        {
            if ((*it)->getISBN() == book->getISBN())
            {
                books.erase(it);
                cout << "Book has been removed from the Library" << endl;
                return;
            }
        }
        cout << "No book found in the Library" << endl;
    }

    Book *searchByISBN(string ISBN)
    {
        for (auto it = books.begin(); it != books.end(); it++)
        {
            if ((*it)->getISBN() == ISBN)
            {
                return *it;
            }
        }
        cout << "No Book found with ISBN: " << ISBN << endl;
        return nullptr;
    }

    Book *searchByTitle(string title)
    {
        for (auto it = books.begin(); it != books.end(); it++)
        {
            if ((*it)->getTitle() == title)
            {
                return *it;
            }
        }
        cout << "No Book found with Title: " << title << endl;
        return nullptr;
    }

    Book *searchByAuthor(string author)
    {
        for (auto it = books.begin(); it != books.end(); it++)
        {
            if ((*it)->getAuthor() == author)
            {
                return *it;
            }
        }
        cout << "No Book found with Author: " << author << endl;
        return nullptr;
    }

    void display()
    {
        for (auto it = books.begin(); it != books.end(); it++)
        {
            cout << "Book: | Title: " << (*it)->getTitle() << " Author: " << (*it)->getAuthor() << " ISBN: " << (*it)->getISBN() << '|' << endl;
        }
    }
};

class Patron
{
private:
    vector<Book *> checkedOutBooks;
    string name, id;

public:
    Patron(string name, string id)
    {
        this->name = name;
        this->id = id;
    }

    void checkOutBook(Book *book)
    {
        bool check = book->checkedOut();
        if (check == true)
        {
            checkedOutBooks.push_back(book);
            cout << "Book has been checked out to: " << this->name << endl;
        }
        else
        {
            cout << "Book is not available" << endl;
        }
    }

    void returnedBook(Book *book)
    {
        for (auto it = checkedOutBooks.begin(); it != checkedOutBooks.end(); it++)
        {
            if ((*it)->getISBN() == book->getISBN())
            {
                checkedOutBooks.erase(it);
                book->returned();
                cout << "Book has been returned by: " << this->name << endl;
                return;
            }
        }
        cout << "No Book is checked out with ISBN: " << book->getISBN() << " by: " << this->name << endl;
    }

    string getName()
    {
        return this->name;
    }

    string getId()
    {
        return this->id;
    }
};

class checkedOut
{
private:
    map<Book *, pair<Patron *, time_t>> checkouts;
    const int DAY_SEC = 60 * 60 * 24;

public:
    void checkout(Book *book, Patron *patron)
    {
        if (book->getAvailable())
        {
            patron->checkOutBook(book);
            time_t dueTime = time(0) + 7 * DAY_SEC;
            checkouts[book] = {patron, dueTime};
        }
        else
        {
            cout << "Book is not available" << endl;
        }
    }

    void returnBook(Book *book)
    {
        if (checkouts.find(book) != checkouts.end())
        {
            Patron *patron = checkouts[book].first;
            patron->returnedBook(book);
            checkouts.erase(book);
        }
        else
        {
            cout << "Book has not been checked out" << endl;
        }
    }

    time_t getDueDate(Book *book)
    {
        if (checkouts.find(book) != checkouts.end())
        {
            return checkouts[book].second;
        }
        else
        {
            cout << "Book has not been checked out" << endl;
            return -1;
        }
    }
};

int main()
{
    Library *l = new Library();

    Book *b1 = new Book("A", "A1", "IXT1");
    Book *b2 = new Book("AA", "A11", "IXT2");
    Book *b3 = new Book("AAA", "A111", "IXT3");
    Book *b5 = new Book("AAAAA", "A11111", "IXT5");
    Book *b4 = new Book("AAAA", "A1111", "IXT4");

    Patron *p1 = new Patron("Suren", "IX1");
    Patron *p2 = new Patron("Karan", "IX2");

    l->addBook(b1);
    l->addBook(b2);
    l->addBook(b3);
    l->addBook(b4);
    l->addBook(b5);

    l->display();

    checkedOut *c = new checkedOut();
    c->checkout(b3, p2);

    time_t dueDate = c->getDueDate(b3);
    if (dueDate != -1)
    {
        cout << "Due Date: " << ctime(&dueDate) << endl;
    }

    Book *p = l->searchByISBN("IXT4");
    if (p != nullptr)
    {
        cout << p->getTitle() << endl;
    }
}
