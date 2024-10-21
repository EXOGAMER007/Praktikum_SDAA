#include <iostream>
#include <cmath>  // Untuk fungsi sqrt
#include <vector> // Untuk vektor
using namespace std;

struct Item
{
  /* data */
  string nama, tier;
  int id;
  Item *prev;
  Item *next;
};

// variabel global
Item *head, *tail, *cur, *newNode, *del, *afterNode;
bool mulai = false;
int menu;
bool pengulanganPertama = false;
int maksimal = 5;
int setID = 7999; // variabel untuk mengatur id dan sebagai nilai awal variabel

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
  setID += 1;
  head->id = setID;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

void addLast(string nama, string tier)
{ // menambahkan node baru ke akhir
  newNode = new Item();
  newNode->nama = nama;
  newNode->tier = tier;
  setID += 1;
  newNode->id = setID;
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
  setID += 1;
  newNode->id = setID;
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
    cout << "Nama  : " << cur->nama << endl;
    cout << "Tier  : " << cur->tier << endl;
    cout << "ID    : " << cur->id << endl;
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
    setID += 1;
    newNode->id = setID;

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
    createDoubleLinkedList("Heartsteel", "S");
    addLast("Terminus", "A");
    addLast("Stasis", "B");
    addLast("Riftmaker", "C");
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
    setID += 1;
    newNode->id = setID;
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
    cout << "ID -> " << cur->id << endl;
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
      cout << "Nama   : " << cur->nama << endl;
      cout << "Tier   : " << cur->tier << endl;
      cout << "ID     : " << cur->id << endl;
      cout << "Nomor  : " << nomor << endl;
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
    setID += 1;
    newNode->id = setID;
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
    cout << "ID   : " << head->id << endl;
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
      cout << "ID   : " << cur->id << endl;
      cout << "====================" << endl;
      cur = cur->next;
      nomor++;
    }
  }
}

// fungsi sort

// merge sort ASC
//  Fungsi untuk membagi linked list menjadi dua
Item *split(Item *head)
{
  Item *fast = head;
  Item *slow = head;

  while (fast->next && fast->next->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }

  Item *temp = slow->next;
  slow->next = NULL;
  return temp;
}

// Fungsi untuk menggabungkan dua linked list yang sudah diurutkan
Item *merge(Item *first, Item *second)
{
  // Jika salah satu sublist kosong
  if (!first)
    return second;
  if (!second)
    return first;

  // Urutkan secara ascending berdasarkan nama item
  if (first->nama < second->nama)
  {
    first->next = merge(first->next, second);
    first->next->prev = first;
    first->prev = NULL;
    return first;
  }
  else
  {
    second->next = merge(first, second->next);
    second->next->prev = second;
    second->prev = NULL;
    return second;
  }
}

// Fungsi utama mergeSort untuk mengurutkan linked list
Item *mergeSort(Item *node)
{
  if (!node || !node->next)
  {
    return node;
  }

  Item *second = split(node);

  // Rekursi untuk mengurutkan dua bagian
  node = mergeSort(node);
  second = mergeSort(second);

  // Gabungkan dua bagian yang telah diurutkan
  return merge(node, second);
}

void sortAscending()
{
  if (head == NULL)
  {
    cout << "Double Linked List masih kosong!" << endl;
  }
  else
  {
    head = mergeSort(head);

    // Update tail setelah merge sort
    tail = head;
    while (tail->next != NULL)
    {
      tail = tail->next;
    }

    cout << "Data berhasil diurutkan secara ascending!" << endl;
  }
}

// quick sort DSC
// Fungsi untuk swap data dua node
void swap(Item *a, Item *b)
{
  string tempNama = a->nama;
  string tempTier = a->tier;
  a->nama = b->nama;
  a->tier = b->tier;
  b->nama = tempNama;
  b->tier = tempTier;
}

// Fungsi partition untuk quick sort descending
Item *partition(Item *low, Item *high)
{
  string pivot = high->nama; // Menggunakan nama item sebagai pivot
  Item *i = low->prev;

  for (Item *j = low; j != high; j = j->next)
  {
    if (j->nama > pivot) // Untuk sorting descending, bandingkan yang lebih besar
    {
      i = (i == NULL) ? low : i->next;
      swap(i, j);
    }
  }
  i = (i == NULL) ? low : i->next;
  swap(i, high);
  return i;
}

// Fungsi rekursif quickSort untuk sorting descending
void quickSort(Item *low, Item *high)
{
  if (high != NULL && low != high && low != high->next)
  {
    Item *p = partition(low, high); // Dapatkan pivot
    quickSort(low, p->prev);        // Sorting sebelum pivot
    quickSort(p->next, high);       // Sorting setelah pivot
  }
}

// Fungsi untuk menjalankan quickSort pada seluruh linked list
void sortDescending()
{
  if (head == NULL)
  {
    cout << "Double Linked List masih kosong!" << endl;
  }
  else
  {
    quickSort(head, tail); // Panggil quickSort dari head hingga tail
    cout << "Data berhasil diurutkan secara descending!" << endl;
  }
}

// Fungsi Search
// Fibonachi Search
// Fungsi untuk mengakses node pada posisi tertentu (0-based index)
Item *getNodeAt(int index)
{
  cur = head;
  int currentIndex = 0;
  while (cur != NULL && currentIndex < index)
  {
    cur = cur->next;
    currentIndex++;
  }
  return cur;
}

// Implementasi Fibonacci Search untuk mencari berdasarkan ID
int fibonacciSearch(int keyID)
{
  int n = countDoubleLinkedList();

  // Inisialisasi bilangan Fibonacci
  int fibMMm2 = 0;              // (m-2)'th Fibonacci number
  int fibMMm1 = 1;              // (m-1)'th Fibonacci number
  int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci number

  // Temukan Fibonacci number yang terbesar lebih kecil atau sama dengan n
  while (fibM < n)
  {
    fibMMm2 = fibMMm1;
    fibMMm1 = fibM;
    fibM = fibMMm2 + fibMMm1;
  }

  int offset = -1;

  // Saat masih ada elemen yang akan dicari
  while (fibM > 1)
  {
    // Cek apakah fibMMm2 adalah indeks yang valid
    int i = min(offset + fibMMm2, n - 1);
    Item *node = getNodeAt(i);

    // Jika ID lebih besar, geser tiga angka Fibonacci
    if (node->id < keyID)
    {
      fibM = fibMMm1;
      fibMMm1 = fibMMm2;
      fibMMm2 = fibM - fibMMm1;
      offset = i;
    }
    // Jika ID lebih kecil, geser dua angka Fibonacci
    else if (node->id > keyID)
    {
      fibM = fibMMm2;
      fibMMm1 = fibMMm1 - fibMMm2;
      fibMMm2 = fibM - fibMMm1;
    }
    // Jika ID cocok
    else
    {
      return i; // Mengembalikan indeks yang cocok
    }
  }

  // Cek elemen terakhir
  if (fibMMm1 && getNodeAt(offset + 1)->id == keyID)
  {
    return offset + 1;
  }

  // Jika ID tidak ditemukan
  return -1;
}

// Jump Search
// Implementasi Jump Search untuk mencari berdasarkan ID
int jumpSearch(int keyID)
{
  int n = countDoubleLinkedList(); // Panjang linked list
  int step = sqrt(n);              // Ukuran blok yang dilompati
  int prev = 0;
  Item *node = getNodeAt(0); // Memulai pencarian dari head

  // Lompatan sampai menemukan blok yang lebih besar atau mencapai akhir
  while (node != NULL && node->id < keyID)
  {
    if (getNodeAt(min(step, n) - 1)->id >= keyID)
      break; // Jika ID lebih besar atau sama dengan keyID
    prev = step;
    step += sqrt(n);                    // Menambah langkah sesuai ukuran blok
    node = getNodeAt(min(step, n) - 1); // Ambil node berikutnya setelah lompatan
  }

  // Melakukan linear search
  node = getNodeAt(prev);
  while (node != NULL && prev < min(step, n))
  {
    if (node->id == keyID)
    {
      return prev; // Jika ditemukan, kembalikan indeks
    }
    node = node->next;
    prev++;
  }

  // Jika tidak ditemukan
  return -1;
}

// Boyer-Moore Search
// Fungsi untuk membuat tabel bad character shift
void badCharHeuristic(string str, int size, int badChar[256])
{
  for (int i = 0; i < 256; i++)
    badChar[i] = -1;

  for (int i = 0; i < size; i++)
    badChar[(int)str[i]] = i;
}

// Implementasi Boyer-Moore untuk mencari substring dalam string
int boyerMooreSearch(string text, string pattern)
{
  int m = pattern.size();
  int n = text.size();

  int badChar[256];
  badCharHeuristic(pattern, m, badChar);

  int shift = 0; // posisi di text
  while (shift <= (n - m))
  {
    int j = m - 1;

    while (j >= 0 && pattern[j] == text[shift + j])
      j--;

    if (j < 0)
    {
      return shift; // ditemukan
      shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
    }
    else
    {
      shift += max(1, j - badChar[(int)text[shift + j]]);
    }
  }

  return -1; // tidak ditemukan
}

// Implementasi Boyer-Moore untuk mencari semua kemunculan substring dalam linked list
vector<int> searchByName(string keyNama)
{
  vector<int> positions; // Vector untuk menampung semua posisi
  int pos = 1;
  cur = head;

  while (cur != NULL)
  {
    if (boyerMooreSearch(cur->nama, keyNama) != -1)
    {
      positions.push_back(pos); // Menyimpan posisi jika substring ditemukan
    }
    cur = cur->next;
    pos++;
  }

  return positions; // Mengembalikan semua posisi yang ditemukan
}

int main()
{
  clear();
  membuatDataAwal();
  string nama;
  string tier;
  int posisi;
  int cariID;        // variable untuk mencari berdasarkan ID
  string cariNama;   // variable untuk mencari berdasarkan nama
  vector<int> index; // vector untuk menampung semua posisi yang ditemukan

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
  cout << "7. Sort Merge ASC" << endl;
  cout << "8. Sort Merge DSC" << endl;
  cout << "9. Search" << endl;
  cout << "10. Keluar" << endl;
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
    cout << "Sort Merge ASC" << endl;
    clear();
    sortAscending();
    printDoubleLinkedList();
    lanjut();
    main();
    break;
  case 8:
    cout << "Urutkan (Quick Sort Descending)" << endl;
    clear();
    sortDescending();
    printDoubleLinkedList();
    lanjut();
    main();
    break;
  case 9:
    cin.ignore();
    clear();
    cout << "Fitur Search!!" << endl;
    cout << "1. Fibonachi Search berdasarkan ID" << endl;
    cout << "2. Jump Search berdasarkan ID" << endl;
    cout << "3. Boyer-Mooyer berdasarkan Nama" << endl;
    cout << "4. Display" << endl;
    cout << "5. Back" << endl;
    cin >> menu;
    switch (menu)
    {
    case 1:
      cout << "Masukkan ID yang ingin dicari: ";
      cin >> cariID;
      clear();
      posisi = fibonacciSearch(cariID);
      if (posisi != -1)
      {
        cout << "Item dengan ID " << cariID << " ditemukan di posisi ke-" << posisi + 1 << endl;
      }
      else
      {
        cout << "Item dengan ID " << cariID << " tidak ditemukan!" << endl;
      }
      lanjut();
      main();
      break;
    case 2:
      cout << "Masukkan ID yang ingin dicari: ";
      cin >> cariID;
      clear();
      posisi = jumpSearch(cariID);
      if (posisi != -1)
      {
        cout << "Item dengan ID " << cariID << " ditemukan di posisi ke-" << posisi + 1 << endl;
      }
      else
      {
        cout << "Item dengan ID " << cariID << " tidak ditemukan!" << endl;
      }
      lanjut();
      main();
      break;
    case 3:
      cout << "Masukkan substring yang ingin dicari: ";
      cin.ignore();
      getline(cin, cariNama);
      clear();
      index = searchByName(cariNama);

      if (!index.empty())
      {
        cout << "Substring \"" << cariNama << "\" ditemukan di index: ";
        for (int i = 0; i < index.size(); i++)
        {
          cout << index[i];
          if (i != index.size() - 1)
            cout << ", ";
        }
        cout << endl;
      }
      else
      {
        cout << "Substring \"" << cariNama << "\" tidak ditemukan!" << endl;
      }
      lanjut();
      main();
      break;
    case 4:
      clear();
      printDoubleLinkedList();
      lanjut();
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
  case 10:
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