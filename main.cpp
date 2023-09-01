#include <iostream> // library untuk input output
#include <fstream> // library untuk membaca file
#include <string>   // library untuk string
#include <iomanip>  // library untuk manipulasi output (setw)

using namespace std;    // menggunakan namespace std

// Deklarasi struct untuk data buku
struct Book{    // struct untuk data buku
    string title, author, code, bookcase; // deklarasi variabel string
    int year, quantity; // deklarasi variabel integer
};

// Deklarasi struct untuk node dalam linked list
struct Node{    // struct untuk node dalam linked list
    Book data;  // deklarasi variabel data bertipe Book
    Node *next; 
};

Node *head = NULL;  // deklarasi variabel head bertipe Node
// Deklarasi fungsi untuk menambah buku ke linked list
void addBook(Book newBook, string filename){    // fungsi untuk menambah buku ke linked list
    Node *newNode = new Node;   // deklarasi variabel newNode bertipe Node
    newNode->data = newBook;    // mengisi data newNode dengan data newBook
    newNode->next = NULL;    // mengisi next newNode dengan NULL
    Node *temp = head;  // deklarasi variabel temp bertipe Node

    if (head == NULL){  // jika head bernilai NULL
        head = newNode; // head diisi dengan newNode
        return; // keluar dari fungsi
    }
    
    while (temp->next != NULL){     // selama next temp tidak NULL
        temp = temp->next;  // temp diisi dengan next temp
    }
    temp->next = newNode;   // next temp diisi dengan newNode
    //test
}

// Deklarasi fungsi untuk menampilkan semua buku dalam linked list
void displayBooks(){    // fungsi untuk menampilkan semua buku dalam linked list
    system("cls");
    Node *temp = head;  // deklarasi variabel temp bertipe Node
    if (head == NULL){  // jika head bernilai NULL
        cout<<"==============================================================================================================================================\n";
        cout<<"|| 		                     	                        TIDAK ADA BUKU YANG DITEMUKAN!!! 		        		                            ||\n";
        cout<<"==============================================================================================================================================\n";
        return; // keluar dari fungsi
    }
    cout<<"==============================================================================================================================================\n";
    cout<<"||            LEMARI             KODE	             JUDUL BUKU                PENULIS	           TAHUN	              JUMLAH        ||\n";
    cout<<"==============================================================================================================================================\n";
    while (temp != NULL){   // selama temp tidak NULL
        cout<<"||  "<<setw(16)<<temp->data.bookcase<<setw(17)<<temp->data.code<<setw(27)<<temp->data.title;    // menampilkan data bookcase, code, dan title
        cout<<setw(25)<<temp->data.author<<setw(17)<<temp->data.year<<setw(25)<<temp->data.quantity<<"\t||"<<endl;  // menampilkan data author, year, dan quantity
        temp = temp->next;  // temp diisi dengan next temp
    }
    cout<<"==============================================================================================================================================\n";
    cout << endl;   // menampilkan baris kosong
}

// Deklarasi fungsi untuk mencari buku berdasarkan judul/kode
void searchBook(string tempo){  // fungsi untuk mencari buku berdasarkan judul/kode
    system("cls");
    Node *temp = head;  // deklarasi variabel temp bertipe Node
    if (head == NULL){  // jika head bernilai NULL
        cout<<"==============================================================================================================================================\n";
        cout<<"|| 		                     	                        TIDAK ADA BUKU YANG DITEMUKAN!!! 		        		                            ||\n";
        cout<<"==============================================================================================================================================\n";
        return; // keluar dari fungsi
    }
    cout<<"==============================================================================================================================================\n";
    cout<<"||            LEMARI             KODE	             JUDUL BUKU                PENULIS	           TAHUN	              JUMLAH        ||\n";
    cout<<"==============================================================================================================================================\n";
    while (temp != NULL){   // selama temp tidak NULL
        if (temp->data.title == tempo || temp->data.code == tempo){ // jika title atau code temp sama dengan tempo
            cout<<"||  "<<setw(16)<<temp->data.bookcase<<setw(17)<<temp->data.code<<setw(27)<<temp->data.title;    // menampilkan data bookcase, code, dan title
            cout<<setw(25)<<temp->data.author<<setw(17)<<temp->data.year<<setw(25)<<temp->data.quantity<<"\t||"<<endl;  // menampilkan data author, year, dan quantity
            cout<<"==============================================================================================================================================\n";
            cout << "Ketik apapun untuk kembali ke menu utama :"; cin.ignore(); // menunggu inputan user
            return; // keluar dari fungsi
        }
        temp = temp->next;  // temp diisi dengan next temp
        //tst code ql 3
    }
}

// Deklarasi fungsi untuk menghapus buku berdasarkan judul/kode
void removeBook(string tempo){  // fungsi untuk menghapus buku berdasarkan judul/kode
    system("cls");
    Node *temp = head;  // deklarasi variabel temp bertipe Node
    int a;  // deklarasi variabel a bertipe integer
    Node *del = NULL;   // deklarasi variabel del bertipe Node
    if (head == NULL){  // jika head bernilai NULL
        cout<<"==============================================================================================================================================\n";
        cout<<"|| 		                     	                        TIDAK ADA BUKU YANG DITEMUKAN!!! 		        		                            ||\n";
        cout<<"==============================================================================================================================================\n";
        return; // keluar dari fungsi
    }
    while (temp != NULL){   // selama temp tidak NULL
        if (temp->data.title == tempo || temp->data.code == tempo){ // jika title atau code temp sama dengan tempo
            cout<<"==============================================================================================================================================\n";
            cout << "||   \t\tJUDUL : " << temp->data.title << "   \t\tJUMLAH : " << temp->data.quantity << "       \t\t||" << endl;
            cout<<"==============================================================================================================================================\n";
            cout << "Masukan jumlah yang ingin dihapus :"; cin >> a;    // meminta inputan user
            if(a < temp->data.quantity){    // jika a kurang dari quantity temp
                temp->data.quantity = temp->data.quantity - a;  // mengurangi quantity temp dengan a
                cout<<"==============================================================================================================================================\n";
                cout << "||   \t\tJUDUL : " << temp->data.title << "   \t\tJUMLAH : " << temp->data.quantity << "       \t\t||" << endl;
                cout<<"==============================================================================================================================================\n";
            }else{  // jika a lebih dari quantity temp
                if (del == NULL){   // jika del bernilai NULL
                head = temp->next;  // head diisi dengan next temp
                }else{
                del->next = temp->next; // next del diisi dengan next temp
                }
                cout<<"==============================================================================================================================================\n";
                cout << "||   \t\tJUDUL : " << temp->data.title << "   \t\tKODE : " << temp->data.code << "  \t\tTELAH DIHAPUS    \t\t||" << endl;
                cout<<"==============================================================================================================================================\n";
                delete temp;    // menghapus temp
                return; // keluar dari fungsi
            }
        }
        //ini deklarasi buat nanti pas putaran selanjutnya
        del = temp;    // del diisi dengan temp
        temp = temp->next;  // temp diisi dengan next temp
    }
    cout << endl;   // menampilkan baris kosong
}

Book Return(string tempo){
    Node *temp = head;  // deklarasi variabel temp bertipe Node
    Book newBook;   // deklarasi variabel newBook bertipe Book
    int totalQuantity = 0;  // deklarasi variabel totalQuantity bertipe integer
    while(temp != NULL){
        newBook.bookcase = temp->data.bookcase;  // mengisi bookcase newBook dengan temp->data.bookcase
        newBook.code = temp->data.code;    // mengisi code newBook dengan temp->data.code
        newBook.title = temp->data.title;   // mengisi title newBook dengan temp->data.title
        newBook.author = temp->data.author;  // mengisi author newBook dengan temp->data.author
        newBook.year = temp->data.year;  // mengisi year newBook dengan temp->data.year
        newBook.quantity = temp->data.quantity;  // mengisi quantity newBook dengan temp->data.quantity
        if (newBook.bookcase == tempo || newBook.code == tempo || newBook.title == tempo) {
            // Jika lemari sama dengan tempo, tambahkan jumlah buku yang baru saja dibaca
            totalQuantity += newBook.quantity;  
        }
        temp = temp->next;  // temp diisi dengan next temp
    }
    newBook.quantity = totalQuantity;   // mengisi quantity newBook dengan totalQuantity
    return newBook; // Mengembalikan objek buku
}

// Deklarasi fungsi untuk menghapus buku berdasarkan judul/kode
void changeBook(string tempo){  // fungsi untuk menghapus buku berdasarkan judul/kode
    Node *temp = head;  // deklarasi variabel temp bertipe Node
    string tempTitle, tempAuthor;   // deklarasi variabel tempTitle dan tempAuthor bertipe string
    if (head == NULL){  // jika head bernilai NULL
        cout<<"==============================================================================================================================================\n";
        cout<<"|| 		                     	                        TIDAK ADA BUKU YANG DITEMUKAN!!! 		        		                            ||\n";
        cout<<"==============================================================================================================================================\n";
        return; // keluar dari fungsi
    }
    cout<<"==============================================================================================================================================\n";
    cout<<"||            LEMARI             KODE	             JUDUL BUKU                PENULIS	           TAHUN	              JUMLAH        ||\n";
    cout<<"==============================================================================================================================================\n";
    while (head != NULL){   // selama temp tidak NULL
        if (temp->data.title == tempo || temp->data.code == tempo){ // jika title atau code temp sama dengan tempo
            cout<<"||  "<<setw(16)<<temp->data.bookcase<<setw(17)<<temp->data.code<<setw(27)<<temp->data.title;    // menampilkan data bookcase, code, dan title
            cout<<setw(25)<<temp->data.author<<setw(17)<<temp->data.year<<setw(25)<<temp->data.quantity<<"\t||"<<endl;  // menampilkan data author, year, dan quantity
            cout<<"==============================================================================================================================================\n";
            Book result = Return(temp->data.bookcase); // memanggil fungsi return untuk mendapatkan jumlah buku di lemari yang sama
            cout << "Lemari ini sudah berisi : " << result.quantity << " buku " << endl;  // menampilkan jumlah buku
            temp->data.code;    // mengisi code temp
            cout << "Masukan judul baru : ";    getline(cin, tempTitle); temp->data.title=tempTitle;    // meminta inputan user
            cout << "Masukan penulis baru : ";   getline(cin, tempAuthor); temp->data.author=tempAuthor;    // meminta inputan user
            cout << "Masukan tanggal baru: ";     cin >> temp->data.year;   // meminta inputan user
            //cout << "Lemari ini sudah berisi : " << result.quantity << " buku " << endl;  // menampilkan jumlah buku
            cout << "Masukan jumlah baru : ";       // meminta inputan user
            int newQuantity;    // deklarasi variabel newQuantity bertipe integer
            int totalQuantity = 0;  // deklarasi variabel totalQuantity bertipe integer
            cin >> newQuantity;   // meminta inputan user
            totalQuantity = result.quantity - temp->data.quantity + newQuantity; // menghitung jumlah buku baru di dalam lemari
            if (totalQuantity > 100) { // jika jumlah buku melebihi batas, tampilkan pesan error
                cout << "Jumlah buku di dalam satu lemari tidak boleh melebihi 100." << endl;
                return; // keluar dari fungsi
            }
            temp->data.quantity = newQuantity; // mengisi quantity temp dengan newQuantity
            cout<<"==============================================================================================================================================\n";
            cout<<"||  "<<setw(16)<<temp->data.bookcase<<setw(17)<<temp->data.code<<setw(27)<<temp->data.title;    // menampilkan data bookcase, code, dan title
            cout<<setw(25)<<temp->data.author<<setw(17)<<temp->data.year<<setw(25)<<temp->data.quantity<<"\t||"<<endl;  // menampilkan data author, year, dan quantity
            cout<<"==============================================================================================================================================\n";
            return; // keluar dari fungsi
        }
        temp = temp->next;  // temp diisi dengan next temp
    }
    cout << "Ketik apapun untuk kembali ke menu utama :"; cin.ignore(); // menunggu inputan user
}

// Deklarasi fungsi untuk menyimpan data buku ke file txt
void saveData(string filename){ // fungsi untuk menyimpan data buku ke file txt
    Node *temp = head;  // deklarasi variabel temp bertipe Node
    ofstream file;  // deklarasi variabel file bertipe ofstream
    file.open(filename);    // membuka file

    while (temp != NULL){   // selama temp tidak NULL
        file << temp->data.bookcase << "," << temp->data.code << "," << temp->data.title << "," << temp->data.author << ","   // menulis data bookcase, code, title, author, year, dan quantity ke file
             << temp->data.year << "," << temp->data.quantity << endl;  // menulis data bookcase, code, title, author, year, dan quantity ke file
        temp = temp->next;  // temp diisi dengan next temp
    }
    file.close();   // menutup file
}

// Deklarasi fungsi untuk memuat data buku dari file txt
void loadData(string filename){ // fungsi untuk memuat data buku dari file txt
    ifstream file;  // deklarasi variabel file bertipe ifstream
    file.open(filename);    // membuka file

    if (!file){ // jika file tidak ada
        cout << "Eror : Tidak bisa membuka file" << endl;   // menampilkan pesan error
        return; // keluar dari fungsi
    }
    string line;    // deklarasi variabel line bertipe string
    while (getline(file, line)){    // selama getline file tidak NULL
        Book newBook;   // deklarasi variabel newBook bertipe Book
        int pos = 0; // posisi koma
        string token[5];    // deklarasi variabel token bertipe string

        for (int i = 0; i < 5; i++){
            pos = line.find(",");           // mencari posisi koma
            token[i] = line.substr(0, pos); // mengambil string dari posisi 0 sampai posisi koma
            line.erase(0, pos + 1);         // menghapus string dari posisi 0 sampai posisi koma
        }
        newBook.bookcase = token[0];  // mengisi bookcase newBook dengan token[0]
        newBook.code = token[1];    // mengisi code newBook dengan token[1]
        newBook.title = token[2];   // mengisi title newBook dengan token[2]
        newBook.author = token[3];  // mengisi author newBook dengan token[3]
        newBook.year = stoi(token[4]);  // mengisi year newBook dengan token[4]
        newBook.quantity = stoi(line);  // mengisi quantity newBook dengan line
        addBook(newBook, filename); // Menambah buku ke linked list
    }
    file.close();   // menutup file
}

int main(){ // fungsi utama
    loadData("books.txt"); // Memuat data buku dari file txt
    int choice;
    do{ // Menampilkan menu
        cout<<"==============================================================================================================================================\n";
        cout << "||                                                         MENU PERPUSTAKAAN                                                                ||" << endl;
        cout<<"==============================================================================================================================================\n";
        cout << "||                                              1. Menambahkan buku                                                                         ||" << endl;
        cout << "||                                              2. Tampilkan semua buku                                                                     ||" << endl;
        cout << "||                                              3. Mencari buku                                                                             ||" << endl;
        cout << "||                                              4. Hapus buku                                                                               ||" << endl;
        cout << "||                                              5. Mengganti buku                                                                           ||" << endl;
        cout << "||                                              6. Keluar                                                                                   ||" << endl;
        cout<<"==============================================================================================================================================\n";
        cout << "Masukan pilihan anda: "; cin >> choice;    // meminta inputan user
        system("cls");
        switch (choice){    // memilih menu
        case 1:{    // Menambahkan buku
            Book newBook;   // deklarasi variabel newBook bertipe Book
            string tempo;   // deklarasi variabel tempo bertipe string

            cout << "Masukan nama lemari: ";  // meminta inputan user
            cin.ignore();
            getline(cin, tempo);    // meminta inputan user
            // Book result = Return("books.txt", tempo);   // Mengembalikan buku
            Book result = Return(tempo);
            cout << "Lemari ini sudah berisi : " << result.quantity << " buku " << endl;  // menampilkan jumlah buku
            if (result.quantity >= 100){    // jika result.quantity lebih dari sama dengan 100
                cout << "Lemari telah penuh" << endl;  // menampilkan pesan
            }
            else{   // jika result.quantity kurang dari 100
                cout << "Masukan judul : ";
                getline(cin, newBook.title);
                cout << "Masukan nama penulis : ";
                getline(cin, newBook.author);
                cout << "Masukan tahun terbit : ";
                cin >> newBook.year;
                cout << "Masukan jumlah buku : ";
                cin >> newBook.quantity;
                int b = result.quantity + newBook.quantity; // deklarasi variabel b bertipe integer
                if (b > 100){   // jika b lebih dari 100
                    cout << "Lemari telah penuh (tidak bisa menambahkan buku lagi)" << endl;
                    break;  // keluar dari perulangan
                }
                cout << "Masukan kode buku :";
                cin >> newBook.code;
                if(newBook.code == result.code){    // jika newBook.code sama dengan result.code
                    cout << "Kode buku telah digunakan" << endl;
                    break;  // keluar dari perulangan
                }
                newBook.bookcase = tempo; // mengisi bookcase newBook dengan tempo
                addBook(newBook, "books.txt");  // Menambah buku ke linked list
                cout << "buku : " << newBook.title << " telah ditambahkan" << endl; // menampilkan pesan
                saveData("books.txt");  // Menyimpan data buku ke file txt
            }
            break;  // keluar dari perulangan
        }
        case 2:{
            displayBooks(); // Menampilkan semua buku
            break;
        }
        case 3:{    // Mencari buku
            cout << "Masukan kode buku / judul buku : ";    // meminta inputan user
            string tempo;   // deklarasi variabel tempo bertipe string
            cin.ignore();   // mengabaikan inputan user
            getline(cin, tempo);    // meminta inputan user
            searchBook(tempo);      // Mencari buku
            cout << endl;   // menampilkan baris kosong
            break;  // keluar dari perulangan
        }
        case 4:{
            cout << "Masukan kode buku / judul buku : ";    // meminta inputan user
            string tempo;   // deklarasi variabel tempo bertipe string
            cin.ignore();   // mengabaikan inputan user
            getline(cin, tempo);    // meminta inputan user
            removeBook(tempo);  // Menghapus buku
            saveData("books.txt");  // Menyimpan data buku ke file txt
            break;  // keluar dari perulangan
        }
        case 5:{
            cout << "Masukan kode buku / judul buku : ";    // meminta inputan user
            string tempo;   // deklarasi variabel tempo bertipe string
            cin.ignore();   // mengabaikan inputan user
            getline(cin, tempo);    // meminta inputan user
            changeBook(tempo);  // Mengganti buku
            saveData("books.txt");  // Menyimpan data buku ke file txt
            break;  // keluar dari perulangan
        }
        case 6:{    // Keluar
            cout << "Selamat tinggal" << endl; // Keluar dari program
            break;  // keluar dari perulangan
        }
        default:{   // Jika pilihan salah
            cout << "Pilihan anda salah" << endl;   // menampilkan pesan
            break;  // keluar dari perulangan
            }
        }
    } while (choice != 6);  // selama choice tidak sama dengan 6
    return 0;   // keluar dari program
}
