#include <iostream>
#include<fstream>

using namespace std;
int main()
{
    ifstream oku ("abc.txt");
    int soruSayisi;
    oku >> soruSayisi;//bilgileri dosyadan aldým.
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
    while (oku)//deðer atamasý yaptým.
    {
        oku >> ogrNo[i] >> ogrCvp[i];
        i++;
    }
    for (j = 0; j < 6; j++)//aldýðým deðerleri ekrana yansýttým.
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
        
        for (k = 0; k < 19; k++)//cevaplar kadar döndürdüm virgül dahil.
        {
            if (ogrCvp[i][k] != ',')//virgüllerden kurtulmak için if kullandým.
            {
                if (cvpa[x] == ogrCvp[i][k])//doðru yanlýþ ve boþ için puan verdim.
                {
                    dogru+=4;
                }
                
                else if(' '==ogrCvp[i][k])//boþluk deðerine 0 verdim.
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
   	diziYuz[n]=(puan[n]*10)/4;//100 lük deðere çevirdim.
   }
   for(int a=0;a<5;a++)//iç içe for ile numaralar ile beraber puanlarý sýraladým.
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
   int ort,toplam;//burada da ortalama, fark, yüksek, düþük, medyan hesaplayýp yansýttým.
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
