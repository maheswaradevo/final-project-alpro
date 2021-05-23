#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char nama[50];
    int usia;
    char alamat[100];
    char penyakit[100];
    int harga;
    int saldo;
    int tinggi;
}tiket;



int main(){
  tiket data[50];
  int i, pilihan, exit, awal;
  int j;
  int pil1,pil2=0,pil3,pil4,pil5,pil6,pil7,pil8;
  int tarif;
  char konfirmasi[2];
  awal :
system ("cls");
printf ("========================\n");
printf ("selamat datang di Wahana\n");
printf ("========================\n");
printf ("    silahkan pilih menu\n");
printf ("    1.REGISTRASI\n");
printf ("    2.Pilih Wahana\n");
printf ("    3.Exit\n");
printf ("masukkan pilihan anda : ");
scanf  ("%d", &pilihan);

switch(pilihan){
    case 1 :
    break;

    case 2:
    system ("cls");
    printf("==============================================\n");
    printf("=================Menu wahana==================\n");
    printf("==============================================\n");
    printf("apakah anda ingin melihat rekomendasi wahana?\n");
    printf("                   1.Iya                     \n");
    printf("                   2.tidak                   \n");
    printf("==============================================\n");
    printf(" masukkan pilihan anda :");
    scanf("%d", &pil1);
    if (pil1==1){
      if(data[j].usia>=18 || strcmp(data[j].penyakit, "asma") == 1 || strcmp(data[j].penyakit, "jantung") == 1 || data[j].tinggi>=140 ){
         printf("Wahana selain rolloer coaster bisa anda naiki");} 

      else if(data[j].usia>=14 || strcmp(data[j].penyakit, "hipertensi") == 1 || strcmp(data[j].penyakit, "jantung") == 1 ){
         printf("wahana biang lala bisa anda naiki");}

      else if(data[j].usia>=16 || strcmp(data[j].penyakit, "jantung") == 1 || data[j].tinggi>= 150 || strcmp(data[j].penyakit, "hipertensi" ) == 1 ){
         printf("wahana sky swinger bisa anda naiki");}

      else if(data[j].usia>=10 || strcmp(data[j].penyakit, "jantung") == 1 ){
         printf("wahana bom bom car bisa anda naiki");}

      else if(data[j].usia>=10 || strcmp(data[j].penyakit, "jantung") == 1 ){
         printf("wahana rumah hantu bisa anda naiki");}

      else if(data[j].usia>=10 || strcmp(data[j].penyakit, "jantung") == 1 || strcmp(data[j].penyakit, "anemia") == 1 || data[j].tinggi>=130){
         printf("wahana ACCELERATOR bisa anda naiki");
       }
    }
    else if (pil1==2){
     system ("cls");

     printf("=========wahana pada taman hiburan===========\n");
     printf("====silahkan pilih wahana sesuai keinginan====\n");
     printf("                  1.roller coaster\n");
     printf("                  2.Biang Lala\n");
     printf("                  3.Sky Swinger\n");
     printf("                  4.BOM-BOM CAR\n");
     printf("                  5.RUMAH HANTU\n");
     printf("                  6.ACCELERATOR\n");
     printf("=============================================\n");
     printf("                  1.roller coaster  | tarif Rp.10000\n");
     printf("                  2.Biang Lala      | tarif Rp.8000\n");
     printf("                  3.Sky Swinger     | tarif Rp.5000\n");
     printf("                  4.BOM-BOM CAR     | tarif Rp.4000\n");
     printf("                  5.RUMAH HANTU     | tarif Rp.7000\n");
     printf("                  6.ACCELERATOR     | tarif Rp.10000\n");
     printf("silahkan masukan pilihan anda :");
     scanf("%d",&pil2);
     switch(pil2){
     case 1:
       if(data[j].usia<18 || strcmp(data[j].penyakit, "asma") == 0 || strcmp(data[j].penyakit, "jantung") == 0 || data[j].tinggi<140 ){
         printf("wahana tidak sesuai dengan kriteria anda");
       }else {
         printf("=============================\n");
         printf("wahana ini cocok untuk anda\n");
         printf("=============================\n");
         printf("apakah anda ingin di wahana Roller coaster? \n\t1.Iya\n\t2.Tidak\nmasukkan pilihan :");
         scanf("%d", &pil3);
           if (pil3==1){
                tarif = 10000;
               if(data[j].saldo > tarif || data[j].saldo == tarif ){
                 data[j].saldo= data[j].saldo-tarif;
                 printf("\n===silahkan bermain di wahana ini===\n");
                 printf("\nsaldo saat ini Rp.%d", data[j].saldo);
               }else{
                printf("saldo tidak cukup");}
          }else if (pil3==2){
            printf("pemilihan wahana dibatalkan");
                }
           else {
            printf("inputan salah");
                }
           goto konfirmasi;
       }
     break;
     case 2:
        if(data[j].usia<14 || strcmp(data[j].penyakit, "hipertensi") == 0 || strcmp(data[j].penyakit, "jantung") == 0 ){
         printf("wahana tidak sesuai dengan kriteria anda");
       }else {
         printf("=============================\n");
         printf("wahana ini cocok untuk anda\n");
         printf("=============================\n");
         printf("apakah anda ingin Bermain di wahana BIANG LALA? \n\t1.Iya\n\t2.Tidak\nmasukkan pilihan :");
         scanf("%d", &pil4);
           if (pil4==1){
                tarif = 8000;
               if(data[j].saldo > tarif || data[j].saldo == tarif ){
                 data[j].saldo= data[j].saldo-tarif;
                 printf("\n===silahkan bermain di wahana ini===\n");
                 printf("\nsaldo saat ini Rp.%d", data[j].saldo);
               }else{
                printf("saldo tidak cukup");}
          }else if (pil4==2){
            printf("pemilihan wahana dibatalkan");
                }
           else {
            printf("inputan salah");
                }
           goto konfirmasi;
       }
     break;
     case 3:
        if(data[j].usia<16 || strcmp(data[j].penyakit, "jantung") == 0 || data[j].tinggi< 150 || strcmp(data[j].penyakit, "hipertensi" ) == 0 ){
         printf("wahana tidak sesuai dengan kriteria anda");
       }else {
         printf("=============================\n");
         printf("wahana ini cocok untuk anda\n");
         printf("=============================\n");
         printf("apakah anda ingin bermain di wahana Sky Swinger? \n\t1.Iya\n\t2.Tidak\nmasukkan pilihan :");
         scanf("%d", &pil5);
           if (pil5==1){
                tarif = 5000;
               if(data[j].saldo > tarif || data[j].saldo == tarif ){
                 data[j].saldo= data[j].saldo-tarif;
                 printf("\n===silahkan bermain di wahana ini===\n");
                 printf("\nsaldo saat ini Rp.%d", data[j].saldo);
               }else{
                printf("saldo tidak cukup");}
          }else if (pil5==2){
            printf("pemilihan wahana dibatalkan");
                }
           else {
            printf("inputan salah");
                }
           goto konfirmasi;
       }
     break;
     case 4:
        if(data[j].usia<10 || strcmp(data[j].penyakit, "jantung") == 0 ){
         printf("wahana tidak sesuai dengan kriteria anda");
       }else {
         printf("=============================\n");
         printf("wahana ini cocok untuk anda\n");
         printf("=============================\n");
         printf("apakah anda ingin bermain di wahana BOM-BOM CAR? \n\t1.Iya\n\t2.Tidak\nmasukkan pilihan :");
         scanf("%d", &pil6);
           if (pil6==1){
                tarif = 4000;
               if(data[j].saldo > tarif || data[j].saldo == tarif ){
                 data[j].saldo= data[j].saldo-tarif;
                 printf("\n===silahkan bermain di wahana ini===\n");
                 printf("\nsaldo saat ini Rp.%d", data[j].saldo);
               }else{
                printf("saldo tidak cukup");}
          }else if (pil6==2){
            printf("pemilihan wahana dibatalkan");
                }
           else {
            printf("inputan salah");
                }
         goto konfirmasi;
       }
     break;
     case 5:
        if(data[j].usia<10 || strcmp(data[j].penyakit, "jantung") == 0 ){
         printf("wahana tidak sesuai dengan kriteria anda");
       }else {
         printf("=============================\n");
         printf("wahana ini cocok untuk anda\n");
         printf("=============================\n");
         printf("apakah anda ingin bermain di wahana RUMAH HANTU? \n\t1.Iya\n\t2.Tidak\nmasukkan pilihan :");
         scanf("%d", &pil7);
           if (pil7==1){
                tarif = 7000;
               if(data[j].saldo > tarif || data[j].saldo == tarif ){
                 data[j].saldo= data[j].saldo-tarif;
                 printf("\n===silahkan bermain di wahana ini===\n");
                 printf("\nsaldo saat ini Rp.%d", data[j].saldo);
               }else{
                printf("saldo tidak cukup");}
          }else if (pil7==2){
            printf("pemilihan wahana dibatalkan");
                }
           else {
            printf("inputan salah");
                }
         goto konfirmasi;
       }
     break;
     case 6:
        if(data[j].usia<10 || strcmp(data[j].penyakit, "jantung") == 0 || strcmp(data[j].penyakit, "anemia") == 0 || data[j].tinggi<130){
         printf("wahana tidak sesuai dengan kriteria anda");
       }else {
         printf("=============================\n");
         printf("wahana ini cocok untuk anda\n");
         printf("=============================\n");
         printf("apakah anda ingin bermain di wahana ACCELERATOR? \n\t1.Iya\n\t2.Tidak\nmasukkan pilihan :");
         scanf("%d", &pil8);
           if (pil8==1){
                tarif = 10000;
               if(data[j].saldo > tarif || data[j].saldo == tarif ){
                 data[j].saldo= data[j].saldo-tarif;
                 printf("\n===silahkan bermain di wahana ini===\n");
                 printf("\nsaldo saat ini Rp.%d", data[j].saldo);
               }else{
                printf("saldo tidak cukup");}
          }else if (pil8==2){
            printf("pemilihan wahana dibatalkan");
                }
           else {
            printf("inputan salah");
                }
         goto konfirmasi;
       }
     break;
     default: printf("pilihan anda salah");
     }

    }else{
     printf("pilihan salah\n");
    }
    break;

    case 3:
     goto exit;
    break;
    default : printf("Pilihan anda salah");

}
    konfirmasi:

    printf("\nApakah anda ingin  kembali ke menu ? Y/T : ");

    scanf("%s",&konfirmasi);

    if(strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0){

        goto awal;

    }else if(strcmp(konfirmasi, "T") == 0 || strcmp(konfirmasi, "t") == 0){

        goto exit;
    exit:
        system("cls");
        printf("================================");
        printf("\n       Terimakasih ");
        printf("\n================================\n");

         }else{

    printf("\nPilihan salah");

        goto konfirmasi;

         }

return 0;
}



