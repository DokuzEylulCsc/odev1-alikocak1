#include <iostream>
#include<fstream>

using namespace std;
int main()
{
    ifstream oku ("abc.txt");
    int soruSayisi;
    oku >> soruSayisi;//bilgileri dosyadan ald�m.
    cout << soruSayisi<<endl;
    string cvp;
    oku >> cvp;
    char cvpa[10];
    int sayac = cvp.length();
    int i = 0, j = 0;
    while (i < sayac)
    {
        cvpa[j] = cvp[i];
        i += 2;
        j++;
    }
    for (int a = 0; a < 10; a++)
    {
        cout << cvpa[a];
    }
    cout << endl;
    string ogrNo[6];
    string ogrCvp[6];
    i = 0;
    while (oku)//de�er atamas� yapt�m.
    {
        oku >> ogrNo[i] >> ogrCvp[i];
        i++;
    }
    for (j = 0; j < 6; j++)//ald���m de�erleri ekrana yans�tt�m.
    {
        cout << ogrNo[j] <<" "<< ogrCvp[j] << endl;
    }
    //cout << ogrCvp[1][0]<<endl;
   

    int puan[5];
    int dogru = 0;
    int x = 0;
    int k;
    for (i = 0; i < 5; i++)
    {
        
        for (k = 0; k < 19; k++)//cevaplar kadar d�nd�rd�m virg�l dahil.
        {
            if (ogrCvp[i][k] != ',')//virg�llerden kurtulmak i�in if kulland�m.
            {
                if (cvpa[x] == ogrCvp[i][k])//do�ru yanl�� ve bo� i�in puan verdim.
                {
                    dogru+=4;
                }
                
                else if(' '==ogrCvp[i][k])//bo�luk de�erine 0 verdim.
				{
                	dogru+=0;
				}
				else
				{
					dogru--;
				}
                x++;
                /*for (int x = 0; x < 10; x++)
                {
                    if (cvpa[x] == ogrCvp[i][j])
                    {
                        j++;
                        dogru ++;
                    }
                }*/
            }
        }
        puan[i] = dogru;
        dogru = 0;
        x=0;
    }
    int diziYuz[6];
    int n;
    int temp;
    
    string temp1;
    for(n=0;n<5;n++)
   {
   	diziYuz[n]=(puan[n]*10)/4;//100 l�k de�ere �evirdim.
   }
   for(int a=0;a<5;a++)//i� i�e for ile numaralar ile beraber puanlar� s�ralad�m.
   {
   	for(int b=0;b<5;b++)
   	{
   		if(diziYuz[a]>diziYuz[b])
   		{
   			temp=diziYuz[a];
   			diziYuz[a]=diziYuz[b];
   			diziYuz[b]=temp;
   			temp1=ogrNo[a];
   			ogrNo[a]=ogrNo[b];
   			ogrNo[b]=temp1;
	    }
    }
   }
   for(int c=0;c<5;c++)
   {
   	cout<<c+1<<". "<<ogrNo[c]<<"	"<<diziYuz[c]<<endl;
   }
   int ort,toplam;//burada da ortalama, fark, y�ksek, d���k, medyan hesaplay�p yans�tt�m.
   for(int d=0;d<5;d++){
   	toplam+=diziYuz[d];
   }
   int fark;
   fark=diziYuz[0]-diziYuz[4];
   ort=toplam/5;
   int median;
   
   cout<<endl;
   cout<<"Ortalama :"<<ort<<endl;
   cout<<"En yUksek :"<<diziYuz[0]<<endl;
   cout<<"En dusuk :"<<diziYuz[4]<<endl;
   cout<<"Aciklik :"<<fark<<endl;
   cout<<"Median :"<<diziYuz[2]<<endl;
}
