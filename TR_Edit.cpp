#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <unistd.h>
#define n 999
char namadb[20],hapus[10],edit[10],editkode[10],editnama[20],editharga[20],editkategori[20],editstok[5],search[20];
char recent[10],panah[10]="-->",panahh[10]="--<",back,sp;
int a,b,c,d,e,data,data2,pilih,edit2,sea,i,j,k,pil1,aa,cek;
int gotoxy(int x, int y){
COORD coord;//fungsi untuk membuat gotoxy dalam dev c++
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct history *head = NULL;
struct history *head2 = NULL;
struct history { 
    char indeks[10]; 
    struct history *next;
    struct history *prev;
};
int utama();
int menu5();
int menu8();
struct database
{
	char kode[10];
	char namabarang[20];
	char kategori[20];
	char harga[20];
	char stok[5];
};
int push(struct history **head_ref, char new_data[10])
{
    struct history *new_node = (struct history*) malloc(sizeof(struct history)); //penulisan malloc di visual studio
    strcpy(new_node->indeks,new_data); 
 
    /* 3. menjadikan next pada new node sebagai head*/
    new_node->next = (*head_ref);
 
    /* 4. pointer head menunjuk ke new node*/
    (*head_ref)= new_node;
}
database db[n];
int menu1()
{
	system("COLOR 70");
	system("CLS");
	gotoxy(30,3);printf("Membuat Database\n");
	fflush(stdin);
	gotoxy(10,5);printf("Nama Database : ");
	gotoxy(25,5);printf("[-"); gotoxy(50,5);printf("-]");
	gotoxy(28,5);gets(namadb);
	gotoxy(0,7);printf("Batas Maksimum yang diinputkan (20)\n");
	do
	{
	gotoxy(0,8);printf("Banyak data yang dimasukan : ");
	gotoxy(28,8);printf("["); gotoxy(53,8);printf("]");
	gotoxy(30,8);scanf("%d",&data);
	}
	while(data>=20);
	gotoxy(0,10);printf("Database %s \n",namadb);
	gotoxy(10,11);printf("Masukan Datanya\n");
	
	/* //-----------------------------dataa-----------------------------------
		gotoxy(1,12);printf(" | Masukan Kode |");
		gotoxy(19,12);printf("  Masukan Nama Barang |");
		gotoxy(44,12);printf("  Masukan Kategori |");
		gotoxy(65,12);printf("  Masukan Harga Barang |");
		gotoxy(89,12);printf("  Masukan Stok Barang[10-99] |");
	//----------------------------data-----------------------------
	*/
	for(a=0;a<data;a++)
	{
		printf("\n\nKode : "); scanf("%s",&db[a].kode);fflush(stdin);
		printf("Nama Barang : ");gets(db[a].namabarang);
		printf("Kategori : ");scanf("%s",&db[a].kategori);
		printf("Harga Barang : ");printf("Rp.");scanf("%s",&db[a].harga);
		printf("Stok Barang[10-99] : ");scanf("%s",&db[a].stok);
		
		/*gotoxy(4,13+(a));scanf("%s",&db[a].kode);
		fflush(stdin);
		gotoxy(23,13+(a));gets(db[a].namabarang);
		gotoxy(48,13+(a));scanf("%s",&db[a].kategori);
		gotoxy(69,13+(a));printf("Rp.");scanf("%s",&db[a].harga);
		gotoxy(93,13+(a));scanf("%s",&db[a].stok);
		*/
	}
	printf("\n\nBack To Menu");
	getch();
}
int menu2()
{
	system("COLOR 70");
	system("CLS");
	gotoxy(50,2);printf("Database %s \n",namadb);
		/*
		//-----------------------------dataa-----------------------------------
		gotoxy(1,7);printf("| No |");
		gotoxy(8,7);printf("  Masukan Kode |");
		gotoxy(26,7);printf("  Masukan Nama Barang |");
		gotoxy(53,7);printf("  Masukan Kategori |");
		gotoxy(72,7);printf("  Masukan Harga Barang |");
		gotoxy(96,7);printf("  Masukan Stok Barang |");
	//----------------------------data-----------------------------
	*/
	for(b=0;b<data;b++)
	{
		printf("\n\nNo[%d]\n",b+1);
		printf("Kode : %s\n",db[b].kode);
		printf("Nama Barang : %s\n",db[b].namabarang);
		printf("Masukan Kategori :  %s\n",db[b].kategori);
		printf("Masukan Harga Barang : Rp.%s\n",db[b].harga);
		printf("Masukan Stok Barang : %s\n",db[b].stok);		/*
		gotoxy(3,8+b);printf("[%d]",b+1);
		gotoxy(10,8+(b));printf("%s",db[b].kode);
		gotoxy(29,8+(b));printf(" %s",db[b].namabarang);
		gotoxy(56,8+(b));printf(" %s",db[b].kategori);
		gotoxy(75,8+(b));printf(" Rp.%s",db[b].harga);
		gotoxy(99,8+(b));printf(" %s",db[b].stok);
		*/
	}	
	getch();
}
int menu3()
{
	system("COLOR 70");
	system("CLS");
	gotoxy(50,5);printf("Database %s \n",namadb);
	gotoxy(20,7);printf("Batas Maksimum yang diinputkan (20)\n");
	do
{ gotoxy(0,8);printf("Banyak data yang dimasukan : ");
  gotoxy(28,8);printf("["); gotoxy(53,8);printf("]");
  gotoxy(30,8);scanf("%d",&data2);
	}
	while(data>=20);
	gotoxy(20,11);printf("Masukan Datanya\n");	
	/*
	//-----------------------------dataa-----------------------------------
		gotoxy(1,12);printf(" | Masukan Kode |");
		gotoxy(19,12);printf("  Masukan Nama Barang |");
		gotoxy(44,12);printf("  Masukan Kategori |");
		gotoxy(65,12);printf("  Masukan Harga Barang |");
		gotoxy(89,12);printf("  Masukan Stok Barang[10-99] |");
	//----------------------------data-----------------------------
	*/
	for(a=data;a<data+data2;a++)
	{
		/*
		gotoxy(4,13+(a-data));scanf("%s",&db[a].kode);
		fflush(stdin);
		gotoxy(23,13+(a-data));gets(db[a].namabarang);
		gotoxy(48,13+(a-data));scanf("%s",&db[a].kategori);
		gotoxy(69,13+(a-data));printf("Rp.");scanf("%s",&db[a].harga);
		gotoxy(93,13+(a-data));scanf("%s",&db[a].stok);
		*/
		printf("\n\nKode : "); scanf("%s",&db[a].kode);fflush(stdin);
		printf("Nama Barang : ");gets(db[a].namabarang);
		printf("Kategori : ");scanf("%s",&db[a].kategori);
		printf("Harga Barang : ");printf("Rp.");scanf("%s",&db[a].harga);
		printf("Stok Barang[10-99] : ");scanf("%s",&db[a].stok);
	}
	data=data+data2;
	gotoxy(12,a+20);printf("Back To Menu");
	getch();		
}
int menu4()
{
	del:
	system("COLOR 70");
	system("CLS");
	
	gotoxy(50,2);printf("Database %s \n",namadb);
	gotoxy(30,4);printf("Kode Data Barang Yang inngin Dihapus : ");
	/*
	//-----------------------------dataa-----------------------------------
		gotoxy(1,8);printf("| No |");
		gotoxy(8,8);printf("  Masukan Kode |");
		gotoxy(26,8);printf("  Masukan Nama Barang |");
		gotoxy(53,8);printf("  Masukan Kategori |");
		gotoxy(72,8);printf("  Masukan Harga Barang |");
		gotoxy(96,8);printf("  Masukan Stok Barang |");
	//----------------------------data-----------------------------
	*/
	for(b=0;b<data;b++)
	{
		/*
		gotoxy(3,9+b);printf("[%d]",b+1);
		gotoxy(10,9+(b));printf("%s",db[b].kode);
		gotoxy(29,9+(b));printf(" %s",db[b].namabarang);
		gotoxy(56,9+(b));printf(" %s",db[b].kategori);
		gotoxy(75,9+(b));printf(" Rp.%s",db[b].harga);
		gotoxy(99,9+(b));printf(" %s",db[b].stok);
		*/
		printf("\n\nNo[%d]\n",b+1);
		printf("Kode : %s\n",db[b].kode);
		printf("Nama Barang : %s\n",db[b].namabarang);
		printf("Masukan Kategori :  %s\n",db[b].kategori);
		printf("Masukan Harga Barang : Rp.%s\n",db[b].harga);
		printf("Masukan Stok Barang : %s\n",db[b].stok);
	}
	
printf("\nBack ? Press [b] : "); 
back=getche();
if(back=='b'){ utama();}
else { }
printf("\nHapus data?");scanf("%s",&hapus);	
for(c=0;c<data;c++)
	{
		if (strcmp(hapus,db[c].kode)==0)
		{
			for(a=c;a<data;a++)
			{
			strcpy(db[a].kode,db[a+1].kode); 
			strcpy(db[a].namabarang,db[a+1].namabarang); 
			strcpy(db[a].kategori,db[a+1].kategori); 
			strcpy(db[a].harga,db[a+1].harga); 
			strcpy(db[a].stok,db[a+1].stok); 
			}
			data=data-1;
			goto del;
		}
		else if(strcmp(hapus,db[c].kode)==!0)
		{ printf("Data Tidak Ada"); }
	}
getch();
}
int menu5()
{
	lima:
	system("COLOR 70");
	system("CLS");
	gotoxy(30,2);printf("Database %s \n",namadb);
	//-----------------------------dataa-----------------------------------
		/*gotoxy(1,8);printf("| No |");
		gotoxy(8,8);printf("  Masukan Kode |");
		gotoxy(26,8);printf("  Masukan Nama Barang |");
		gotoxy(53,8);printf("  Masukan Kategori |");
		gotoxy(72,8);printf("  Masukan Harga Barang |");
		gotoxy(96,8);printf("  Masukan Stok Barang |");
		*/
	//----------------------------data-----------------------------
	for(b=0;b<data;b++)
	{
		/*
		gotoxy(3,9+b);printf("[%d]",b+1);
		gotoxy(10,9+(b));printf("%s",db[b].kode);
		gotoxy(29,9+(b));printf(" %s",db[b].namabarang);
		gotoxy(56,9+(b));printf(" %s",db[b].kategori);
		gotoxy(75,9+(b));printf(" Rp.%s",db[b].harga);
		gotoxy(99,9+(b));printf(" %s",db[b].stok);
		*/
		printf("\n\nNo[%d]\n",b+1);
		printf("Kode : %s\n",db[b].kode);
		printf("Nama Barang : %s\n",db[b].namabarang);
		printf("Masukan Kategori :  %s\n",db[b].kategori);
		printf("Masukan Harga Barang : Rp.%s\n",db[b].harga);
		printf("Masukan Stok Barang : %s\n",db[b].stok);
	}
	
printf("Back ? Press [b]"); 
back=getche();
if(back=='b'){ utama();}
else { }
printf("\n\nInput Kode Barang : ");scanf("%s",&edit);
	for(a=0;a<=data;a++)
	{		
			ulang:
			if (strcmp(edit,db[a].kode)==0)
			{
				system("CLS");
				for(aa=0;aa<3;aa++)
					{	
					gotoxy(20+aa,5);printf("%c",panah[a]); gotoxy(69-a,6);printf("%c",panahh[a]);
					gotoxy(20+aa,6);printf("%c",panah[a]); gotoxy(69-a,7);printf("%c",panahh[a]);
					gotoxy(20+aa,7);printf("%c",panah[a]); gotoxy(69-a,8);printf("%c",panahh[a]);
					gotoxy(20+aa,8);printf("%c",panah[a]); gotoxy(69-a,9);printf("%c",panahh[a]);
					gotoxy(20+aa,9);printf("%c",panah[a]); gotoxy(69-a,10);printf("%c",panahh[a]);
					gotoxy(20+aa,10);printf("%c",panah[a]); gotoxy(69-a,11);printf("%c",panahh[a]);
					}
				gotoxy(25,5);printf("1. Kode Barang \n");
				gotoxy(25,6);printf("2. Nama Barang \n");
				gotoxy(25,7);printf("3. Kategori \n");
				gotoxy(25,8);printf("4. Harga \n");
				gotoxy(25,9);printf("5. Stok \n");
				gotoxy(25,10);printf("6. Exit \n");
				
				gotoxy(15,11);printf("Pilih : ");scanf("%d",&edit2);
				if(edit2==1)
				{
				gotoxy(16,14);printf("Masukan Kode Baru : ");scanf("%s",&editkode);
					strcpy(db[a].kode,editkode); 	
					goto ulang;
				}
				else if(edit2==2)
				{
					fflush(stdin);
					gotoxy(16,14);printf("Masukan Nama Baru : ");gets(editnama);
					strcpy(db[a].namabarang,editnama); 	
					goto ulang;
				}
				else if(edit2==3)
				{
				gotoxy(16,14);printf("Masukan Kategori Baru : ");scanf("%s",&editkategori);
					strcpy(db[a].kategori,editkategori); 
					goto ulang;	
				}
				else if(edit2==4)
				{
				gotoxy(16,14);printf("Masukan Harga Baru : Rp.");scanf("%s",&editharga);
					strcpy(db[a].harga,editharga); 	
					goto ulang;
				}
				else if(edit2==5)
				{
					gotoxy(16,14);printf("Masukan Stok Baru : ");scanf("%s",&editstok);
					strcpy(db[a].stok,editstok); 
					goto ulang;	
				}
				else if(edit2==6)
				{
					menu5();	
				}
			}
			else { menu5();	}
	}
}
int cari()
{
	sea=0;
	system("COLOR 70");
	system("CLS");
	gotoxy(30,2);printf("Database %s \n",namadb);
	gotoxy(10,4);printf("Pencarian Berdasarkan [Kode Barang] [Nama Barang]");gotoxy(60,4);scanf("%s",&search);
	for(a=0;a<data;a++){
	if (strcmp(search,db[a].kode)==0)
		{
			//-----------------------------dataa-----------------------------------
			/*gotoxy(1,8);printf("| No |");
			gotoxy(8,8);printf("  Masukan Kode |");
			gotoxy(26,8);printf("  Masukan Nama Barang |");
			gotoxy(53,8);printf("  Masukan Kategori |");
			gotoxy(72,8);printf("  Masukan Harga Barang |");
			gotoxy(96,8);printf("  Masukan Stok Barang |");
			*/
		//----------------------------data-----------------------------
			/*
				gotoxy(3,9+a);printf("[%d]",a+1);
				gotoxy(10,9+(a));printf("%s",db[a].kode);
				gotoxy(29,9+(a));printf(" %s",db[a].namabarang);
				gotoxy(56,9+(a));printf(" %s",db[a].kategori);
				gotoxy(75,9+(a));printf(" Rp.%s",db[a].harga);
				gotoxy(99,9+(a));printf(" %s",db[a].stok);
				*/
			printf("\n\nNo[%d]\n",b+1);
			printf("Kode : %s\n",db[b].kode);
			printf("Nama Barang : %s\n",db[b].namabarang);
			printf("Masukan Kategori :  %s\n",db[b].kategori);
			printf("Masukan Harga Barang : Rp.%s\n",db[b].harga);
			printf("Masukan Stok Barang : %s\n",db[b].stok);	
			sea=sea+1;
			push(&head,db[a].kode);
		}
	else if((strstr(db[a].namabarang,search)))
		{
				//-----------------------------dataa-----------------------------------
				/*gotoxy(1,8);printf("| No |");
				gotoxy(8,8);printf("  Masukan Kode |");
				gotoxy(26,8);printf("  Masukan Nama Barang |");
				gotoxy(53,8);printf("  Masukan Kategori |");
				gotoxy(72,8);printf("  Masukan Harga Barang |");
				gotoxy(96,8);printf("  Masukan Stok Barang |");
				//----------------------------data-----------------------------
				gotoxy(3,9+a);printf("[%d]",a+1);
				gotoxy(10,9+(a));printf("%s",db[a].kode);
				gotoxy(29,9+(a));printf(" %s",db[a].namabarang);
				gotoxy(56,9+(a));printf(" %s",db[a].kategori);
				gotoxy(75,9+(a));printf(" Rp.%s",db[a].harga);
				gotoxy(99,9+(a));printf(" %s",db[a].stok);*/
				printf("\n\nNo[%d]\n",a+1);
				printf("Kode : %s\n",db[a].kode);
				printf("Nama Barang : %s\n",db[a].namabarang);
				printf("Masukan Kategori :  %s\n",db[a].kategori);
				printf("Masukan Harga Barang : Rp.%s\n",db[a].harga);
				printf("Masukan Stok Barang : %s\n",db[a].stok);
			sea=sea+1;
			push(&head,db[a].kode);
		}
	}
	if((sea==0))
	{
		printf("data Tidak Ditemukan");
		
	}
}
int menu7()
{
	system("COLOR 70");	system("CLS");
	 /*//-----------------------------dataa-----------------------------------
				gotoxy(1,8);printf("| No |");
				gotoxy(8,8);printf("  Masukan Kode |");
				gotoxy(26,8);printf("  Masukan Nama Barang |");
				gotoxy(53,8);printf("  Masukan Kategori |");
				gotoxy(72,8);printf("  Masukan Harga Barang |");
				gotoxy(96,8);printf("  Masukan Stok Barang |");
	//----------------------------data-----------------------------
	*/
	aa=0;
	head2 = head;
  while (head2 != NULL)
  {
  	cek=0;
     strcpy(recent,head2->indeks);
	 
	
	for(a=0;a<data;a++){
	 if(strcmp(recent,db[a].kode)==0){
	 
	 
	 		/*gotoxy(3,9+(aa));printf(" [%d]",aa+1);
			gotoxy(10,9+(aa));printf(" %s",db[a].kode);
			gotoxy(29,9+(aa));printf(" %s",db[a].namabarang);
			gotoxy(56,9+(aa));printf(" %s",db[a].kategori);
			gotoxy(75,9+(aa));printf(" Rp.%s",db[a].harga);
			gotoxy(99,9+(aa));printf(" %s",db[a].stok);*/
			printf("\n\nNo[%d]\n",aa+1);
			printf("Kode : %s\n",db[a].kode);
			printf("Nama Barang : %s\n",db[a].namabarang);
			printf("Masukan Kategori :  %s\n",db[a].kategori);
			printf("Masukan Harga Barang : Rp.%s\n",db[a].harga);
			printf("Masukan Stok Barang : %s\n",db[a].stok);
			cek=cek+1;
    }
 	}
 	if(cek==0) 
	 	{	
		 gotoxy(18,23+aa);printf("%s",recent); 
		}
	 head2 = head2->next;
	 aa++;
}
}
int menu8()
{
	char *temp[10];
	go:
	system("CLS");
	gotoxy(30,2);printf("Database %s \n",namadb);
	gotoxy(10,4);printf("Sort By Kode Barang=[k] Nama Barang=[n] Kategori=[c] Stok=[s] Back[b]");
		/*//-----------------------------dataa-----------------------------------
		gotoxy(1,7);printf("| No |");
		gotoxy(8,7);printf("  Masukan Kode |");
		gotoxy(26,7);printf("  Masukan Nama Barang |");
		gotoxy(53,7);printf("  Masukan Kategori |");
		gotoxy(72,7);printf("  Masukan Harga Barang |");
		gotoxy(96,7);printf("  Masukan Stok Barang |");
	//----------------------------data-----------------------------
	*/
	for(b=0;b<data;b++)
	{
		/*(printf("data [%d]\n",b+1);
		printf(" Kode : %s\n",db[b].kode);
		printf(" Nama Barang : %s\n",db[b].namabarang);
		printf(" Kategori : %s\n",db[b].kategori);
		printf(" Harga Barang : Rp.%s\n",db[b].harga);
		printf(" Stok Barang : %s\n",db[b].stok);
		*/
		/*gotoxy(3,8+b);printf("[%d]",b+1);
		gotoxy(10,8+(b));printf("%s",db[b].kode);
		gotoxy(29,8+(b));printf(" %s",db[b].namabarang);
		gotoxy(56,8+(b));printf(" %s",db[b].kategori);
		gotoxy(75,8+(b));printf(" Rp.%s",db[b].harga);
		gotoxy(99,8+(b));printf(" %s",db[b].stok);*/
		printf("\n\nNo[%d]\n",b+1);
		printf("Kode : %s\n",db[b].kode);
		printf("Nama Barang : %s\n",db[b].namabarang);
		printf("Masukan Kategori :  %s\n",db[b].kategori);
		printf("Masukan Harga Barang : Rp.%s\n",db[b].harga);
		printf("Masukan Stok Barang : %s\n",db[b].stok);
	}	
	gotoxy(50,5);sp=getche();
	if(sp=='k'){
		for(i=0;i<data-1;i++){
			for(j=0;j<data-1;j++){
				if (strcmp(db[j].kode,db[j+1].kode)>0)
				{
					char *temp1 = (char *)malloc((strlen(db[j].kode)+1) * sizeof(char));
					char *temp2 = (char *)malloc((strlen(db[j].namabarang)+1) * sizeof(char));
					char *temp3 = (char *)malloc((strlen(db[j].kategori)+1) * sizeof(char));
					char *temp4 = (char *)malloc((strlen(db[j].harga)+1) * sizeof(char));
					char *temp5 = (char *)malloc((strlen(db[j].stok)+1) * sizeof(char));
					
					strcpy(temp1,db[j].kode); strcpy(db[j].kode,db[j+1].kode); strcpy(db[j+1].kode,temp1);
					free(temp1);
					strcpy(temp2,db[j].namabarang); strcpy(db[j].namabarang,db[j+1].namabarang); strcpy(db[j+1].namabarang,temp2);
					free(temp2);
					strcpy(temp3,db[j].kategori); strcpy(db[j].kategori,db[j+1].kategori); strcpy(db[j+1].kategori,temp3);
					free(temp3);
					strcpy(temp4,db[j].harga); strcpy(db[j].harga,db[j+1].harga); strcpy(db[j+1].harga,temp4);
					free(temp4);
					strcpy(temp5,db[j].stok); strcpy(db[j].stok,db[j+1].stok); strcpy(db[j+1].stok,temp5);
					free(temp5);
				}
			}
		}
		goto go;
	}
	if (sp=='n'){
		for(i=0;i<data-1;i++){
			for(j=0;j<data-1;j++){
			
		
				if (strcmp(db[j].namabarang,db[j+1].namabarang)>0)
				{
					char *temp1 = (char *)malloc((strlen(db[j].kode)+1) * sizeof(char));
					char *temp2 = (char *)malloc((strlen(db[j].namabarang)+1) * sizeof(char));
					char *temp3 = (char *)malloc((strlen(db[j].kategori)+1) * sizeof(char));
					char *temp4 = (char *)malloc((strlen(db[j].harga)+1) * sizeof(char));
					char *temp5 = (char *)malloc((strlen(db[j].stok)+1) * sizeof(char));
					
					strcpy(temp1,db[j].kode); strcpy(db[j].kode,db[j+1].kode); strcpy(db[j+1].kode,temp1);
					free(temp1);
					strcpy(temp2,db[j].namabarang); strcpy(db[j].namabarang,db[j+1].namabarang); strcpy(db[j+1].namabarang,temp2);
					free(temp2);
					strcpy(temp3,db[j].kategori); strcpy(db[j].kategori,db[j+1].kategori); strcpy(db[j+1].kategori,temp3);
					free(temp3);
					strcpy(temp4,db[j].harga); strcpy(db[j].harga,db[j+1].harga); strcpy(db[j+1].harga,temp4);
					free(temp4);
					strcpy(temp5,db[j].stok); strcpy(db[j].stok,db[j+1].stok); strcpy(db[j+1].stok,temp5);
					free(temp5);
				}
			}
		}
		goto go;
	
	}
	if (sp=='c'){
		for(i=0;i<data-1;i++){
			for(j=0;j<data-1;j++){
			
		
				if (strcmp(db[j].kategori,db[j+1].kategori)>0)
				{
					char *temp1 = (char *)malloc((strlen(db[j].kode)+1) * sizeof(char));
					char *temp2 = (char *)malloc((strlen(db[j].namabarang)+1) * sizeof(char));
					char *temp3 = (char *)malloc((strlen(db[j].kategori)+1) * sizeof(char));
					char *temp4 = (char *)malloc((strlen(db[j].harga)+1) * sizeof(char));
					char *temp5 = (char *)malloc((strlen(db[j].stok)+1) * sizeof(char));
					
					strcpy(temp1,db[j].kode); strcpy(db[j].kode,db[j+1].kode); strcpy(db[j+1].kode,temp1);
					free(temp1);
					strcpy(temp2,db[j].namabarang); strcpy(db[j].namabarang,db[j+1].namabarang); strcpy(db[j+1].namabarang,temp2);
					free(temp2);
					strcpy(temp3,db[j].kategori); strcpy(db[j].kategori,db[j+1].kategori); strcpy(db[j+1].kategori,temp3);
					free(temp3);
					strcpy(temp4,db[j].harga); strcpy(db[j].harga,db[j+1].harga); strcpy(db[j+1].harga,temp4);
					free(temp4);
					strcpy(temp5,db[j].stok); strcpy(db[j].stok,db[j+1].stok); strcpy(db[j+1].stok,temp5);
					free(temp5);
				}
			}
		}
		goto go;
	}
	if (sp=='s'){
	
		for(i=0;i<data-1;i++){
			for(j=0;j<data-1;j++){
			
		
				if (strcmp(db[j].stok,db[j+1].stok)>0)
				{
					char *temp1 = (char *)malloc((strlen(db[j].kode)+1) * sizeof(char));
					char *temp2 = (char *)malloc((strlen(db[j].namabarang)+1) * sizeof(char));
					char *temp3 = (char *)malloc((strlen(db[j].kategori)+1) * sizeof(char));
					char *temp4 = (char *)malloc((strlen(db[j].harga)+1) * sizeof(char));
					char *temp5 = (char *)malloc((strlen(db[j].stok)+1) * sizeof(char));
					
					strcpy(temp1,db[j].kode); strcpy(db[j].kode,db[j+1].kode); strcpy(db[j+1].kode,temp1);
					free(temp1);
					strcpy(temp2,db[j].namabarang); strcpy(db[j].namabarang,db[j+1].namabarang); strcpy(db[j+1].namabarang,temp2);
					free(temp2);
					strcpy(temp3,db[j].kategori); strcpy(db[j].kategori,db[j+1].kategori); strcpy(db[j+1].kategori,temp3);
					free(temp3);
					strcpy(temp4,db[j].harga); strcpy(db[j].harga,db[j+1].harga); strcpy(db[j+1].harga,temp4);
					free(temp4);
					strcpy(temp5,db[j].stok); strcpy(db[j].stok,db[j+1].stok); strcpy(db[j+1].stok,temp5);
					free(temp5);
				}
			}
		}
		goto go;
	}
	if(sp=='b')
	{
		utama;
	}
}
int utama()
{
mulai:
system("COLOR 70");	system("CLS");
gotoxy(50,3);printf("Pilih menu : \n");
for(a=0;a<3;a++)
{	
gotoxy(40+a,6);printf("%c",panah[a]); gotoxy(69-a,6);printf("%c",panahh[a]);
gotoxy(40+a,7);printf("%c",panah[a]); gotoxy(69-a,7);printf("%c",panahh[a]);
gotoxy(40+a,8);printf("%c",panah[a]); gotoxy(69-a,8);printf("%c",panahh[a]);
gotoxy(40+a,9);printf("%c",panah[a]); gotoxy(69-a,9);printf("%c",panahh[a]);
gotoxy(40+a,10);printf("%c",panah[a]); gotoxy(69-a,10);printf("%c",panahh[a]);
gotoxy(40+a,11);printf("%c",panah[a]); gotoxy(69-a,11);printf("%c",panahh[a]);
gotoxy(40+a,12);printf("%c",panah[a]); gotoxy(69-a,12);printf("%c",panahh[a]);
gotoxy(40+a,13);printf("%c",panah[a]); gotoxy(69-a,13);printf("%c",panahh[a]); 
gotoxy(40+a,14);printf("%c",panah[a]); gotoxy(69-a,14);printf("%c",panahh[a]);
//sleep(1);  
}

gotoxy(45,6);printf(" 1. Create Database \n");
gotoxy(45,7);printf(" 2. View  Database \n");
gotoxy(45,8);printf(" 3. Add New Data  \n");
gotoxy(45,9);printf(" 4. Delete  \n");
gotoxy(45,10);printf(" 5. Edit Data   \n");
gotoxy(45,11);printf(" 6. Search Data   \n");
gotoxy(45,12);printf(" 7. Recent History \n");
gotoxy(45,13);printf(" 8. Sort Data  \n");
gotoxy(45,14);printf(" 9. Exit Program \n");


gotoxy(53,17);printf("[ ");gotoxy(55,17);printf("]");gotoxy(54,17);scanf("%d",&pilih);
if(pilih==1){ menu1(); goto mulai; }
else if(pilih==2){ menu2(); goto mulai; }
else if(pilih==3){ menu3(); goto mulai; }
else if(pilih==4){ menu4(); goto mulai; }
else if(pilih==5){ menu5(); goto mulai; }
else if(pilih==6){ cari(); getch(); goto mulai; }
else if(pilih==7){ menu7(); getch(); goto mulai; }
else if(pilih==8){ menu8(); getch(); goto mulai; }
else { goto mulai;
}	
}
int main()
{
utama();
getch;
}
