#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#define MAX 10

int antrian [MAX];
int front = -1;
int rear = -1;

//cek apakah antrian penuh.................................................
bool isFull()
{
	if((front == rear + 1) || (front == 0 && rear == MAX - 1)){
   	return true;
   }
   else
   	return false;
}

//cek apakah antrian kosong.................................................
bool isEmpty()
{
	return front == -1;
}

//menambahkan data ke antrian................................................
void enqueue(){
		if (isFull())
      {
      	cout<<"\n Antrian Penuh! ";
         getch();
      }
      else
      {
      	int xantrian;
         cout<<"\n Masukkan Antrian : ";
         cin>>xantrian;

         if(front == -1)
         		front = 0;

         rear = (rear + 1)% MAX;
         antrian[rear] = xantrian;
      }
}

//mengambil data dari antrian..............................................
void dequeue()
{
	int xdequeue;
   if (isEmpty())
   {
   	cout<<"\n Antrian Masih Kosong ! ";
   }
   else
   {
   	xdequeue = antrian[front];
      antrian[front] = 0;
      if (front == rear){
      	front = rear = -1;
      }
      else {
      	front = (front + 1)% MAX;
      }
      cout<<"\n  Mengambil Antrian \""<< xdequeue << "\"";
      	cout<<endl;
   }
   getch();
}
//menampilkan queue
void printQueue(){
	if(isEmpty())
   {
   	cout<<"\n Antrian Kosong ! ";
   }
   else {
   	cout<<"\n\n Kondisi Antrian : \n\n";
      cout<< "==== | ";
      for (int i = MAX-1; i>=0; i--)
      {
      	if(antrian[i] == 0)
         	cout<<" | ";
         else
         	cout<<antrian[i]<<" | ";
      }
      cout<<"==== \n";
      cout<<"Front = "<< front <<endl;
      cout<<"Rear = "<< rear <<endl;
      cout<<"\n Enter Kembali ke Menu ";
   }
   getch();
}

//program utama...................................................
void main()
{
	int pilih;
   do
   {
   	//Tampilan menu......................................
      clrscr();
      cout<<"-----------------------------------------\n"
      		<< " Menu Pilihan Circular Queue \n"
            << "---------------------------------------\n"
            << " [1] Enqueue / Tambah Antrian \n"
            << " [2] Dequeue / Hapus Antrian \n"
            << " [3] PrintDequeue / Cetak Antrian \n"
            << " [4] Keluar \n\n"
            << " ---------------------------------------\n"
            << "Masukkan Pilihan : "; cin>>pilih;
      switch (pilih)
      {
      	case 1:
         		enqueue();
               break;
         case 2:
         		dequeue();
               break;
         case 3:
         		printQueue();
               break;
         default:
         		cout<<" Pilihan Tidak Tersedia !";
               break;
      }
   }while (pilih !=4);
}
