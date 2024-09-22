#include <iostream>
using namespace std;
 struct variabel
 {
    int menu;
    string menu2;
    int idx, jumlah = 3;
 };




 void lanjut(string &menu2);
 void bersih();

 //crud
 void lihat(string item[5]);
 string hapus(string item[5], int &idx, int &jumlah);
 void tambah(string item[5], int &jumlah);
 void ganti(string item[5], int &idx);


//variabel
variabel menu;
string status2;
variabel *ptrmenu = &menu;
string item[5] = {"Heartsteel", "Terminus", "Stasis", "", ""};
// ptrmenu->jumlah = 3;

 int main() {
    

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

    cin >> ptrmenu->menu;

    switch (ptrmenu->menu) {
    case 1:
        bersih();
        lihat(item);
        lanjut(ptrmenu->menu2);
        main();
        break;

    case 2:
        bersih();
        lihat(item);
        status2 = hapus(item, ptrmenu->idx, ptrmenu->jumlah);
        cout << status2 << endl;
        lanjut(ptrmenu->menu2);
        main();
        break;
    
    case 3:
        bersih();
        tambah(item, ptrmenu->jumlah);
        lanjut(ptrmenu->menu2);
        main();
        break;

    case 4:
        bersih();
        ganti(item, ptrmenu->idx);
        lanjut(ptrmenu->menu2);
        main();
        break;

    default:
        cout << "Inputan salah\n";
        lanjut(ptrmenu->menu2);
        main();
        break;
    }
    return 0;
}

void lanjut(string &menu2) {    
    cout << "tekan ENTER untuk lanjut\n";
    cin.clear();
    cin.ignore();
    getline(cin, menu2);
    bersih();
 }
 
 void bersih(){
    system("cls");
 }

 void lihat(string item[5]){
    cout << "==========Tier List ITEM==========\n";
    for (int i = 0; i < 5; i++){
        cout << "ITEM Tier ke-"<< i+1 <<" "<< item[i]<< endl;
        cout << "............" << endl;
    }
 }

  string hapus(string item[5], int &idx, int &jumlah){
    cout << "==========HAPUS DATA==========\n";
        cout << "Masukan nomor Tier yang ingin di hapus : ";
        cin >> idx;
        

        for (int i = idx-1; i < jumlah; i++){
            item[i] = item[i+1]; //mengganti data dengan data yang berada di index selanjutnya
        }
        jumlah--;
        string status = "berhasil dihapus";
        return status;
  }

void tambah(string item[5], int &jumlah){
    cout << "==========TAMBAH DATA==========\n";
    cout << "Masukan nama item : ";
    cin.ignore();
    getline(cin, item[jumlah]);
    jumlah++;
}

void ganti(string item[5], int &idx){
    cout << "==========GANTI DATA==========\n";
        cout << "masukan nomor Tier List data : ";
        cin >> idx;
        cout << "masukan nama item : ";
        cin.ignore();
        getline(cin, item[idx-1]);
}