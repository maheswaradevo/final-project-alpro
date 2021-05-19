#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu();
void cari();
void pembelian();
void daftar_souvenir();
void tambah_souvenir();

typedef struct{
    char nama[50];
    int no;
    int jmlh;
    int harga;
}Souvenir;


int main(){
    printf("Hello World");

    return 0;
}

