#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string InputKalimat, pilihan;
    char HurufSebelum, HurufSetelah, HrfSblmD, HrfStlhD;
    int AngkaInput, KunciEnkripsi, KunciDekripsi, PnjgKlmt;
    int jmlh=0;
    
    cout<<"=======================================================================\n";
    cout<<"==========================PROGRAM KRYPTOGRAFI==========================\n";
	cout<<"=======================================================================\n\n";
	
	cout<<"<>ENKRIPSI atau DEKRIPSI?[e/d]\t\t\t\t: ";
	cin>>pilihan;
	cin.ignore();
	
	if (pilihan=="e" || pilihan=="E" || pilihan=="enskripsi" || pilihan=="Enskripsi" || pilihan=="ENSKRIPSI"){
	    
	    //input kalimat yang akan di enskripsi
	    cout<<"<>MASUKAN KALIMAT YANG AKAN DI ENKRIPSI\t\t: ";
	    getline(cin, InputKalimat);
	    //menghitung panjang karakter dari input
	    PnjgKlmt= InputKalimat.length(); 
	    vector<int> data(PnjgKlmt);
	    //input huruf yang akan diubah
	    cout<<"\n<>MASUKAN 2 HURUF UNTUK KUNCI ENKRIPSI DAN DEKRIPSI";
	    cout<<"\n\t>Huruf sebelum enkripsi\t\t\t\t\t: ";
        cin>>HurufSebelum;
        //input huruf setelah diubah
	    cout<<"\t>Huruf setelah enkripsi\t\t\t\t\t: ";
        cin>>HurufSetelah;
        //kunci enskirpsi 
        cout<<"\n<>KUNCI ENKRIPSI ANDA ADALAH "<<HurufSebelum<<"="<<HurufSetelah<<endl;
        //proses mengubah input menjadi angka ascii
        for (char p: InputKalimat){
            if (isalpha(p)){
                data[jmlh]=(int) p;
                jmlh++;
            } else if(isspace(p)){
                data[jmlh]=(int) p;
                jmlh++;
            } else if (ispunct(p)){
                data[jmlh]=(int) p;
                jmlh++;
            }else{
                data[jmlh]=(int) p;
                jmlh++;
            }
        }
        cout<<"\n";
        //kunci enskripsi(angka)
        KunciEnkripsi = (int) HurufSetelah - (int) HurufSebelum;
        //proses enskripsi
        for(int j=0; j<PnjgKlmt; j++){
            data[j]=data[j] + KunciEnkripsi;
            if(data[j]>126){
                data[j]=data[j]-126;
                data[j]=data[j]+32;
            }
        }
        //output hasil enkripsi
        cout<<"<>HASIL ENKRIPSI PESAN KALIMAT = ";
        for (int k=0; k<PnjgKlmt; k++){
            cout<<(char) data[k];
        }
    }
	else if(pilihan == "d" || pilihan == "D" || pilihan == "dekripsi" || pilihan == "Dekripsi" || pilihan == "DEKRIPSI") {
	    //input kalimat yang akan diproses dekripsi
	    cout<<"<>MASUKAN KALIMAT YANG AKAN DI DEKRIPSI\t\t: ";
	    getline(cin, InputKalimat);
	    //menghitung panjang kalimat
	    PnjgKlmt = InputKalimat.length();
	    vector<int> data(PnjgKlmt);
	    //input kunci huruf yang digunakan untuk enkripsi sesebelum;
	    cout<<"\n<>MASUKAN KUNCI DEKRIPSI DENGAN KODE 2 HURUF\n";
	    cout<<"\t>Masukan huruf sebelum enkripsi\t\t\t: ";
	    cin>>HrfSblmD;
	    //input huruf kunci dekripsi setelahnya
	    cout<<"\t>Masukan huruf setelah enkripsi\t\t\t: ";
	    cin>>HrfStlhD;
	    cout<<"\n<>KUNCI UNTUK DEKRIPSI ANDA ADALAH "<<HrfSblmD<<"="<<HrfStlhD;
	    //proses menentukkan kunci dekripsi
	    KunciDekripsi=(int)HrfStlhD - (int)HrfSblmD;
	    //mengubah input kalimat menjadi angka ascii
	    for (char d: InputKalimat){
	        if(isalpha(d)){
	            data[jmlh]=(int) d;
	            jmlh++;
	        } else if(isdigit(d)){
	            data[jmlh]=(int) d;
	            jmlh++;
	        } else if(ispunct(d)){
	            data[jmlh]=(int) d;
	            jmlh++;
	        } else if(isspace(d)){
	            data[jmlh]=(int) d;
	            jmlh++;
	        } else{
	            data[jmlh]=(int) d;
	            jmlh++;
	        }
	    }
	    //proses dekripsi untuk mengubah input menggunakan kunci enkripsi
	    for(int i=0; i<PnjgKlmt; i++){
	        data[i]=data[i] - 32;
	        if(data[i]<KunciDekripsi){
	            data[i]= 126 + data[i];
	            data[i]= data[i] - KunciDekripsi;
	        } else{
	            data[i]=data[i]+32-KunciDekripsi;
	        }
	    }
	    
	    //menampilkan hasil dekripsi
	    cout<<endl;
	    cout<<"\n<>HASIL DEKRIPSI PESAN KALIMAT = ";
	    for(int i=0; i<PnjgKlmt; i++){
	        cout<< (char) data[i];
	    }
	} else {
	    const string merah = "\033[31m";
	    cout<<merah<<"Input tidak valid!!";
	}

  return 0;
}

