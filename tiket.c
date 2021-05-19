#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nama;
    int usia;
    char alamat;
    char penyakit;
    int harga;
    int saldo;
}tiket;

void Registrasi(){



}

void wahana(){

}

int main(){
  tiket data[50];
  int i=0, pilihan, exit, awal;
  char konfirmasi[2];
  awal :
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
    Registrasi();
    break;

    case 2:
    wahana();
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


