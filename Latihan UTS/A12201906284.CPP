//sort record
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <iomanip.h>

int const n = 10;
int jumlah;
//struct smhs
//{
//char nama[10];
// int nilai;
//};
//smhs datamhs[n];
struct inpt
{
   int nip;
	char nama[10];
	int golongan;
   int gajipokok;
   int gajikotor;
   int gajibersih;
   int tunjangan;
   int potongan;
};
inpt pegawai[100];
void tukar(int a, int b)
{
	inpt temp;
   temp = pegawai[b];
   pegawai[b] = pegawai[a];
   pegawai[a] = temp;
}

void bubbleSort()
{
	for(int i=1;i<jumlah;i++)
	{
		for(int j=1; j<jumlah-i; j++)
      {
			if(pegawai[j].golongan > pegawai[j+1].golongan)
         	tukar(j,j+1);
      }
   }
}

void main()
{
	//berikan data ke datamhs
	cout<<"===PROGRAM BUBBLE SORT==="<<endl;
   cout << "NAMA: DEWI PUTRI AYUNINGSIH \n";
   cout<<"NIM : A12.2019.06284"<<endl;
   	//tampilkan data awal
		jumlah = 1;
		while (jumlah<n)
{
	   cout<< "\n\n masukkan data index [" << jumlah << "] :\n";
  	   gotoxy(5,7);cout << "\t Masukan NIP 		= "; cin >> pegawai[jumlah].nip;
		gotoxy(5,8);cout << "\t Masukan Nama 		= "; cin >> pegawai[jumlah].nama;
		gotoxy(5,9);cout << "\t Masukan Golongan 	= "; cin >> pegawai[jumlah].golongan;

      if (pegawai[jumlah].golongan == 1) {
      	 pegawai[jumlah].gajipokok = 1000000;
         }else if (pegawai[jumlah].golongan == 2) {
      	pegawai[jumlah].gajipokok = 2000000;
         }else if (pegawai[jumlah].golongan == 3) {
      	pegawai[jumlah].gajipokok = 3000000;
		} else {

      }

   	gotoxy(5,10);cout << "\t Masukan Tunjangan 	= "; cin >> pegawai[jumlah].tunjangan;
   	pegawai[jumlah].gajikotor = pegawai[jumlah].gajipokok + pegawai[jumlah].tunjangan;
  	   gotoxy(5,11);cout << "\t Gaji Kotor   	  	= " << pegawai[jumlah].gajikotor;
      cout << endl;
      gotoxy(5,12);cout << "\t Masukan Potongan 	= "; cin >> pegawai[jumlah].potongan;
      cout << endl;

      pegawai[jumlah].gajibersih = pegawai[jumlah].gajikotor - pegawai[jumlah].potongan;
      gotoxy(5,13);cout << "\t Gaji Bersih   	  	= " << pegawai[jumlah].gajibersih;
   jumlah++;
   cout<< "\nTambah data lagi [y/t] : ";
   char lagi = getche();
   if(strchr("Tt", lagi) != NULL) break;
   clrscr();
}

//tampilkan data
clrscr();
gotoxy(1,1);cout << "Nama : Dewi Putri Ayuningsih\n";
cout<<"NIM : A12.2019.06284"<<endl;
cout<<"\nData Awal : " << endl;
cout<<"Data Sebelum di Sort : " << endl;
cout<<"------------------------------------------------------------------------------------------------\n";
gotoxy(1,8);cout<<"------------------------------------------------------------------------------------------------";
for(int i=1; i<jumlah; i++)
{
   gotoxy(2,7);cout << " No";
   gotoxy(15,7);cout << "NIP";
   gotoxy(30,7);cout << "Nama";
   gotoxy(42,7);cout << "GOL";
   gotoxy(52,7);cout << "Gaji Kotor";
   gotoxy(68,7);cout << "Potongan";
   gotoxy(83,7);cout << "Gaji Bersih";

   gotoxy(2,9+i);cout<<" "<<i;
   gotoxy(15,9+i);printf("%i",pegawai[i].nip);
   gotoxy(31,9+i);printf(pegawai[i].nama);
   gotoxy(43,9+i);cout << pegawai[i].golongan;
   gotoxy(52,9+i);printf("%i",pegawai[i].gajikotor);
   gotoxy(68,9+i);printf("%i",pegawai[i].potongan);
   gotoxy(84,9+i);printf("%i",pegawai[i].gajibersih);
	//cout << setw(5) << (i+1);
   //gotoxy(15,5);cout << setw(15) << datamhs[i].nip;
   //cout << setw(5) << datamhs[i].nilai;
   //cout << endl;
   }
//proses pengurutan data

bubbleSort();

//tampilkan data setelah diurutkan
gotoxy(1,16);cout<<"\n\nData Setelah di Sort : " << endl;
gotoxy(1,19);cout<<"------------------------------------------------------------------------------------------------\n";
gotoxy(1,21);cout<<"------------------------------------------------------------------------------------------------";

for(int a=1; a<jumlah; a++)
{
 gotoxy(2,20);cout << " No";
   gotoxy(15,20);cout << "NIP";
   gotoxy(30,20);cout << "Nama";
   gotoxy(42,20);cout << "GOL";
   gotoxy(52,20);cout << "Gaji Kotor";
   gotoxy(68,20);cout << "Potongan";
   gotoxy(83,20);cout << "Gaji Bersih";

   gotoxy(2,22+a);cout<<" "<<a;
   gotoxy(15,22+a);printf("%i",pegawai[a].nip);
   gotoxy(31,22+a);printf(pegawai[a].nama);
   gotoxy(43,22+a);cout << pegawai[a].golongan;
   gotoxy(52,22+a);printf("%i",pegawai[a].gajikotor);
   gotoxy(68,22+a);printf("%i",pegawai[a].potongan);
   gotoxy(84,22+a);printf("%i",pegawai[a].gajibersih);
}
cout << "\n\nSorting Selesai";
getch();
}