#include<iostream>
using namespace std;

int main()
{
int thnlahir, thnskrg, usia;

cout<<"\nMasukkan Tahun Kelahiran Anda:";
cin>>thnlahir;
cout<<"Masukkan Tahun Sekarang:";
cin>>thnskrg;
usia=thnskrg-thnlahir;
cout<<"\nUsia anda sekarang adalah "<<usia<< "tahun";
return 0;
}