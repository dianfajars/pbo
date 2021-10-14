<<<<<<< HEAD
#include <iostream>
=======
#include<iostream>
>>>>>>> febdaa066556d7be74e03668693124aa68a135c6
using namespace std;

int main(){
int thnlahir, thnskrg, usia; //type data yang diinput hanya berbentuk integer 

cout<<"\nMasukkan Tahun Kelahiran Anda:"; //Fungsi untuk mengeluarkan teks sebagai media penginputan tahun lahir anda
cin>>thnlahir; //Untuk input tahun lahir anda
cout<<"Masukkan Tahun Sekarang:"; //Fungsi untuk mengeluarkan teks sebagai media penginputan tahun sekarang
cin>>thnskrg;//Untuk input tahun sekarang
usia=thnskrg-thnlahir; //rumus untuk menghitung usianya
cout<<"\nUsia anda sekarang adalah "<<usia<< "tahun"; //Perintah untuk mengeluarkan hasil outputnya
return 0;
}