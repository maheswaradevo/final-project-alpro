#include<stdio.h>

typedef struct {
    char type[20];
    int price;
}element;

int costCountA(int mobil, int jam)
{
    int result;
    result = jam * mobil;
    printf("HARGA PARKIR = %d", result);
    return 0;
}
int costCountB(int motor, int jam)
{
    int result;
    result = jam * motor;
    printf("HARGA PARKIR = %d", result);
    return 0;
}

int main()
{
    int result;
    element data[50];
    FILE *fp;
    int jam, mnt, dtk, i=0, choice;
    fp = fopen("parkir.txt", "r");
    if(fp == NULL){
        printf("Tidak ada file yang ditemukan!");
    }
    while(!feof(fp)){
        fscanf(fp, "%s %d", &data[i].type, &data[i].price);
        i++;
    }
    printf("PEMBAYARAN MOBIL PERJAM = %d\n", data[0].price);
    printf("PEMBAYARAN MOTOR PERJAM = %d\n", data[1].price);
    printf("KENDARAAN PELANGGAN : \n");
    printf("1. MOBIL\n");
    printf("2. MOTOR\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        printf("\nMASUKKAN BERAPA LAMA PELANGGAN BERADA DI LOKASI (H/M/S) : ");
        scanf("%d %d %d", &jam, &mnt, &dtk);
        printf("WAKTU PELANGGAN DI LOKASI : %d JAM %d MENIT %d DETIK", jam, mnt, dtk);
        costCountA(data[0].price, jam);
        break;
        case 2:
        printf("\nMASUKKAN BERAPA LAMA PELANGGAN BERADA DI LOKASI (H/M/S) : ");
        scanf("%d %d %d", &jam, &mnt, &dtk);
        printf("WAKTU PELANGGAN DI LOKASI : %d JAM %d MENIT %d DETIK", jam, mnt, dtk);
        costCountB(data[1].price, jam);
        break;
    }
    return 0;
}