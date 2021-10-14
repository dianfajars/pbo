#include <iostream>
using namespace std;

class usia{
    private:
    int tl, ts;

    public:
    void assign(int tahunlahir, int tahunskrg){
        tl = tahunlahir;
        ts = tahunskrg;
    }
    int umur(){
        return ts-tl;
    }
};

int main(){
    usia obj;
    obj.assign(1990,2021);
    cout<<"Berarti usia anda sekarang adalah "<<obj.umur()<<" Tahun";

return 0;
}