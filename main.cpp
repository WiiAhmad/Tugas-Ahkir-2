#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Deklarasi struct untuk data buku
struct Book
{
    string title;
    string author;
    string code;
    int year;
    int quantity;
    string drawer;
};

// Deklarasi struct untuk node dalam linked list
struct Node
{
    Book data;
    Node *next;
};

// Deklarasi fungsi untuk menambah buku ke linked list
void addBook(Node **head, Book newBook, string filename)
{
    Node *newNode = new Node;
    newNode->data = newBook;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Deklarasi fungsi untuk menampilkan semua buku dalam linked list
void displayBooks(Node *head)
{
    if (head == NULL)
    {
        cout << "No books found." << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Drawer: " << temp->data.drawer << endl;
        cout << "Code: " << temp->data.code << endl;
        cout << "Title: " << temp->data.title << endl;
        cout << "Author: " << temp->data.author << endl;
        cout << "Year: " << temp->data.year << endl;
        cout << "Quantity: " << temp->data.quantity << endl;
        cout << endl;
        temp = temp->next;
    }
}

// Deklarasi fungsi untuk mencari buku berdasarkan judul/kode
void searchBook(Node *head, string tempo)
{
    if (head == NULL)
    {
        cout << "No books found." << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.title == tempo || temp->data.code == tempo)
        {
            cout << "Drawer: " << temp->data.drawer << endl;
            cout << "Code: " << temp->data.code << endl;
            cout << "Title: " << temp->data.title << endl;
            cout << "Author: " << temp->data.author << endl;
            cout << "Year: " << temp->data.year << endl;
            cout << "Quantity: " << temp->data.quantity << endl;
            cout << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Book not found." << endl;
}

// Deklarasi fungsi untuk menghapus buku berdasarkan judul/kode
void removeBook(Node **head, string tempo)
{
    if (*head == NULL)
    {
        cout << "No books found." << endl;
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data.title == tempo || temp->data.code == tempo)
        {
            if (prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            cout << "title :" << temp->data.title << "code :" << temp->data.code << " has been removed." << endl;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int Drawer(Node **head, string filename, string tempo)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        // handle error: could not open file
        return -1;
    }

    int i = 0;
    string line;
    while (getline(file, line))
    {
        Book newBook;
        int pos = 0; // posisi koma
        string token[5];

        for (int i = 0; i < 5; i++)
        {
            pos = line.find(",");           // mencari posisi koma
            token[i] = line.substr(0, pos); // mengambil string dari posisi 0 sampai posisi koma
            line.erase(0, pos + 1);         // menghapus string dari posisi 0 sampai posisi koma
        }
        newBook.drawer = token[0];
        newBook.code = token[1];
        newBook.title = token[2];
        newBook.author = token[3];
        newBook.year = stoi(token[4]);
        newBook.quantity = stoi(line);

        if (token[0] == tempo)
        {
            i = i + stoi(line);
        }
    }
    return i;
}

// Deklarasi fungsi untuk menghapus buku berdasarkan judul/kode
void changeBook(Node *head, string tempo)
{
    if (head == NULL)
    {
        cout << "No books found." << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.title == tempo || temp->data.code == tempo)
        {
            cout << "Drawer: " << temp->data.drawer << endl;
            cout << "Code: " << temp->data.code << endl;
            cout << "Title: " << temp->data.title << endl;
            cout << "Author: " << temp->data.author << endl;
            cout << "Year: " << temp->data.year << endl;
            cout << "Quantity: " << temp->data.quantity << endl;
            cout << endl;

            cout << "Enter new code: ";
            cin >> temp->data.code;
            cout << "Enter new title: ";
            cin >> temp->data.title;
            cout << "Enter new author: ";
            cin >> temp->data.author;
            cout << "Enter new year: ";
            cin >> temp->data.year;
            cout << "Enter new quantity: ";
            cin >> temp->data.quantity;
            cout << endl;

            cout << "title : " << temp->data.title << "code : " << temp->data.code << " has been change" << endl;
            return;
        }
        temp = temp->next;
    }
}

// Deklarasi fungsi untuk menyimpan data buku ke file txt
void saveData(Node *head, string filename)
{
    ofstream file;
    file.open(filename);

    Node *temp = head;
    while (temp != NULL)
    {
        file << temp->data.drawer << "," << temp->data.code << "," << temp->data.title << "," << temp->data.author << ","
             << temp->data.year << "," << temp->data.quantity << endl;
        temp = temp->next;
    }
    file.close();
}

// Deklarasi fungsi untuk memuat data buku dari file txt
void loadData(Node **head, string filename)
{
    ifstream file;
    file.open(filename);

    if (!file)
    {
        cout << "Error: cannot open file." << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        Book newBook;
        int pos = 0; // posisi koma
        string token[5];

        for (int i = 0; i < 5; i++)
        {
            pos = line.find(",");           // mencari posisi koma
            token[i] = line.substr(0, pos); // mengambil string dari posisi 0 sampai posisi koma
            line.erase(0, pos + 1);         // menghapus string dari posisi 0 sampai posisi koma
        }
        newBook.drawer = token[0];
        newBook.code = token[1];
        newBook.title = token[2];
        newBook.author = token[3];
        newBook.year = stoi(token[4]);
        newBook.quantity = stoi(line);

        // Menambah buku ke linked list
        addBook(head, newBook, filename);
    }
    file.close();
}

int main()
{
    Node *head = NULL;

    // Memuat data buku dari file txt
    loadData(&head, "books.txt");

    int choice;
    do
    {
        // Menampilkan menu
        cout << "Menu:" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Display all books" << endl;
        cout << "3. Search book" << endl;
        cout << "4. Remove book" << endl;
        cout << "5. Change book" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Menambah buku
            Book newBook;
            string tempo;

            cout << "Enter drawer :";
            cin.ignore();
            getline(cin, tempo);
            int a = Drawer(&head, "books.txt", tempo);
            if (a >= 100)
            {
                cout << "Drawer is full" << endl;
            }
            else
            {
                cout << a << endl;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, newBook.title);
                cout << "Enter author: ";
                getline(cin, newBook.author);
                cout << "Enter year: ";
                cin >> newBook.year;
                cout << "Enter quantity: ";
                cin >> newBook.quantity;
                int b = a + newBook.quantity;
                if (b > 100)
                {
                    cout << "Drawer is full" << endl;
                    break;
                }
                cout << "Enter code: ";
                cin >> newBook.code;
                newBook.drawer = tempo;
                addBook(&head, newBook, "books.txt");
                cout << newBook.title << " has been added." << endl;
                saveData(head, "books.txt");
            }
            break;
        }
        case 2:
        {
            // Menampilkan semua buku
            displayBooks(head);
            break;
        }
        case 3:
        {
            cout << "Enter code/title";
            string tempo;
            cin.ignore();
            getline(cin, tempo);
            searchBook(head, tempo);
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "Enter code/title";
            string tempo;
            cin.ignore();
            getline(cin, tempo);
            removeBook(&head, tempo);
            saveData(head, "books.txt");
            break;
        }
        case 5:
        {
            cout << "Enter code/title";
            string tempo;
            cin.ignore();
            getline(cin, tempo);
            changeBook(head, tempo);
            saveData(head, "books.txt");
            break;
        }
        case 6:
        {
            // Keluar dari program
            cout << "Goodbye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 6);
    return 0;
}
