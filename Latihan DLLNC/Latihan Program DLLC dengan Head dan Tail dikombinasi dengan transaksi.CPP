#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
struct TNode
{
int npp;
char nama[20];
int gol,gajipokok,gajikotor,tunjangan;
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
void tambahDepan (){
TNode *temp;
temp = new TNode;
// masukkan data...........................

temp = new TNode;
clrscr();
cout << "Isikan Data Simpul Baru\n";
cout << "====================================\n";
cout << "NPP : "; cin >> temp->npp;
cout << "Nama : "; gets(temp->nama);
cout << "Gol [1/2/3] : "; cin >> temp->gol;
 if ( temp->gol == 1 )
 {
 temp->gajipokok = 1000000;
 }
 else if ( temp->gol == 2 )
 {
 temp->gajipokok = 1500000;
 }
 else if ( temp->gol == 3 )
 {
 temp->gajipokok = 2000000;
 }
 else
 {
cout<<"Golongan Salah!";
 }
 cout<<"Gaji Pokok : "; cout <<temp->gajipokok;
 cout<<"\nTunjangan : "; cin>>temp->tunjangan;
 temp->gajikotor=temp->gajipokok+temp->tunjangan;
 cout<<"Gaji Kotor :";cout<<temp->gajikotor;
temp->prev = temp;
temp->next = temp;
cout << endl;
if(isEmpty()==1){
 head=temp;
 tail=temp;
 head->next = head;
 head->prev = head;
 tail->next = tail;
 tail->prev = tail;
 }
 else {
temp->next = head;
head->prev = temp;
head = temp;
head->prev = tail;
tail->next = head;
 }
 cout<<"Data masuk\n";
 getch();
}
void tambahBelakang(){
TNode *temp;
temp = new TNode;
temp->next = temp;
temp->prev = temp;
clrscr();
cout << "Isikan Data Simpul Baru\n";
cout << "====================================\n";
cout << "NPP : "; cin >> temp->npp;
cout << "Nama : "; gets(temp->nama);
cout << "Gol [1/2/3] : "; cin >> temp->gol;
 if ( temp->gol == 1 )
 {
 temp->gajipokok = 1000000;
}
else if ( temp->gol == 2 )
{
temp->gajipokok = 1500000;
}
else if ( temp->gol == 3 )
{
temp->gajipokok = 2000000;
}
 else
{
cout<<"Golongan Salah!";
}
 cout<<"\nGaji Pokok : "; cout <<temp->gajipokok;
 cout<<"\nTunjangan : "; cin>>temp->tunjangan;
 temp->gajikotor=temp->gajipokok+temp->tunjangan;
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
else {
 tail->next = temp;
 temp->prev = tail;
 tail = temp;
 tail->next = head;
 head->prev = tail;
}
cout<<"Data masuk\n";
}
void hapusDepan(){
TNode *hapus;
int d;
hapus=head;
if (isEmpty()==0){
 if(head != tail)
 {
 hapus = head;
 d = hapus->npp;
 head = head->next;
 tail->next = head;
 head->prev = tail;
 delete hapus;
 }
 else
 {
 d = head->npp;
 head = NULL;
 tail = NULL;
 }
 cout<<d<<" terhapus\n";
 }
else
cout<<"Masih kosong\n";
}
void hapusBelakang(){
TNode *hapus;
int d;
 if (isEmpty()==0){
 	if(head != tail){
 		hapus = tail;
      d = hapus->npp;
 tail = tail->prev;
 tail->next = head;
 head->prev = tail;
 delete hapus;
}
else
{
 d = head->npp;
 head = NULL;
 tail = NULL;
}
 cout<<d<<" terhapus\n";
 }
 else
 cout<<"Masih kosong\n";
 }
void tampil(){
TNode *temp;
temp = head;
if(isEmpty()==0){
do{
 clrscr;
 cout <<" ";
							cout << "NPP : " << temp->npp;
							cout << ", nama : "<< temp->nama;
							cout << ", Gol : "<< temp->gol;
 	cout << ",Gapok : "<<temp->gajipokok;
 		cout << ",Tunjangan:"<<temp->tunjangan;
 		cout << ",Gator :" <<temp->gajikotor;
						cout << endl;
 	temp=temp->next;
 		}
 while(temp!=tail->next);
 			cout<<endl;
 } else cout<<"Masih kosong\n";
 getch();
}
void clear(){
		TNode *bantu,*hapus;
      if (isEmpty()==0){
bantu = head;
while(bantu->next!=head){
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
cout << "----------------------------------\n"
<< " Menu Pilihan (DLLC)\n"
<< "----------------------------------\n"
<< " [1] Tambah Depan \n"
<< " [2] Tambah Belakang \n"
<< " [3] Hapus Depan \n"
<< " [4] Hapus Belakang \n"
<< " [5] Cetak Linked List \n"
<< " [6] Keluar \n\n"
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
cout << "Pilihan tidak tersedia ! ";
break;
}
} while (pilih != 6);
}