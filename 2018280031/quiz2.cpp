#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	ifstream dosya("metin.txt");/*veriyi oluþturduðum .txt uzantýlý belgenin içinden aldým*/
	
	int value,temp,j;
	char sirali;
	int dizi[20];
	while(j<20){
		dosya>>dizi[j];
		cout<<dizi[j]<<"	";
		j++;
		if(j%2==0){/*alýrken satýr sütün yapmadýðý için satýr sütün yapabileceði þekilde*/
			cout<<endl;/*iki sütündda bir alt satýra geçmesini saðladým*/
		}
	}
	cout<<"Hangi sutun'a gore siralamak istersiniz? (1/2)";
	int secim;
	int a=0;/*bundan sonrasýný ilk ödevdeki gibi yapaya çalýþtým ama yapamadým :( */
	cin>>secim;
	if(secim==1){
	int dizi1[10];
	for(int i=0;i<20;i+=2){
		dizi[i]>>dizi1[a];
		a++;
	}
	for(a=0;a<9;a++){
		for(int b=a+1;b<10;b++){
			if(dizi1[a]>dizi1[b]){
				temp=dizi1[a];
				dizi1[a]=dizi1[b];
				dizi1[b]=temp;
			}
		}
		cout<<dizi1[a];
	}
	for(int c=0;c<10;c++){
		cout<<dizi1[c]<<endl;
	}
	}
	if(secim==2){
	int dizi2[10];
	for(int i=1;i<20;i+=2){
		dizi[i]>>dizi2[a];
		a++;
	}
	for(a=0;a<9;a++){
		for(int b=a+1;b<10;b++){
			if(dizi2[a]>dizi2[b]){
				temp=dizi2[a];
				dizi2[a]=dizi2[b];
				dizi2[b]=temp;
			}
		}
		cout<<dizi2[a];
	}
	for(int c=0;c<10;c++){
		cout<<dizi2[c]<<endl;
	}
	}
	}
	/*
	Kaynakça;
	1-)https://www.yusufsezer.com.tr/cpp-dosya-islemleri/
	2-)http://teknokafe.net/2017/11/22/c-txt-dosyalama-islemleri/
	3-)https://www.algoritmaornekleri.com/c-plus-plus/c-dizi-elemanlarini-kucukten-buyuge-siralama/
	*/
