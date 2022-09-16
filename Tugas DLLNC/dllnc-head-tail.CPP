
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

// Dewi Putri Ayuningsih
//A12.2019.06284

int pil;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();
void tambah_tengah();
void hapus_tengah();

struct Node
{int notest;
char nama[20];
int nilai;
Node *next;
Node *prev;
};
Node *head = NULL;
Node *tail = NULL;

void tambahdepan()

{
Node *temp;
// masukkan data
temp = new Node;
clrscr();
cout<<"Isikan Data Simpul Baru\n";
cout<<"=============================\n";
cout << "No Test : "; cin >> temp->notest;
cout << "Nama : "; gets(temp->nama);
cout << "Nilai : "; cin >> temp->nilai;
temp-> prev = NULL;
temp->next = NULL;
cout << endl;

// Set up link to this node
if (head == NULL)
{head = temp;
tail = temp;
}

else
{temp->next = head;
head->prev = temp;
head = temp;
}
}
void tambahbelakang() {
Node *temp;
// masukkan data
temp = new Node;
clrscr();
cout << "Isikan Data simpul baru\n";
cout << "============================\n";
cout << "No Test 	: "; cin >> temp -> notest;
cout << "Nama 		: "; gets(temp->nama);
cout << "Nilai 	: "; cin >> temp->nilai;
temp->prev = NULL;
temp->next = NULL;
cout << endl;


// Set up link to this node
if (head == NULL)
{
head = temp;
tail = temp;
}
else
{
tail->next = temp;
temp-> prev = tail;
tail = temp;
}
}

void hapusdepan()
{
Node *temp;
temp = head;
// cek apakah kosong, 1 node, atau bbrp node...
if (head == NULL)
{cout << "\nLinked List Kosong ! (Enter] ";
getch();
}
else
{
//jika ada sebuah node
if(head->next == NULL) {
head = NULL;
tail = NULL;
}else
{
//jika node lebih dari 1
head = head->next;
head->prev = NULL;
}
delete temp;
}
}

void hapusbelakang()
{Node *temp;
temp = tail;
// cek apakah kosong, 1 node, atau bbrp node
if (head == NULL)
{cout << "\nLinked List Kosong ! [Enter] "; getch();
}
else
{//jika ada sebuah node
if(head->next == NULL)
{
head = NULL;
tail = NULL;
}
else {
//jika node lebih dari 1
tail = temp->prev;
tail->next = NULL;
} delete temp;
}
}
void print_node()
{Node *temp;
temp = head;

if(temp == NULL)
cout << "\nEmpty List !, [Enter]";
else
{
clrscr();
cout << "\nIsi Linked List\n";
cout << "============================\n";
do
{
cout << "No test : " << temp->notest;
cout << ", nama : " << temp->nama;
cout << ", nilai : " << temp->nilai;
cout << endl;
temp = temp->next;
}while(temp != NULL);
cout << "===========================\n";
cout << "[Enter]";
}getch();
}

//program utama
void main()
{
int pilih;
do
{ //Tampilan menu
clrscr();
cout << "---------------------------\n"
	<< " Menu Pilihan (SLLC)\n"
   << "---------------------------- \n"
   << " [1] Tambah Depan \n"
   << " [2] Tambah Belakang \n"
   << " [3] Hapus Depan \n"
   << " [4] Hapus Belakang \n"
   << " [5) Cetak Linked List \n"
   << " [6] Keluar \n\n"
   << "---------------------------\n"
   << "Masukkan pilihan : "; cin >> pilih;
   switch (pilih)
{
case 1:
tambahdepan();
break;
case 2:
tambahbelakang();
break;
case 3:
hapusdepan();
break;
case 4:
hapusbelakang();
break;
case 5:
print_node();
break;
default:
cout << "Pilihan tidak tersedia ! ";
break;
}
}while (pilih != 6);
}


