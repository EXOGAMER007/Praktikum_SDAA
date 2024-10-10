#include <iostream>
using namespace std;

struct Item
{
  /* data */
  string nama, tier;
  Item *prev;
  Item *next;
};

// variabel global
Item *head, *tail, *cur, *newNode, *del, *afterNode;
bool mulai = false;
int menu;
bool pengulanganPertama = false;
int maksimal = 5;

void clear()
{ // membersihkan terminal
  system("cls");
  pengulanganPertama = true;
}

// hitung double linked list
int countDoubleLinkedList()
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
      // print
      jumlah++;
      // step
      cur = cur->next;
    }
    return jumlah;
  }
}

void lanjut()
{
  string enter;
  cout << "tekan ENTER untuk lanjut\n";
  cin.clear();
  cin.ignore();
  getline(cin, enter);
  clear();
}
void createDoubleLinkedList(string nama, string tier)
{ // membuat node awal
  head = new Item();
  head->nama = nama;
  head->tier = tier;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

void addLast(string nama, string tier)
{ // menambahkan node baru ke akhir
  newNode = new Item();
  newNode->nama = nama;
  newNode->tier = tier;
  newNode->prev = tail;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void addFirst(string nama, string tier)
{ // menambahkan node baru ke awal
  newNode = new Item();
  newNode->nama = nama;
  newNode->tier = tier;
  newNode->prev = NULL;
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void printDoubleLinkedList()
{ // menampilkan semua node
  cur = head;
  int nomor = 1;
  while (cur != NULL)
  {
    cout << "Nama : " << cur->nama << endl;
    cout << "Tier : " << cur->tier << endl;
    cout << "Nomor : " << nomor << endl;
    cout << "====================" << endl;
    nomor++;
    cur = cur->next;
  }
}

void addMiddle(string nama, string tier, int posisi)
{ // menambahkan node baru ke tengah
  if (posisi == 1)
  {
    addFirst(nama, tier);
    return;
  }
  if (posisi == countDoubleLinkedList())
  {
    addLast(nama, tier);
    return;
  }
  if (posisi < 1 || posisi > countDoubleLinkedList())
  {
    cout << "Posisi diluar jangkauan2" << endl;
    return;
  }
  else
  {
    newNode = new Item();
    newNode->nama = nama;
    newNode->tier = tier;

    // tranversing
    cur = head;
    int nomor = 1;
    while (nomor > posisi - 1)
    {
      cur = cur->next;
      cur++;
    }
    afterNode = cur->next;
    newNode->prev = cur;
    newNode->next = afterNode;
    cur->next = newNode;
    afterNode->prev = newNode;
  }
}

void membuatDataAwal()
{ // membuat data awal
  if (mulai == false)
  {
    createDoubleLinkedList("Heartsteel ,Youmuu's Ghostblade, Trinity Force", "S");
    addLast("Terminus, Bloodthirster, Quicksilver, Bloodthirster", "A");
    addLast("Stasis, Infinity Orb, Morellonomicon", "B");
    addLast("Riftmaker, Glorious, Manamune", "C");
    mulai = true;
    return;
  }
  else
  {
    return;
  }
}

void removeFirst()
{ /// menghapus node awal
  del = head;
  head = head->next;
  head->prev = NULL;
  delete del;
}

void removeLast()
{ // menghapus node akhir
  del = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete del;
}

void removeMiddle(int posisi)
{ // menghapus node di tengah
  if (posisi == 1)
  {
    removeFirst();
    return;
  }
  if (posisi == countDoubleLinkedList())
  {
    removeLast();
    return;
  }
  if (posisi < 1 || posisi > countDoubleLinkedList())
  {
    cout << "Posisi diluar jangkauan2" << endl;
    return;
  }
  else
  {
    int nomor = 1;
    cur = head;
    while (nomor < posisi - 1)
    {
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    afterNode = del->next;
    cur->next = afterNode;
    afterNode->prev = cur;
    delete del;
  }
}

void changeFirst(string nama, string tier)
{ // mengubah node awal
  head->nama = nama;
  head->tier = tier;
}

void changeLast(string nama, string tier)
{ // mengubah node akhir
  tail->nama = nama;
  tail->tier = tier;
}

void changeMiddle(string nama, string tier, int posisi)
{ // mengubah node di tengah
  if (posisi == 1)
  {
    changeFirst(nama, tier);
    return;
  }
  if (posisi == countDoubleLinkedList())
  {
    changeLast(nama, tier);
    return;
  }
  if (posisi < 1 || posisi > countDoubleLinkedList())
  {
    cout << "Posisi diluar jangkauan2" << endl;
    return;
  }
  else
  {
    cur = head;
    int nomor = 1;
    while (nomor < posisi)
    {
      cur = cur->next;
      nomor++;
    }
    cur->nama = nama;
    cur->tier = tier;
  }
}

// fungsi stack
int countItem()
{
  if (head == NULL)
  {
    return 0;
  }
  else
  {
    int banyak = 0;
    cur = head;
    while (cur != NULL)
    {
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

bool isFullItem()
{
  if (countItem() == maksimal)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isEmptyItem()
{
  if (countItem() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void pushItem(string nama, string tier)
{
  if (isFullItem())
  {
    cout << "Stack Full!!" << endl;
  }
  else if (isEmptyItem())
  {
    createDoubleLinkedList(nama, tier);
  }
  else
  {
    newNode = new Item();
    newNode->nama = nama;
    newNode->tier = tier;
    newNode->prev = tail;
    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;
  }
}

void popItem()
{
  del = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete del;
  maksimal--;
}

void peekItem(int posisi)
{
  if (isEmptyItem())
  {
    cout << "Stack kosong!!" << endl;
  }
  else
  {
    int nomor = 1;
    cur = tail;
    while (nomor < posisi)
    {
      cur = cur->prev;
      nomor++;
    }
    cout << "Data Item posisi ke- " << cur->nama << endl;
    cout << "Tier -> " << cur->tier << endl;
  }
}

void changeItem(string Item, string tier, int posisi)
{
  if (isEmptyItem())
  {
    cout << "Stack kosong!!" << endl;
  }
  else
  {
    int nomor = 1;
    cur = tail;
    while (nomor < posisi)
    {
      cur = cur->prev;
      nomor++;
    }
    cur->nama = Item;
    cur->tier = tier;
  }
}

void destroyItem()
{
  cur = head;
  while (cur != NULL)
  {
    del = cur;
    head = head->next;
    delete del;
    cur = cur->next;
  }
}

void displayItem()
{
  if (isEmptyItem())
  {
    cout << "Stack kosong!!" << endl;
  }
  else
  {
    cout << "\n\nData Item : " << endl;
    cur = tail;
    int nomor = 1;
    while (cur != NULL)
    {
      cout << "Nama : " << cur->nama << endl;
      cout << "Tier : " << cur->tier << endl;
      cout << "Nomor : " << nomor << endl;
      cout << "====================" << endl;
      cur = cur->prev;
    }
  }
}

// fungsi queue
void enqueueItem(string nama, string tier)
{
  if (isFullItem())
  {
    cout << "Queue Full!!" << endl;
  }
  else if (isEmptyItem())
  {
    createDoubleLinkedList(nama, tier); // Membuat queue jika kosong
  }
  else
  {
    newNode = new Item();
    newNode->nama = nama;
    newNode->tier = tier;
    newNode->prev = tail;
    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;
  }
}

void dequeueItem()
{
  if (isEmptyItem())
  {
    cout << "Queue kosong!!" << endl;
  }
  else
  {
    del = head;
    head = head->next;
    if (head != NULL)
    {
      head->prev = NULL;
    }
    else
    {
      tail = NULL;
    }
    delete del;
  }
}

void peekQueue()
{
  if (isEmptyItem())
  {
    cout << "Queue kosong!!" << endl;
  }
  else
  {
    cout << "Data paling depan: " << endl;
    cout << "Nama : " << head->nama << endl;
    cout << "Tier : " << head->tier << endl;
  }
}

void displayQueue()
{
  if (isEmptyItem())
  {
    cout << "Queue kosong!!" << endl;
  }
  else
  {
    cout << "\n\nData dalam Queue : " << endl;
    cur = head;
    int nomor = 1;
    while (cur != NULL)
    {
      cout << "Nomor : " << nomor << endl;
      cout << "Nama : " << cur->nama << endl;
      cout << "Tier : " << cur->tier << endl;
      cout << "====================" << endl;
      cur = cur->next;
      nomor++;
    }
  }
}

int main()
{
  clear();
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
  cout << "5. Stack" << endl;
  cout << "6. Queue" << endl;
  cout << "7. Keluar" << endl;
  cout << "----------------------------------------" << endl;
  if (pengulanganPertama == true)
  {
    cin.ignore();
    cin >> menu;
  }
  else
  {
    cin >> menu;
  }
  switch (menu)
  {
  case 1:
    cout << "Lihat" << endl;
    clear();
    printDoubleLinkedList();
    lanjut();
    main();
    break;
  case 2:
    cout << "Hapus" << endl;
    clear();
    printDoubleLinkedList();
    cout << "Masukkan posisi yang ingin dihapus : ";
    cin >> posisi;
    removeMiddle(posisi);
    clear();
    printDoubleLinkedList();
    lanjut();
    main();
    break;
  case 3:
    cout << "Tambah" << endl;
    clear();
    printDoubleLinkedList();
    cout << "Masukkan posisi yang ingin ditambahkan : ";
    cin >> posisi;
    cout << "Masukkan nama item : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan tier item : ";
    getline(cin, tier);
    clear();
    addMiddle(nama, tier, posisi);
    printDoubleLinkedList();
    lanjut();
    main();
    break;
  case 4:
    cout << "Ganti" << endl;
    clear();
    printDoubleLinkedList();
    cout << "Masukkan posisi yang ingin diganti : ";
    cin >> posisi;
    cout << "Masukkan nama item : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan tier item : ";
    getline(cin, tier);
    clear();
    changeMiddle(nama, tier, posisi);
    printDoubleLinkedList();
    lanjut();
    main();
    break;
  case 5:
    cin.ignore();
    clear();
    cout << "Fitur Stack!!" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Change" << endl;
    cout << "5. Destroy" << endl;
    cout << "6. Back" << endl;
    cin >> menu;
    switch (menu)
    {
    case 1:
      cout << "Push" << endl;
      cout << "Masukkan nama item : ";
      cin.ignore();
      getline(cin, nama);
      cout << "Masukkan tier item : ";
      getline(cin, tier);
      clear();
      pushItem(nama, tier);
      displayItem();
      lanjut();
      clear();
      main();
      break;
    case 2:
      cout << "Pop" << endl;
      popItem();
      clear();
      displayItem();
      lanjut();
      clear();
      main();
      break;
    case 3:
      cout << "Peek" << endl;
      cout << "Masukkan posisi yang ingin dilihat : ";
      cin >> posisi;
      clear();
      peekItem(posisi);
      displayItem();
      lanjut();
      clear();
      main();
      break;
    case 4:
      cout << "Change" << endl;
      displayItem();
      cout << "Masukkan posisi yang ingin diganti : ";
      cin >> posisi;
      cout << "Masukkan nama item : ";
      cin.ignore();
      getline(cin, nama);
      cout << "Masukkan tier item : ";
      getline(cin, tier);
      clear();
      changeItem(nama, tier, posisi);
      clear();
      displayItem();
      lanjut();
      clear();
      main();
      break;
    case 5:
      cout << "Destroy" << endl;
      destroyItem();
      clear();
      displayItem();
      lanjut();
      clear();
      main();
      break;
    case 6:
      clear();
      main();
      break;
    default:
      break;
    }
    break;
  case 6:
    cin.ignore();
    clear();
    cout << "Fitur Queue!!" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Display" << endl;
    cout << "5. Back" << endl;
    cin >> menu;
    switch (menu)
    {
    case 1:
      cout << "Enqueue" << endl;
      cout << "Masukkan nama item : ";
      cin.ignore();
      getline(cin, nama);
      cout << "Masukkan tier item : ";
      getline(cin, tier);
      clear();
      enqueueItem(nama, tier);
      displayQueue();
      lanjut();
      clear();
      main();
      break;
    case 2:
      cout << "Dequeue" << endl;
      dequeueItem();
      clear();
      displayQueue();
      lanjut();
      clear();
      main();
      break;
    case 3:
      cout << "Peek" << endl;
      clear();
      peekQueue();
      lanjut();
      clear();
      main();
      break;
    case 4:
      cout << "Display" << endl;
      clear();
      displayQueue();
      lanjut();
      clear();
      main();
      break;
    case 5:
      clear();
      main();
      break;
    default:
      break;
    }
    break;
    break;
  case 7:
    cout << "Keluar" << endl;
    clear();
    cout << "Terima kasih telah menggunakan program ini" << endl;
    break;
  default:
    clear();
    cout << "Inputan salah\n";
    main();
    break;
  }
  return 0;
}