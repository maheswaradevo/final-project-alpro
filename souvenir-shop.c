#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void cari();
void pembelian();
void daftar_souvenir();
void tambah_souvenir();
void update_stock();

typedef struct{
    char nama[50];
    int no;
    int jmlh;
    int harga;
}Souvenir;

FILE*SOUVENIR;
FILE*PEMBELIAN;

int main(){
    system("cls");
    char pilihan;
    char ulangi = 'y';
    do{
        printf("===================================================================\n");
        printf("===========================SOUVENIR SHOP===========================\n");
        printf("===================================================================\n");
        printf("~MENU~ \t: \n");
		printf("1. Daftar Souvenir \n2. Cari Souvenir \n3. Tambah Souvenir (Admin) \n4. Daftar Pembelian (Admin) \n5. Update (Admin) \n6. Keluar \n");
		printf("Masukkan Pilihan :");
		scanf("%c", &pilihan); fflush(stdin);
		system("cls");
        switch (pilihan){
			case '1':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                           Daftar Souvenir                            |\n");
				printf("|______________________________________________________________________|\n");
				daftar_souvenir();
				break;
			case '2':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                             Cari Souvenir                            |\n");
				printf("|______________________________________________________________________|\n");
				//cari();
				break;
			case '3':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Tambah Souvenir                           |\n");
				printf("|______________________________________________________________________|\n");
				tambah_souvenir();
				break;
			case '4':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Daftar Pembelian                          |\n");
				printf("|______________________________________________________________________|\n");
				//pembelian();
				break;
			case '5':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                                 Update                               |\n");
				printf("|______________________________________________________________________|\n");
				//update_stock();
				break;
			case '6':
				system("pause");
      			exit(0);
				break;
			default:
				printf("~Pilihan yang anda masukkan salah~\n");
		}
        printf("Kembali ke menu ? (y/t) :"); 
        scanf("%c",&ulangi); fflush(stdin);
        system("cls");
    }   while(ulangi == 'y');
    return 0;
}

void tambah_souvenir(){
	Souvenir Produk;
	SOUVENIR = fopen("souvenir.txt", "a+");
	printf("Nama Produk \t\t: "); scanf("%[^\n]",&Produk.nama); fflush(stdin);
	printf("No Produk \t\t: "); scanf("%i",&Produk.no); fflush(stdin);
	printf("Jumlah Produk \t\t: "); scanf("%i", &Produk.jmlh); fflush(stdin);
	printf("Harga Produk \t\t: "); scanf("%i", &Produk.harga); fflush(stdin);
	printf("Tunggu Sebentar...\n");
	fprintf(SOUVENIR,"%s_%i_%i_%i\n", Produk.nama, Produk.no, Produk.jmlh, Produk.harga);
	printf("Selamat! Produk sudah berhasil ditambahkan.\n");
	fclose(SOUVENIR);
}

void daftar_souvenir(){
	Souvenir Produk;
    SOUVENIR = fopen("souvenir.txt", "r");
	printf("========================================================================================\n");
    printf("No \t"); 
	printf("Nama \t\t\t");
    printf("Jumlah \t");
	printf("Harga ");
    printf("\n======================================================================================\n");
	while (!feof(SOUVENIR)){
    fscanf(SOUVENIR,"%[^_]_%i_%i_%i\n", &Produk.nama, &Produk.no, &Produk.jmlh, &Produk.harga);
		fflush(stdin);
			printf("|%-2i| \t", Produk.no); 
			printf("|%-30s|", Produk.nama);
			printf("|%-4i|", Produk.jmlh);
			printf("|%-10i| \n", Produk.harga);
        }
    fclose(SOUVENIR);
}