#include <iostream>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

int pilih;
char kembali;
const char* hostname = "127.0.0.1";
const char* user = "root";
const char* pass = "";
const char* dbname = "uas";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connectdb(){
    MYSQL * conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
    if (conn) {
        cout<< "berhasil"<<endl;
        return conn;
    } else {
        cout<< "gagal"<<endl;
        return conn;
    }
}

class crud{
    public:
void insertDataMahasiswa(MYSQL* conn){ //tabel mahasiswa
    int qstate =0;
    stringstream inserttodb;
    string nim, nama, id;
    cout << "insert Id : "<<endl;
    cin>>id;
    cout << "insert NIM : "<<endl;
    cin>>nim;
    cout << "insert Nama : "<<endl;
    cin>>nama;
    inserttodb << "INSERT INTO mahasiswa (id, nim, nama) VALUES ('"+id+"','"+nim+"','"+nama+"')";
    string query = inserttodb.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if (qstate == 0){
        cout <<"berhasil insert"<<endl;
    } else {
        cout <<"gagal"<<endl;
    }
}

void insertDataMatkul(MYSQL* conn){ //tabel matkul
    int qstate =0;
    stringstream inserttodb;
    string kd_matkul, nama, id;
    cout << "insert Id : "<<endl;
    cin>>id;
    cout << "insert Kode Matkul: "<<endl;
    cin>>kd_matkul;
    cout << "insert Nama : "<<endl;
    cin>>nama;
    inserttodb << "INSERT INTO matkul (id, kd_matkul, nama) VALUES ('"+id+"','"+kd_matkul+"','"+nama+"')";
    string query = inserttodb.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if (qstate == 0){
        cout <<"berhasil insert"<<endl;
    } else {
        cout <<"gagal"<<endl;
    }
}


void displayData(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;

    if (conn){
        int qstate = mysql_query(conn, "SELECT * FROM mahasiswa JOIN matkul ON mahasiswa.id = matkul.id");
        if(!qstate){
            res = mysql_store_result(conn);
            int count = mysql_num_fields(res);
            cout << "=========================================LIST DATA=============================================\n";
            cout << "\tID\tNIM\tNAMA\tCreated at\t\tLast Updated\t\tID\tKd_MK\tNama MK\t\tCreated at\t\tLast Updated\n";
            while(row = mysql_fetch_row(res)){
                for(int i=0; i<count;i++){
                    cout <<"\t"<<row[i];
                }
                cout<<endl;
            }

        }
    } else {
        cout << "Data Kosong" <<endl;
    }
}

void updateDataMahasiswa(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, updatedb;
    selectdb << "SELECT * FROM mahasiswa WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);
    string nim, nama;
    if(x>0){
        cout << "insert NIM : "<<endl;
        cin>>nim;
        cout << "insert Nama : "<<endl;
        cin>>nama;
        updatedb <<"UPDATE mahasiswa SET nim = '"+nim+"', nama= '"+nama+"' WHERE id = '"+id+"' ";
        string query = updatedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

void updateDataMatkul(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, updatedb;
    selectdb << "SELECT * FROM matkul WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);
    string kd_matkul, nama;
    if(x>0){
        cout << "insert Kode Matkul : "<<endl;
        cin>>kd_matkul;
        cout << "insert Nama : "<<endl;
        cin>>nama;
        updatedb <<"UPDATE matkul SET kd_matkul = '"+kd_matkul+"', nama= '"+nama+"' WHERE id = '"+id+"' ";
        string query = updatedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

void deleteDataMahasiswa(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, deletedb;
    selectdb << "SELECT * FROM mahasiswa WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);

    if(x>0){
        deletedb <<"DELETE FROM mahasiswa WHERE id = '"+id+"' ";
        string query = deletedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

void deleteDataMatkul(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, deletedb;
    selectdb << "SELECT * FROM matkul WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);

    if(x>0){
        deletedb <<"DELETE FROM matkul WHERE id = '"+id+"' ";
        string query = deletedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}
};

int main(){
    MYSQL* conn = connectdb();
    crud cr;
    do{
        cout<<"MENU";
        cout<<"\n 0. Exit";
        cout<<"\n 1. Create Data Mahasiswa";
        cout<<"\n 2. Create Data Mata Kuliah";
        cout<<"\n 3. Read Mahasiswa dan Mata Kuliah";
        cout<<"\n 4. Update Data Mahasiswa";
        cout<<"\n 5. Update Data Mata Kuliah";
        cout<<"\n 6. Delete Mahasiswa";
        cout<<"\n 7. Delete Matkul";
        
        cout<<"\nPilih : "; cin>>pilih;

        switch(pilih){
            case 0:
                cout<<"\nThanks"<<endl;
                return 0;
            case 1:
				cr.insertDataMahasiswa(conn);
                break;
            case 2:
                cr.insertDataMatkul(conn);
                break;
            case 3:
				cr.displayData(conn);
                break;
            case 4:
                cr.updateDataMahasiswa(conn);
                cr.displayData(conn);
                break;
            case 5:
                cr.updateDataMatkul(conn);
                cr.displayData(conn);
                break;
            case 6:
                cr.deleteDataMahasiswa(conn);
                break;
            case 7:
                cr.deleteDataMatkul(conn);
                break;
            default:
                cout<<"Pilihan Salah"<<endl;
                break;
            }
            cout<<"Ingin memilih menu lain (y/t)? ";
            cin>>kembali;
            cout<<endl;
        }
        while (kembali!= 't');
        cout<<"Thanks"<<endl;
    return 0;

}