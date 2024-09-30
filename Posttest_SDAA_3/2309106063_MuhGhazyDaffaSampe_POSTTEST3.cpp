#include <iostream>
using namespace std;

struct Item{
    /* data */
    string nama, tier;

    Item *next;
};

//variabel global
Item *head, *tail, *cur, *baru, *before, *del;
bool mulai = false;
int menu;
bool pengulanganPertama = false;

int countSingleLinkedList(){ //menghitung jumlah node
    cur = head;
    int jumlah = 0;
    while (cur != NULL){
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}
void clear(){//membersihkan terminal
    system("cls");
    pengulanganPertama = true;
}

void lanjut() {
    string enter;    
    cout << "tekan ENTER untuk lanjut\n";
    cin.clear();
    cin.ignore();
    getline(cin, enter);
    clear();
 }
void createSingleLinkedList(string nama, string tier){ //membuat node awal
    head = new Item();
    head->nama = nama;
    head->tier = tier;
    head->next = NULL;
    tail = head;
}

void addLast(string nama, string tier){ //menambahkan node baru ke akhir
    baru = new Item();
    baru->nama = nama;
    baru->tier = tier;
    baru->next = NULL;
    tail->next = baru;
    tail = baru;
}

void addFirst(string nama, string tier){ //menambahkan node baru ke awal
    baru = new Item();
    baru->nama = nama;
    baru->tier = tier;
    baru->next = head;
    head = baru;
}

void printSingleLinkedList(){//menampilkan semua node
    cur = head;
    int nomor = 1;
    while (cur != NULL){
        cout << "Nama : " << cur->nama << endl;
        cout << "Tier : " << cur->tier << endl;
        cout << "Nomor : " << nomor << endl;
        cout << "====================" << endl;
        nomor++;
        cur = cur->next;
    }
}

void addMiddle(string nama, string tier, int posisi){ //menambahkan node baru ke tengah
    if (posisi == 1){
        addFirst(nama, tier);
        return;
    }
    if (posisi == countSingleLinkedList()){
        addLast(nama, tier);
        return;
    }
    if (posisi< 1 || posisi > countSingleLinkedList()){
        cout << "Posisi diluar jangkauan2" << endl;
        return;
    } 
    else{
        baru = new Item();
        baru->nama = nama;
        baru->tier = tier;

        cur = head;
        int nomor = 1;
        while (nomor < posisi - 1){
            cur = cur->next;
            nomor++;
        }

        baru->next = cur->next;
        cur->next = baru;
    }
}

void membuatDataAwal(){ //membuat data awal
    if (mulai == false){
        createSingleLinkedList("Heartsteel ,Youmuu's Ghostblade, Trinity Force", "S");
        addLast("Terminus, Bloodthirster, Quicksilver, Bloodthirster", "A");
        addLast("Stasis, Infinity Orb, Morellonomicon", "B");
        addLast("Riftmaker, Glorious, Manamune", "C");
        mulai = true;
        return;
    } else
    {
        return;
    }  
}

void removeFirst(){ ///menghapus node awal
    del = head;
    head = head->next;
    delete del;
}

void removeLast(){ //menghapus node akhir
    del = tail;
    cur = head;
    while (cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void removeMiddle(int posisi){ //menghapus node di tengah
    if (posisi == 1){
        removeFirst();
        return;
    }
    if (posisi == countSingleLinkedList()){
        removeLast();
        return;
    }
    if (posisi< 1 || posisi > countSingleLinkedList()){
        cout << "Posisi diluar jangkauan2" << endl;
        return;
    } 
    else{
        int nomor = 0;
        cur = head;
        while (nomor < posisi - 1){
        if (nomor <= posisi - 1){
            before = cur;
        }
        if (nomor  == posisi){
            del = cur;
        }
        cur = cur->next;
        nomor++;
        }
        before->next = cur->next;
        delete del;
    }
}

void changeFirst(string nama, string tier){//mengubah node awal
    head->nama = nama;
    head->tier = tier;
}

void changeLast(string nama, string tier){//mengubah node akhir
    tail->nama = nama;
    tail->tier = tier;
}

void changeMiddle(string nama, string tier, int posisi){ //mengubah node di tengah
    if (posisi == 1){
        changeFirst(nama, tier);
        return;
    }
    if (posisi == countSingleLinkedList()){
        changeLast(nama, tier);
        return;
    }
    if (posisi< 1 || posisi > countSingleLinkedList()){
        cout << "Posisi diluar jangkauan2" << endl;
        return;
    } 
    else{
        cur = head;
        int nomor = 1;
        while (nomor < posisi){
            cur = cur->next;
            nomor++;
        }
        cur->nama = nama;
        cur->tier = tier;
    }
    
}


int main(){
    membuatDataAwal();
    string nama;
    string tier;
    int posisi;
    cout << "----------------------------------------" << endl;
    cout << "|             TIER LIST ITEM           |" << endl;
    cout << "|              LOL WILD RIFT           |" << endl;
    cout << "----------------------------------------" << endl;
    cout << "MENU :" << endl;
    cout << "1. Lihat" << endl;
    cout << "2. Hapus" << endl;
    cout << "3. Tambah" << endl;
    cout << "4. Ganti" << endl;
    cout << "----------------------------------------" << endl;
    if (pengulanganPertama == true){
        cin.ignore();
        cin >> menu;
    }else
    {
        cin >> menu;
    }
    switch (menu) {
    case 1:
        cout << "Lihat" << endl;
        clear();
        printSingleLinkedList();
        lanjut();
        main();
        break;
    case 2:
        cout << "Hapus" << endl;
        clear();
        printSingleLinkedList();
        cout << "Masukkan posisi yang ingin dihapus : ";
        cin >> posisi;
        removeMiddle(posisi);
        clear();
        printSingleLinkedList();
        lanjut();
        main();
        break;
    case 3:
        cout << "Tambah" << endl;
        clear();
        printSingleLinkedList();
        cout << "Masukkan posisi yang ingin ditambahkan : ";
        cin >> posisi;
        cout << "Masukkan nama item : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan tier item : ";
        getline(cin, tier);
        clear();
        addMiddle(nama, tier, posisi);
        printSingleLinkedList();
        lanjut();
        main();
        break;
    case 4:
        cout << "Ganti" << endl;
        clear();
        printSingleLinkedList();
        cout << "Masukkan posisi yang ingin diganti : ";
        cin >> posisi;
        cout << "Masukkan nama item : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan tier item : ";
        getline(cin, tier);
        clear();
        changeMiddle(nama, tier, posisi);
        printSingleLinkedList();
        lanjut();
        main();
        break;
    default:
        clear();
        cout << "Inputan salah\n";
        main();
        break;
    }
    return 0;
}

