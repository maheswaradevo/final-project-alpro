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
				//daftar_souvenir();
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
				//tambah_souvenir();
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

