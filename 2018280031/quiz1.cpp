#include <iostream>
#include <sstream>
#include <string>

using namespace std;
	int selectionSort(int ogrNo[],int diziUzun){
		int degisken;
		stringstream ogrenciNumarasi;
		
		for(int i=0;i<diziUzun-1;i++)
		{
			for(int j=i+1;j<diziUzun;j++){
				if(ogrNo[i]>ogrNo[j]){/*dizi elemanlar�n� bir birleriyle kar��la�t�r�p e�er k���kse yer de�i�tiriyorum (bubble)*/
					degisken=ogrNo[i];
					ogrNo[i]=ogrNo[j];
					ogrNo[j]=degisken;
				}
			}
		}

		cout<<"ogrenci numaranizin kucukten buyuge siralanmis hali"<<endl;
		for(int a=0;a<diziUzun;a++){
			ogrenciNumarasi<<ogrNo[a];/*d�zenledi�im diziyi ekrana yans�t�yorum*/
		}
		cout<<ogrenciNumarasi.str();
	}
	int stringToIntVeSelectionSort(string ogrNo,int diziUzun){/*al�nan veri dizi ile s�ralamak i�in ay�rd�m */
		int intogrNo[diziUzun];
		for(int i=0;i<diziUzun;i++){
			intogrNo[i]=ogrNo[i]-'0';
		}
		selectionSort(intogrNo,diziUzun);
	}
	
	int main(){
		cout<<"ogrenci numarannini giriniz"<<endl;/*ogrenci nmaras�n� al�p hem uzunlu�a hem kendisine de�i�ken verdim*/
		string ogrID;
		cin>>ogrID;
		stringToIntVeSelectionSort(ogrID,ogrID.length());
	}
	/*
	Kaynak�a;
	1-)https://www.algoritmaornekleri.com/c-plus-plus/c-dizi-elemanlarini-kucukten-buyuge-siralama/
	2-)https://furkanaktas.com/yazilim/c-diziye-girilen-sayilari-siralama/
	3-)https://www.technoprogram.com/c-dizilerde-siralama-console-application.html
	*/
