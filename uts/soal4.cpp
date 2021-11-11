#include <iostream>
#include <string.h>
using namespace std;

class Nama{
    public:
    string fname;
    string mname;
    string lname;
};

int main(){
    Nama n;
    int menu;
    char ulang;
    
    Pilihan:
    cout << "MENU" << endl;
    cout << "0. Keluar" << endl;
    cout << "1. Input" << endl;
    cout << "Masukkan Pilihan Anda: ";
    cin >> menu;
    switch(menu){
        case 0:
        goto Keluar;
        break;

        case 1:
        cout << "Masukkan First Name: "; cin >> n.fname;
        cout << "Masukkan Middle Name: "; cin >> n.mname;
        cout << "Masukkan Last Name: "; cin >> n.lname;
        cout << "Full Name: "<< n.fname << " " << n.mname << " " << n.lname << endl;
        break;
    }
    cout << "Ingin coba lagi?(y/n)"<<endl;
    cin >> ulang;
    if((ulang=='y') || (ulang=='Y')){
        goto Pilihan;
    }
    else if ((ulang=='n') || (ulang=='N')){
        goto Keluar;
    }
    Keluar : 
    cout << "Thanks"<<endl;
    return 0;
}