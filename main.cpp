#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Deklarasi struct untuk data buku
struct Book{
    string title, author, code, drawer;
    int year, quantity;
};

// Deklarasi struct untuk node dalam linked list
struct Node{
    Book data;
    Node *next;
};

// Deklarasi fungsi untuk menambah buku ke linked list
void addBook(Node **head, Book newBook, string filename){
    Node *newNode = new Node;
    newNode->data = newBook;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Deklarasi fungsi untuk menampilkan semua buku dalam linked list
void displayBooks(Node *head){
    if (head == NULL){
        cout<<"==================================================================================\n";
        cout<<"|| 			TIDAK ADA BUKU YANG DITEMUKAN 				||\n";
        cout<<"==================================================================================\n";
        return;
    }
    Node *temp = head;
    cout<<"==========================================================================================\n";
    cout<<"||    LACI        KODE	      JUDUL BUKU        PENULIS	       TAHUN	    JUMLAH      ||\n";
    cout<<"==========================================================================================\n";

    while (temp != NULL){
        cout<<"||  "<<setw(7)<<temp->data.drawer<<setw(10)<<temp->data.code<<setw(16)<<temp->data.title;
        cout<<setw(15)<<temp->data.author<<setw(15)<<temp->data.year<<setw(13)<<temp->data.quantity<<"\t||"<<endl;
        temp = temp->next;
    }
    cout<<"==========================================================================================\n";
}

// Deklarasi fungsi untuk mencari buku berdasarkan judul/kode
void searchBook(Node *head, string tempo){
    if (head == NULL){
        cout<<"==================================================================================\n";
        cout<<"|| 			TIDAK ADA BUKU YANG DITEMUKAN 				||\n";
        cout<<"==================================================================================\n";
        return;
    }
    Node *temp = head;
    cout<<"==========================================================================================\n";
    cout<<"||    LACI        KODE	      JUDUL BUKU        PENULIS	       TAHUN	    JUMLAH      ||\n";
    cout<<"==========================================================================================\n";
    while (temp != NULL){
        if (temp->data.title == tempo || temp->data.code == tempo){
            cout<<"||  "<<setw(7)<<temp->data.drawer<<setw(10)<<temp->data.code<<setw(16)<<temp->data.title;
            cout<<setw(15)<<temp->data.author<<setw(15)<<temp->data.year<<setw(13)<<temp->data.quantity<<"\t||"<<endl;
            cout<<"==========================================================================================\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Buku tidak ditemukan" << endl;
}

// Deklarasi fungsi untuk menghapus buku berdasarkan judul/kode
void removeBook(Node **head, string tempo){
    if (*head == NULL){
        cout<<"==================================================================================\n";
        cout<<"|| 			TIDAK ADA BUKU YANG DITEMUKAN 				||\n";
        cout<<"==================================================================================\n";
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL){
        if (temp->data.title == tempo || temp->data.code == tempo){
            if (prev == NULL){
                *head = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            cout << "Judul :" << temp->data.title << "  Kode :" << temp->data.code << " telah dihapus" << endl;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

Book Return(string filename, string tempo) {
    ifstream file(filename);
    Book newBook;
    string line;
    int totalQuantity = 0;
    while (getline(file, line)) {
        int pos = 0; // posisi koma
        string token[5];

        for (int i = 0; i < 5; i++) {
            pos = line.find(",");
            token[i] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        newBook.drawer = token[0];
        newBook.code = token[1];
        newBook.title = token[2];
        newBook.author = token[3];
        newBook.year = stoi(token[4]);
        newBook.quantity = stoi(line);
        if (newBook.drawer == tempo) {
            // Jika laci sama dengan tempo, tambahkan jumlah buku yang baru saja dibaca
            totalQuantity += newBook.quantity;
        }
    }
    // Atur jumlah buku yang baru saja dibaca pada objek buku yang akan dikembalikan
    newBook.quantity = totalQuantity;
    return newBook;
}

// Deklarasi fungsi untuk menghapus buku berdasarkan judul/kode
void changeBook(Node *head, string tempo){
    if (head == NULL){
        cout<<"==================================================================================\n";
        cout<<"|| 			TIDAK ADA BUKU YANG DITEMUKAN!!! 				||\n";
        cout<<"==================================================================================\n";
        return;
    }
    Node *temp = head;
    cout<<"==========================================================================================\n";
    cout<<"||    LACI        KODE	      JUDUL BUKU        PENULIS	       TAHUN	    JUMLAH      ||\n";
    cout<<"==========================================================================================\n";
    while (temp != NULL){
        if (temp->data.title == tempo || temp->data.code == tempo){
            cout<<"||  "<<setw(7)<<temp->data.drawer<<setw(10)<<temp->data.code<<setw(16)<<temp->data.title;
            cout<<setw(15)<<temp->data.author<<setw(15)<<temp->data.year<<setw(13)<<temp->data.quantity<<"\t||"<<endl;
            cout<<"==========================================================================================\n";
            cout << endl;

            cout << "Masukan kode baru : ";     cin >> temp->data.code;
            cout << "Masukan judul baru : ";    cin >> temp->data.title;
            cout << "Masukan penulis baru : ";   cin >> temp->data.author;
            cout << "Masukan tanggal baru: ";     cin >> temp->data.year;
            cout << "Masukan jumlah baru : ";   cin >> temp->data.quantity;
            cout<<"==========================================================================================\n";
            cout<<"||  "<<setw(7)<<temp->data.drawer<<setw(10)<<temp->data.code<<setw(16)<<temp->data.title;
            cout<<setw(15)<<temp->data.author<<setw(15)<<temp->data.year<<setw(13)<<temp->data.quantity<<"\t||"<<endl;
            cout<<"==========================================================================================\n";
            return;
        }
        temp = temp->next;
    }
}

// Deklarasi fungsi untuk menyimpan data buku ke file txt
void saveData(Node *head, string filename){
    ofstream file;
    file.open(filename);

    Node *temp = head;
    while (temp != NULL){
        file << temp->data.drawer << "," << temp->data.code << "," << temp->data.title << "," << temp->data.author << ","
             << temp->data.year << "," << temp->data.quantity << endl;
        temp = temp->next;
    }
    file.close();
}

// Deklarasi fungsi untuk memuat data buku dari file txt
void loadData(Node **head, string filename){
    ifstream file;
    file.open(filename);

    if (!file){
        cout << "Eror : Tidak bisa membuka file" << endl;
        return;
    }
    string line;
    while (getline(file, line)){
        Book newBook;
        int pos = 0; // posisi koma
        string token[5];

        for (int i = 0; i < 5; i++){
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
        addBook(head, newBook, filename); // Menambah buku ke linked list
    }
    file.close();
}

int main(){
    Node *head = NULL;
    loadData(&head, "books.txt"); // Memuat data buku dari file txt
    int choice;
    do{ // Menampilkan menu
        cout<<"==========================================================================================\n";
        cout << "||                                     MENU PERPUSTAKAAN                                ||" << endl;
        cout<<"==========================================================================================\n";
        cout << "||                 1. Menambahkan buku                                                  ||" << endl;
        cout << "||                 2. Tampilkan semua buku                                              ||" << endl;
        cout << "||                 3. Mencari buku                                                      ||" << endl;
        cout << "||                 4. Hapus buku                                                        ||" << endl;
        cout << "||                 5. Mengganti buku                                                    ||" << endl;
        cout << "||                 6. Keluar                                                            ||" << endl;
        cout<<"==========================================================================================\n";
        cout << "Masukan pilihan anda: "; cin >> choice;
        switch (choice){
        case 1:{
            Book newBook;
            string tempo;

            cout << "Masukan nama laci: ";
            cin.ignore();
            getline(cin, tempo);
            Book result = Return("books.txt", tempo);
            cout << result.quantity << endl;
            if (result.quantity >= 100){
                cout << "Laci telah penuh" << endl;
            }
            else{
                cout << "Masukan judul : ";
                getline(cin, newBook.title);
                cout << "Masukan nama penulis : ";
                getline(cin, newBook.author);
                cout << "Masukan tanggal dibuat : ";
                cin >> newBook.year;
                cout << "Masukan jumlah buku : ";
                cin >> newBook.quantity;
                int b = result.quantity + newBook.quantity;
                if (b > 100){
                    cout << "Laci telah penuh (tidak bisa menambahkan buku lagi)" << endl;
                    break;
                }
                cout << "Masukan kode buku :";
                cin >> newBook.code;
                if(newBook.code == result.code){
                    cout << "Kode buku telah digunakan" << endl;
                    break;
                }
                newBook.drawer = tempo;
                addBook(&head, newBook, "books.txt");
                cout << newBook.title << " telah ditambahkan" << endl;
                saveData(head, "books.txt");
            }
            break;
        }
        case 2:{
            displayBooks(head); // Menampilkan semua buku
            break;
        }
        case 3:{
            cout << "Masukan kode buku / judul buku : ";
            string tempo;
            cin.ignore();
            getline(cin, tempo);
            searchBook(head, tempo);
            cout << endl;
            break;
        }
        case 4:{
            cout << "Masukan kode buku / judul buku : ";
            string tempo;
            cin.ignore();
            getline(cin, tempo);
            removeBook(&head, tempo);
            saveData(head, "books.txt");
            break;
        }
        case 5:{
            cout << "Masukan kode buku / judul buku : ";
            string tempo;
            cin.ignore();
            getline(cin, tempo);
            changeBook(head, tempo);
            saveData(head, "books.txt");
            break;
        }
        case 6:{
            cout << "Selamat tinggal" << endl; // Keluar dari program
            break;
        }
        default:{
            cout << "Pilihan anda salah" << endl;
            break;
            }
        }
    } while (choice != 6);
    return 0;
}
