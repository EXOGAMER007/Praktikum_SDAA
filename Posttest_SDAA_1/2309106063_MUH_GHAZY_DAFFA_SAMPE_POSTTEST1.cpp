#include <iostream>
using namespace std;

void menara_hanoi(string menara_awal[3], string menara_tujuan[3], string menara_sementara[3], char index);

int main() {
    string menara_awal[3]={"piringan1", "piringan2", "piringan3"};
    string menara_tujuan[3];
    string menara_sementara[3];
    char index=0;//untuk kepentingan perulangan saja

    //menampilkan isi array
    cout << "SEBELUM PENYELESAIAN :" << endl;
    cout << "menara awal :" << endl;
    for (char i = 0; i < 3; i++){
        cout <<i+1 <<". " << menara_awal[i] << endl;
    };
    cout << "menara tujuan :" << endl;
    for (char i = 0; i < 3; i++){
        cout <<i+1 <<". " << menara_tujuan[i] << endl;
    };
    cout <<""<<endl;


    menara_hanoi(menara_awal, menara_tujuan, menara_sementara,index);
    return 0;
}
void menara_hanoi(string menara_awal[3], string menara_tujuan[3], string menara_sementara[3], char index) {
    if (index!=3){
        menara_sementara[index] = menara_awal[index];//menyalin isi array dari menara awal ke menara sementara
        menara_tujuan[index]=menara_sementara[index];//menyalin isi array dari menara sementara ke menara tujuan
        
        //membuat kosong array seolah olah kosong
        menara_awal[index] = " ";
        menara_sementara[index] = " ";


        index++;
        menara_hanoi(menara_awal, menara_tujuan, menara_sementara,index);//mulai melakukan rekursif
    }

    //menampilkan isi array
    cout << "SETELAH PENYELESAIAN :" << endl;
    cout << "menara awal :" << endl;
    for (char i = 0; i < 3; i++){
        cout <<i+1 <<". " << menara_awal[i] << endl;
    };

    cout << "menara tujuan :" << endl;
    for (char i = 0; i < 3; i++){
        cout <<i+1 <<". " << menara_tujuan[i] << endl;
    };
    exit(0);//mematikan program
};
