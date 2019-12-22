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
				if(ogrNo[i]>ogrNo[j]){/*dizi elemanlarýný bir birleriyle karþýlaþtýrýp eðer küçükse yer deðiþtiriyorum (bubble)*/
					degisken=ogrNo[i];
					ogrNo[i]=ogrNo[j];
					ogrNo[j]=degisken;
				}
			}
		}

		cout<<"ogrenci numaranizin kucukten buyuge siralanmis hali"<<endl;
		for(int a=0;a<diziUzun;a++){
			ogrenciNumarasi<<ogrNo[a];/*düzenlediðim diziyi ekrana yansýtýyorum*/
		}
		cout<<ogrenciNumarasi.str();
	}
	int stringToIntVeSelectionSort(string ogrNo,int diziUzun){/*alýnan veri dizi ile sýralamak için ayýrdým */
		int intogrNo[diziUzun];
		for(int i=0;i<diziUzun;i++){
			intogrNo[i]=ogrNo[i]-'0';
		}
		selectionSort(intogrNo,diziUzun);
	}
	
	int main(){
		cout<<"ogrenci numarannini giriniz"<<endl;/*ogrenci nmarasýný alýp hem uzunluða hem kendisine deðiþken verdim*/
		string ogrID;
		cin>>ogrID;
		stringToIntVeSelectionSort(ogrID,ogrID.length());
	}
	/*
	Kaynakça;
	1-)https://www.algoritmaornekleri.com/c-plus-plus/c-dizi-elemanlarini-kucukten-buyuge-siralama/
	2-)https://furkanaktas.com/yazilim/c-diziye-girilen-sayilari-siralama/
	3-)https://www.technoprogram.com/c-dizilerde-siralama-console-application.html
	*/
