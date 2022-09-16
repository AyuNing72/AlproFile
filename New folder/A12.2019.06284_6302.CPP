#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>

struct TNode
{
	int no;
	char nama[20];
	int klmpk, hrg, bulan, biaya, subsidi, ppn, byar;
	TNode *prev;
	TNode *next;
};

TNode *head = NULL;
TNode *tail = NULL;

int isEmpty()
{
	if(tail==NULL)
		return 1;
	else
		return 0;
}

void tambahDepan ()
{
	TNode *temp;
	temp = new TNode;
	// masukkan data...........................
	temp = new TNode;
	clrscr();

   cout << "Masukkan Data Baru\n";
	cout << "====================================\n\n";
	cout << "No Pelanggan 			: "; cin >> temp->no;
	cout << "Nama 				: "; gets(temp->nama);
	cout << "Kelompok [1/2/3] 		: "; cin >> temp->klmpk;

   if ( temp->klmpk == 1 )
   {
		temp->hrg = 5000;
 	}
 	else if ( temp->klmpk == 2 )
 	{
		 temp->hrg = 4000;
   }
   else if ( temp->klmpk == 3 )
	{
		temp->hrg = 3500;
   }
	else
	{
		cout<<"Data Kelompok Salah!\n\n";
	}

   cout<<"Harga per m3 			: "; cout << temp->hrg;
   cout<<"\nPemakaian per bulan 		: "; cin >> temp->bulan;

 	temp->biaya = temp->hrg * temp->bulan;
 	cout<<"Total Biaya 			: "; cout << temp->biaya;

   if ( temp->klmpk == 1 )
   {
      temp->ppn = temp->biaya * 3 / 100;
      temp->subsidi = temp->biaya * 5 / 10;
 	}
 	else if ( temp->klmpk== 2 )
 	{
       temp->ppn = temp->biaya * 2 / 100;
       temp->subsidi = temp->biaya * 3 / 10;
   }
   else if ( temp->klmpk == 3 )
	{
      temp->ppn = temp->biaya * 1 / 100;
      temp->subsidi = temp->biaya * 10 /100;
   }

   cout<<"\nPPN 				: "; cout << temp->ppn;
   cout<<"\nSubsidi 			: "; cout << temp->subsidi;

   temp->byar = temp->biaya - (temp->ppn + temp->subsidi);
   cout<<"\nTotal Bayar 			: "; cout << temp->byar;

	temp->prev = temp;
	temp->next = temp;
	cout << endl;

   if(isEmpty()==1)
   {
 		head=temp;
 		tail=temp;
 		head->next = head;
 		head->prev = head;
 		tail->next = tail;
 		tail->prev = tail;
   }
   else
   {
		temp->next = head;
		head->prev = temp;
		head = temp;
		head->prev = tail;
		tail->next = head;
	}
 	cout<<"\nData masuk\n";
 	getch();
}

void tambahBelakang()
{
	TNode *temp;
	temp = new TNode;
	temp->next = temp;
	temp->prev = temp;
	clrscr();

   cout << "Masukkan Data Baru\n";
	cout << "====================================\n\n";
	cout << "No Pelanggan 				: "; cin >> temp->no;
	cout << "Nama 				  	: "; gets(temp->nama);
	cout << "Kelompok [1/2/3] 			: "; cin >> temp->klmpk;

   if ( temp->klmpk == 1 )
   {
		temp->hrg = 5000;
 	}
 	else if ( temp->klmpk == 2 )
 	{
		 temp->hrg = 4000;
   }
   else if ( temp->klmpk == 3 )
	{
		temp->hrg = 3500;
   }
	else
	{
		cout<<"Kelompok Salah!\n\n";
	}

   cout<<"Harga per m3 				: "; cout << temp->hrg;
   cout<<"\nPemakaian per bulan 			: "; cin >> temp->bulan;

 	temp->biaya = temp->hrg * temp->bulan;
 	cout<<"Total Biaya 				:"; cout << temp->biaya;

   if ( temp->klmpk == 1 )
   {
      temp->ppn = temp->biaya * 3 / 100;
      temp->subsidi = temp->biaya * 5 / 10;
 	}
 	else if ( temp->klmpk == 2 )
 	{
       temp->ppn = temp->biaya * 2 / 100;
       temp->subsidi = temp->biaya * 3 / 10;
   }
   else if ( temp->klmpk == 3 )
	{
      temp->ppn = temp->biaya * 1 / 100;
      temp->subsidi = temp->biaya * 10 /100;
   }

   cout<<"\nPPN 					: "; cout << temp->ppn;
   cout<<"\nSubsidi 				: "; cout << temp->subsidi;

   temp->byar = temp->biaya - (temp->ppn + temp->subsidi);
   cout<<"\nTotal Bayar 				: "; cout << temp->byar;

	temp->prev = temp;
	temp->next = temp;
	cout << endl;

 	if(isEmpty()==1)
 	{
		head=temp;
 		tail=temp;
 		head->next = head;
 		head->prev = head;
 		tail->next = tail;
 		tail->prev = tail;
 	}
	else
   {
   	tail->next = temp;
 		temp->prev = tail;
 		tail = temp;
 		tail->next = head;
 		head->prev = tail;
	}
	cout<<"\nData masuk!\n";
   getch();
}

void hapusDepan()
{
	TNode *hapus;
	int d;
	hapus=head;
	if (isEmpty()==0)
   {
 		if(head != tail)
 		{
 			hapus = head;
 			d = hapus->no;
 			head = head->next;
 			tail->next = head;
 			head->prev = tail;
 			delete hapus;
 		}
 		else
 		{
 			d = head->no;
 			head = NULL;
 			tail = NULL;
 		}
 		cout<<d<<" terhapus\n";
	}
	else
	cout<<"Data Tidak Ada!\n";
}

void hapusBelakang()
{
	TNode *hapus;
	int d;
 	if (isEmpty()==0)
   {
 		if(head != tail)
      {
 			hapus = tail;
 			d = hapus->no;
	 		tail = tail->prev;
 			tail->next = head;
 			head->prev = tail;
 			delete hapus;
		}
		else
		{
		   d = head->no;
 			head = NULL;
 			tail = NULL;
		}
 		cout<<d<<" terhapus\n";
 	}
 	else
 	cout<<"Data Tidak Ada!\n";
}

void tampil()
{
	TNode *temp;
	temp = head;
   clrscr();
	if(isEmpty()==0)
   {
 		do
   	{
 			clrscr;
         cout << "Data Program\n";
			cout << "\nNo 		 	: " << temp->no;
			cout << "\nNama 			: " << temp->nama;
			cout << "\nKelompok 		: " << temp->klmpk;
 			cout << "\nHarga per m3 		: " << temp->hrg;
 			cout << "\nPemakaian per bulan 	: " << temp->bulan;
 			cout << "\nTotal Biaya 	 	: " << temp->biaya;
         cout << "\nPPN 			: " << temp->ppn;
         cout << "\nSubsidi 		: " << temp->subsidi;
         cout << "\nTotal Bayar 	 	: " << temp->byar;
         cout << endl;
         cout << endl;

			cout << endl;
 			temp=temp->next;
 		}
 		while(temp!=tail->next);
 		cout<<endl;
 	}
   else cout<<"Data kosong\n"
   <<"Silahkan Masukkan Data!!";
 	getch();
}

void clear()
{
	TNode *bantu,*hapus;
	if (isEmpty()==0)
   {
		bantu = head;
		while(bantu->next!=head)
      {
			hapus = bantu;
			bantu = bantu->next;
			delete hapus;
		}
		head = NULL;
	}
}

//program utama ...........................................
void main()
{
	int pilih;
	do
   {
		//Tampilan menu....................................
		clrscr();
		cout <<"Nama	: Dewi Putri Ayuningsih\n"
      <<"Nim 	: A12.2019.06284\n"
      <<"UAS ALOGARITMA&PEMOGRAMAN II / A12.6302 \n\n"
      <<"----------------------------------\n"
		<< " Menu Utama \n"
		<< "----------------------------------\n"
		<< " [1] Tambah Depan \n"
		<< " [2] Tambah Belakang \n"
		<< " [3] Hapus Depan \n"
		<< " [4] Hapus Belakang \n"
		<< " [5] Tampil Data \n"
		<< " [6] Selesai \n\n"
		<< "----------------------------------\n"
		<< "Masukkan pilihan : "; cin >> pilih;

      switch (pilih)
		{
			case 1:
				tambahDepan();
				break;
			case 2:
				tambahBelakang();
				break;
 			case 3:
				hapusDepan();
				break;
			case 4:
         	hapusBelakang();
				break;
			case 5:
				tampil();
				break;
			default:
				cout << "Pilihan Tidak Tersedia !";
				break;
		}
	}
   while (pilih != 6);
}