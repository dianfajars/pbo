#include <iostream>
using namespace std;

class Time{
    private:
    int hour, minute, second;

    public:
    Time(int hour=0, int minute=0, int second=0);
    void setWaktu(int jam, int menit, int detik);
    int getJam();
    int getMenit();
    int getDetik();
};

Time::Time(int hour, int minute, int second){
    setWaktu(hour, minute, second);
};

void Time::setWaktu(int jam, int menit, int detik){
    if ((jam>=0 && jam<24) && (menit>=0 && menit<59) && (detik>=0 && detik<59)){
        hour = jam;
        minute = menit;
        second = detik;
    } else{
        cout << "Format Salah/Format Tidak Diketahui"<<endl;
    }
};

int Time::getJam(){
    return hour;
}

int Time::getMenit(){
    return minute;
}

int Time::getDetik(){
    return second;
}

int main(){
    Time t;
    int jam, menit, detik;
    cout<<"Masukkan Format Waktu"<<endl;
    cout<<"Jam : ";
    cin>>jam;
    cout<<"Menit : ";
    cin>>menit;
    cout<<"Detik : ";
    cin>>detik;

    t.setWaktu(jam, menit, detik);
    cout<< endl << t.getJam() << ":" << t.getMenit() << ":" << t.getDetik(); 
    return 0;
}