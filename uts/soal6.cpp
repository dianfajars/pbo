#include <iostream>
using namespace std;

class calculator{
    private:
    int a,b;
    public:
    int tambah(){
        return a+b;
    }
    int kurang(){
        return a-b;
    }
    int kali(){
        return a*b;
    }
    int bagi(){
        return a/b;
    }

    void inputan(){
        cout<<"Masukkan angka pertama: ";
        cin>>a;
        cout<<"Masukkan angka kedua: ";
        cin>>b;
    }
};

int main(){
    calculator c;
    int menu;
    char pilih;

    Menu:
    cout<<"Program Kalkulator Sederhana"<<endl;
    cout<<"1. Penjumlahan"<<endl;
    cout<<"2. Pengurangan"<<endl;
    cout<<"3. Perkalian"<<endl;
    cout<<"4. Pembagian"<<endl;
    cout<<"5. Keluar"<<endl;
    cout<<"Masukkan Pilihan Anda: ";
    cin>>menu;
    switch(menu){
        case 1:
        c.inputan();
        cout<<"Hasil= " << c.tambah() << endl;
        break;

        case 2:
        c.inputan();
        cout<<"Hasil= " << c.kurang() << endl;
        break;

        case 3:
        c.inputan();
        cout<<"Hasil= " << c.kali() << endl;
        break;

        case 4:
        c.inputan();
        cout<<"Hasil= " << c.bagi() << endl;
        break;

        case 5:
        goto Keluar;
        break;
    }
    cout << "Ingin coba lagi?(y/n)"<<endl;
    cin >> pilih;
    if((pilih=='y') || (pilih=='Y')){
        goto Menu;
    }
    else if ((pilih=='n') || (pilih=='N')){
        goto Keluar;
    }
    Keluar : 
    cout << "Terima Kasih"<<endl;
    return 0;
}