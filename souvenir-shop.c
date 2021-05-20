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
		system("cls");
        printf("===================================================================\n");
        printf("===========================SOUVENIR SHOP===========================\n");
        printf("===================================================================\n");
        printf("~MENU~ \t: \n");
		printf("1. Daftar Souvenir \n2. Cari Souvenir \n3. Pembelian \n4. Tambah Souvenir (Admin) \n5. Daftar Pembelian (Admin) \n6. Update (Admin) \n7. Keluar \n");
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
				cari();
				break;
			case '3':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            	 Pembelian                             |\n");
				printf("|______________________________________________________________________|\n");
				pembelian();
				break;
			case '4':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Tambah Souvenir                           |\n");
				printf("|______________________________________________________________________|\n");
				tambah_souvenir();
				break;
			case '5':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Daftar Pembelian                           |\n");
				printf("|______________________________________________________________________|\n");
				//pembelian();
				break;
			case '6':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                                 Update                               |\n");
				printf("|______________________________________________________________________|\n");
				//update_stock();
				break;
			case '7':
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
	printf("======================================================================================\n");
    printf("No \t"); 
	printf("Nama \t\t\t\t");
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

void cari(){
	char cari[50];
	Souvenir Produk;
    SOUVENIR = fopen("souvenir.txt", "r");
	printf("Masukan Nama Produk yang ingin dicari \t: "); scanf("%s",&cari); fflush(stdin);
	while (!feof(SOUVENIR)){
    	fscanf(SOUVENIR,"%[^_]_%i_%i_%i\n", &Produk.nama, &Produk.no, &Produk.jmlh, &Produk.harga);
		fflush(stdin);
		if(strcmp(cari,Produk.nama)==0){
			printf("Nama Produk \t\t: %s\n", Produk.nama);
			printf("No Produk \t\t: %i\n", Produk.no);
            printf("Jumlah Produk \t\t: %i\n", Produk.jmlh);
            printf("Harga Produk \t\t: %i\n", Produk.harga);
        }
    }
    fclose(SOUVENIR);
}

void pembelian(){
	Souvenir Produk_beli[20];
	time_t now;
	time (&now);
	int nomor;
	int index, i;
	SOUVENIR = fopen("souvenir.txt", "r+");
	printf("\t===Pilih produk yang akan anda beli===\n");
	printf("Masukkan nomor produk : \n");
	scanf("%i", &nomor);
	while (!feof(SOUVENIR)){
    	fscanf(SOUVENIR,"%[^_]_%i_%i_%i\n", &Produk_beli[index].nama, &Produk_beli[index].no, &Produk_beli[index].jmlh, &Produk_beli[index].harga);
		fflush(stdin);
		printf("Nama Produk \t\t: %s\n", Produk_beli[index].nama);
		printf("No Produk \t\t: %i\n", Produk_beli[index].no);
        printf("Jumlah Produk \t\t: %i\n", Produk_beli[index].jmlh);
        printf("Harga Produk \t\t: %i\n", Produk_beli[index].harga);
		if(nomor == Produk_beli[index].no){
			if(Produk_beli[index].no > 1){
				printf("======================Souvenir Berhasil Dibeli===============\n");
					Produk_beli[index].jmlh -= 1;
			}
			else{
				printf("======================Souvenir Tidak Berhasil Dibeli===============\n");
			}
		}
		index++;
	}
	fclose(SOUVENIR);
	SOUVENIR = fopen("souvenir.txt","w");
	fclose(SOUVENIR);
	SOUVENIR = fopen("souvenir.txt","a");
	for(i=0; i<index; i++){
		fprintf(SOUVENIR,"%s_%i_%i_%i\n", Produk_beli[i].nama, Produk_beli[i].no, Produk_beli[i].jmlh, Produk_beli[i].harga);
	}
	fclose(SOUVENIR);
}