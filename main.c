#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[50][50];
int umur;
char penyakit[50][50];
int tb;

int ageCount(int tgl_lahir, int bln_lahir, int thn_lahir)
{   int bulan[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tgl_skrg = 5;
    int bln_skrg = 5;
    int thn_skrg = 2021;
    if(tgl_lahir > tgl_skrg){
        tgl_skrg = tgl_skrg + bulan[bln_lahir - 1];
        bln_skrg = bln_skrg - 1;
    }
    if(bln_lahir > bln_skrg){
        thn_skrg = thn_skrg -1;
        bln_skrg = bln_skrg + 12;
    }
    int tgl_final = tgl_skrg - tgl_lahir;
    int bln_final = bln_skrg - bln_lahir;
    umur = thn_skrg - thn_lahir;
    return 0;
}
void identity()
{
    char name[50][50];
    int choice, tgl, bln, thn, n, i;
    char penyakit[50][50];
    int j=0;
    printf("MASUKKAN NAMA ANDA : ");
    scanf("%[^\n]s", &name);
    printf("MASUKKAN TANGGAL LAHIR ANDA : ");
    scanf("%d %d %d", &tgl, &bln, &thn);
    ageCount(tgl, bln, thn);
    fflush(stdin);
    printf("APAKAH MEMILIKI RIWAYAT PENYAKIT? (Y/N) : ");
    scanf("%s", &choice);
    switch(choice){
        case 'Y':
        fflush(stdin);
            printf("BERAPA BANYAK PENYAKIT YANG DIDERITA : ");
            scanf("%d", &n);
            fflush(stdin);
            for(i = 0; i<n; i++){
                printf("-");
                fflush(stdin);
                scanf("%[^\n]s", &penyakit);
            }
            printf("TINGGI BADAN ANDA (CM) : ");
            scanf("%d", &tb);
        break;
        case 'N':
            printf("TINGGI BADAN ANDA (CM) : ");
            scanf("%d", &tb);
        break;
    }
}
void game()
{
    if((umur >= 17)&&(tb>170)){
        printf("ANDA DAPAT MEMAINKAN PERMAINAN DIBAWAH INI : \n");
        printf("1. ROLLER COASTER\n");
        printf("2. BIANG LALA\n");
        printf("3. SKY SWINGER\n");
        printf("4. BOM-BOM CAR\n");
        printf("5. RUMAH HANTU\n");
        printf("6. ACCELERATOR\n");
    }
    else if((umur >= 12)&&(umur < 17)&&(tb <= 170)&&(tb > 160)){
        printf("1. BOM-BOM CAR\n");
        printf("2. RUMAH HANTU\n");
        printf("3. ACCELERATOR\n");
        printf("4. ROLLER COASTER MINI\n");
    }
    else if ((umur < 12) && (tb <= 160)){
        printf("UNTUK ANAK UMUR DIBAWAH 11 TAHUN\n");
        printf("DIMOHON DIDAMPINGIN ORANG TUA\n");
        printf("1. SAFARI CAR\n");
        printf("2. KOMEDI PUTAR\n");
        printf("3. ROLLER COASTER MINI\n");
    }
    
}

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
    int i, choice;
    int result;
    element data[50];
    FILE *fp;
    int jam, mnt, dtk;
    char name[50];
    while(1){
        printf("\n1. MASUKKAN IDENTITAS ANDA\n");
        printf("2. REKOMENDASI PERMAINAN\n");
        printf("5. HITUNG PARKIR\n");
        printf("6. Exit\n");
        printf("MASUKKAN PILIHAN : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                fflush(stdin);
                identity();
            break;
            case 2:
                game();
            break;
            case 5:
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
                printf("MASUKKAN PILIHAN : ");
                scanf("%d", &choice);
                switch(choice){
                    case 1:
                    printf("\nMASUKKAN BERAPA LAMA PELANGGAN BERADA DI LOKASI (H/M/S) : ");
                    scanf("%d %d %d", &jam, &mnt, &dtk);
                    printf("WAKTU PELANGGAN DI LOKASI : %d JAM %d MENIT %d DETIK\n", jam, mnt, dtk);
                    costCountA(data[0].price, jam);
                    break;
                    case 2:
                    printf("\nMASUKKAN BERAPA LAMA PELANGGAN BERADA DI LOKASI (H/M/S) : ");
                    scanf("%d %d %d", &jam, &mnt, &dtk);
                    printf("WAKTU PELANGGAN DI LOKASI : %d JAM %d MENIT %d DETIK", jam, mnt, dtk);
                    costCountB(data[1].price, jam);
                    break;
                }
            break;
            case 6:
                exit(1);
            break;
        }
    }
    return 0;
}