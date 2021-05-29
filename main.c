#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct data
{
    char nama[50], alamat[50], penyakit[50];
    int usia, tb;
    int harga, saldo;
} data;
data identitas[20];

typedef struct
{
    char type[20];
    int price;
} element;

typedef struct
{
    char nama[50];
    int no;
    int jmlh;
    int harga;
} Souvenir;

FILE *SOUVENIR;
FILE *PEMBELIAN;

int ageCount(int tgl_lahir, int bln_lahir, int thn_lahir)
{
    int j = 0;
    int bulan[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tgl_skrg = 5;
    int bln_skrg = 5;
    int thn_skrg = 2021;
    if (tgl_lahir > tgl_skrg)
    {
        tgl_skrg = tgl_skrg + bulan[bln_lahir - 1];
        bln_skrg = bln_skrg - 1;
    }
    if (bln_lahir > bln_skrg)
    {
        thn_skrg = thn_skrg - 1;
        bln_skrg = bln_skrg + 12;
    }
    int tgl_final = tgl_skrg - tgl_lahir;
    int bln_final = bln_skrg - bln_lahir;
    identitas[j].usia = thn_skrg - thn_lahir;
    j++;
    return 0;
}
void identity()
{
    int choice, tgl, bln, thn, n, i;
    int j = 0;
    printf("MASUKKAN NAMA ANDA : ");
    fflush(stdin);
    scanf("%[^\n]s", &identitas[j].nama);
    printf("MASUKKAN TANGGAL LAHIR ANDA : ");
    scanf("%d %d %d", &tgl, &bln, &thn);
    ageCount(tgl, bln, thn);
    fflush(stdin);
    printf("APAKAH MEMILIKI RIWAYAT PENYAKIT? (Y/N) : ");
    scanf("%s", &choice);
    switch (choice)
    {
    case 'Y':
        fflush(stdin);
        printf("BERAPA BANYAK PENYAKIT YANG DIDERITA : ");
        scanf("%d", &n);
        fflush(stdin);
        for (i = 0; i < n; i++)
        {
            printf("-");
            fflush(stdin);
            scanf("%[^\n]s", &identitas[j].penyakit);
        }
        printf("TINGGI BADAN ANDA (CM) : ");
        scanf("%d", &identitas[j].tb);
        break;
    case 'N':
        printf("TINGGI BADAN ANDA (CM) : ");
        scanf("%d", &identitas[j].tb);
        break;
    }
    j++;
}

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
void tambah_souvenir()
{
    Souvenir Produk;
    SOUVENIR = fopen("souvenir.txt", "a+");
    int code;
    printf("UNTUK MELAKUKAN OPERASI INI ANDA HARUS MEMASUKKAN KODE ADMIN!\n");
    printf("MASUKKAN KODE DISINI : ");
    scanf("%i", &code);
    fflush(stdin);
    if (code == 61105)
    {
        printf("NAMA PRODUK \t\t: ");
        scanf("%[^\n]", &Produk.nama);
        fflush(stdin);
        printf("NO PRODUK \t\t: ");
        scanf("%i", &Produk.no);
        fflush(stdin);
        printf("JUMLAH PRODUK \t\t: ");
        scanf("%i", &Produk.jmlh);
        fflush(stdin);
        printf("HARGA PRODUK \t\t: ");
        scanf("%i", &Produk.harga);
        fflush(stdin);

        fprintf(SOUVENIR, "%s_%i_%i_%i\n", Produk.nama, Produk.no, Produk.jmlh, Produk.harga);
        printf("SELAMAT! PRODUK SUDAH BERHASIL DITAMBAHKAN\n");
    }
    else
        printf("KODE YANG ANDA MASUKKAN SALAH!!!");
    fclose(SOUVENIR);
}
void daftar_souvenir()
{
    Souvenir Produk;
    SOUVENIR = fopen("souvenir.txt", "r");
    printf("========================================================================================\n");
    printf("NO \t");
    printf("NAMA \t\t\t\t");
    printf("JUMLAH \t");
    printf("HARGA ");
    printf("\n======================================================================================\n");
    while (!feof(SOUVENIR))
    {
        fscanf(SOUVENIR, "%[^_]_%i_%i_%i\n", &Produk.nama, &Produk.no, &Produk.jmlh, &Produk.harga);
        fflush(stdin);
        printf("|%-2i| \t", Produk.no);
        printf("|%-30s|", Produk.nama);
        printf("|%-4i|", Produk.jmlh);
        printf("|%-10i| \n", Produk.harga);
    }
    fclose(SOUVENIR);
}
void cari()
{
    char cari[50];
    Souvenir Produk;
    SOUVENIR = fopen("souvenir.txt", "r");
    printf("MASUKKAN PRODUK YANG INGIN DICARI \t: ");
    scanf("%s", &cari);
    fflush(stdin);
    while (!feof(SOUVENIR))
    {
        fscanf(SOUVENIR, "%[^_]_%i_%i_%i\n", &Produk.nama, &Produk.no, &Produk.jmlh, &Produk.harga);
        fflush(stdin);
        if (strcmp(cari, Produk.nama) == 0)
        {
            printf("NAMA PRODUK \t\t: %s\n", Produk.nama);
            printf("NO PRODUK \t\t: %i\n", Produk.no);
            printf("JUMLAH PRODUK \t\t: %i\n", Produk.jmlh);
            printf("HARGA PRODUK \t\t: %i\n", Produk.harga);
        }
    }
    if (strcmp(cari, Produk.nama) != 0)
    {
        printf("SOUVENIR TERSEBUT BELUM TERSEDIA\n");
    }
    fclose(SOUVENIR);
}

void pembelian()
{
    Souvenir Produk[20];
    time_t now;
    time(&now);
    char c;
    int nomor;
    int index, i, uang, kembalian;
    index = 0;
    daftar_souvenir();
    SOUVENIR = fopen("souvenir.txt", "r+");
    printf("\t===PILIH PRODUK YANG INGIN ANDA BELI===\n");
    printf("MASUKKAN NOMOR PRODUK : ");
    scanf("%i", &nomor);
    fflush(stdin);
    printf("MASUKKAN NOMINAL UANG YANG DIBERIKAN : ");
    scanf("%i", &uang);
    while (!feof(SOUVENIR))
    {
        fscanf(SOUVENIR, "%[^_]_%i_%i_%i\n", &Produk[index].nama, &Produk[index].no, &Produk[index].jmlh, &Produk[index].harga);
        fflush(stdin);
        if (nomor == Produk[index].no)
        {
            if (uang >= Produk[index].harga)
            {
                kembalian = uang - Produk[index].harga;
                if (Produk[index].jmlh >= 1)
                {
                    printf("======================SOUVENIR BERHASIL DIBELI===============\n");
                    Produk[index].jmlh -= 1;
                    PEMBELIAN = fopen("pembelian.txt", "a");
                    fprintf(PEMBELIAN, "%s_%i_%i_%i\n", Produk[index].nama, Produk[index].no, 1, Produk[index].harga);
                    fclose(PEMBELIAN);
                    printf("ANDA INGIN MENCETAK STRUK?(Y/N)");
                    scanf("%c", &c);
                    if (c == 'y' || c == 'Y')
                    {
                        system("cls");
                        PEMBELIAN = fopen("pembelian.txt", "r");
                        printf("Tanggal pembelian : %s", ctime(&now));
                        printf("======================STRUK BUKTI PEMBELIAN===============\n");
                        printf("Nama Produk \t\t: %s\n", Produk[index].nama);
                        printf("No Produk \t\t: %i\n", Produk[index].no);
                        printf("Jumlah Produk \t\t: %i\n", 1);
                        printf("Harga Produk \t\t: %i\n", Produk[index].harga);
                        printf("Tunai \t\t\t: %i\n", uang);
                        printf("Kembali \t\t\t: %i\n", kembalian);
                        printf("Terima Kasih telah berbelanja.\n");
                        printf("===========================================================\n");
                        fclose(PEMBELIAN);
                    }
                }
                else
                    printf("======================SOUVENIR TIDAK BERHASIL DIBELI===============\n");
            }
            else
                printf("UANG ANDA KURANG UNTUK MEMBELI PRODUK INI!!!\n");
        }
        index++;
    }
    fclose(SOUVENIR);
    SOUVENIR = fopen("souvenir.txt", "w");
    fclose(SOUVENIR);
    SOUVENIR = fopen("souvenir.txt", "a");
    for (i = 0; i < index; i++)
    {
        fprintf(SOUVENIR, "%s_%i_%i_%i\n", Produk[i].nama, Produk[i].no, Produk[i].jmlh, Produk[i].harga);
    }
    fclose(SOUVENIR);
}

void update_stock()
{
    Souvenir Produk[20];
    char cari[50];
    int index, i, jmlh;
    index = 0;
    int code;
    printf("UNTUK MELAKUKAN OPERASI INI ANDA HARUS MEMASUKKAN KODE ADMIN\n");
    printf("MASUKKAN KODE DISINI : ");
    scanf("%i", &code);
    fflush(stdin);
    if (code == 61105)
    {
        daftar_souvenir();
        SOUVENIR = fopen("souvenir.txt", "r+");
        printf("MASUKKAN NAMA PRODUK YANG INGIN ANDA UPDATE \t: ");
        scanf("%s", &cari);
        fflush(stdin);
        while (!feof(SOUVENIR))
        {
            fscanf(SOUVENIR, "%[^_]_%i_%i_%i\n", &Produk[index].nama, &Produk[index].no, &Produk[index].jmlh, &Produk[index].harga);
            fflush(stdin);
            if (strcmp(cari, Produk[index].nama) == 0)
            {
                printf("Nama Produk \t\t: %s\n", Produk[index].nama);
                printf("No Produk \t\t: %i\n", Produk[index].no);
                printf("Jumlah Produk \t\t: %i\n", Produk[index].jmlh);
                printf("Harga Produk \t\t: %i\n\n", Produk[index].harga);
                printf("MASUKKAN JUMLAH PRODUK YANG INGIN ANDA UBAH : ");
                scanf("%i", &jmlh);
                printf("Tunggu Sebentar...\n");
                Produk[index].jmlh = jmlh;
                printf("SELAMAT! PRODUK SUDAH BERHASIL DIUBAH.\n");
            }
            index++;
        }
        fclose(SOUVENIR);
        SOUVENIR = fopen("souvenir.txt", "w");
        fclose(SOUVENIR);
        SOUVENIR = fopen("souvenir.txt", "a");
        for (i = 0; i < index; i++)
        {
            fprintf(SOUVENIR, "%s_%i_%i_%i\n", Produk[i].nama, Produk[i].no, Produk[i].jmlh, Produk[i].harga);
        }
    }
    else
        printf("KODE YANG ANDA MASUKKAN SALAH!!!");
    fclose(SOUVENIR);
}
void title();
void nama();

int main()
{
    data tiket[20];
    element data[50];
    int i, j, choice, ch, keluar, awal, menu;
    int result;
    FILE *fp;
    int jam, mnt, dtk;
    char name[50];
    char pilihan;
    char ulangi = 'y';
    int pil1, pil2 = 0, pil3, pil4, pil5, pil6, pil7, pil8;
    int tarif;
    int counter = 0;
    char konfirmasi[2];
    int admin;
    int hcotton_candy, hsausage, hFrench_fries, hpopcorn, hpop_ice, hsoft_drink, hjuice;
    int total, total2, total3, bayar, kembali, makanan, minuman, pilih, ulang, drink;
    hcotton_candy = 25000;
    hsausage = 20000;
    hFrench_fries = 30000;
    hpopcorn = 35000;
    hpop_ice = 20000;
    hsoft_drink = 15000;
    hjuice = 20000;
    title();
    nama();
    while (1)
    {
        printf("\n1. MASUKKAN IDENTITAS ANDA\n");
        printf("2. TIKET\n");
        printf("3. SOUVENIR\n");
        printf("4. TOKO MAKANAN\n");
        printf("5. HITUNG PARKIR (ADMIN)\n");
        printf("6. Exit\n");
        printf("MASUKKAN PILIHAN : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            identity();
            tiket[counter].usia = identitas[counter].usia;
            tiket[counter].tb = identitas[counter].tb;
            strcpy(tiket[counter].penyakit, identitas[counter].penyakit);
            counter++;
            break;
        case 2:
        awal:
            system("cls");
            printf("========================\n");
            printf("SELAMAT DATANG DI WAHANA\n");
            printf("========================\n");
            printf("    SILAHKAN PILIH MENU\n");
            printf("    1.ISI SALDO\n");
            printf("    2.PILIH WAHANA\n");
            printf("    3.EXIT\n");
            printf("MASUKKAN PILIHAN ANDA : ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("silahkan masukkan saldo :Rp.");
                scanf("%d", &tiket[j].saldo);
                printf("=============================\n");
                printf("   Saldo telah diisi\n");
                printf("=============================\n");
                break;

            case 2:
                system("cls");
                printf("==============================================\n");
                printf("=================MENU WAHANA==================\n");
                printf("==============================================\n");
                printf("APAKAH ANDA INGIN MELIHAT REKOMENDASI WAHANA? \n");
                printf("                   1.IYA                     \n");
                printf("                   2.TIDAK                   \n");
                printf("==============================================\n");
                printf(" MASUKKAN PILIHAN ANDA :");
                scanf("%d", &pil1);
                if (pil1 == 1)
                {
                    if (tiket[j].usia >= 18 || strcmp(tiket[j].penyakit, "asma") == 1 || strcmp(tiket[j].penyakit, "jantung") == 1 || tiket[j].tb >= 140)
                    {
                        printf("WAHANA ROLLLER COASTER BISA ANDA NAIKI\n");
                        printf("APAKAH ANDA INGIN MENAIKI WAHANA INI? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN ANDA :");
                        scanf("%d", &pil3);
                        if (pil3 == 1)
                        {
                            tarif = 10000;
                            if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                            {
                                tiket[j].saldo = tiket[j].saldo - tarif;
                                printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                printf("\nSALDO ANDA SAAT INI Rp.%d\n", tiket[j].saldo);
                            }
                            else
                            {
                                printf("SALDO TIDAK CUKUP\n");
                            }
                        }
                        else if (pil3 == 2)
                        {
                            printf("PEMILIHAN WAHANA DIBATALKAN\n");
                        }
                        else
                        {
                            printf("INPUTAN SALAH\n");
                        }
                        goto konfirmasi;
                    }

                    else if (tiket[j].usia >= 14 || strcmp(tiket[j].penyakit, "hipertensi") == 1 || strcmp(tiket[j].penyakit, "jantung") == 1)
                    {
                        printf("WAHANA BIANG LALA BISA ANDA NAIKI\n");
                        printf("APAKAH ANDA INGIN BERMAIN DI WAHANA BIANG LALA? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN ANDA :");
                        scanf("%d", &pil4);
                        if (pil4 == 1)
                        {
                            tarif = 8000;
                            if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                            {
                                tiket[j].saldo = tiket[j].saldo - tarif;
                                printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                printf("\nSALDO ANDA SAAT INI Rp.%d\n", tiket[j].saldo);
                            }
                            else
                            {
                                printf("SALDO TIDAK CUKUP\n");
                            }
                        }
                        else if (pil4 == 2)
                        {
                            printf("PEMILIHAN WAHANA DIBATALKAN\n");
                        }
                        else
                        {
                            printf("INPUTAN SALAH\n");
                        }
                        goto konfirmasi;
                    }

                    else if (tiket[j].usia >= 16 || strcmp(tiket[j].penyakit, "jantung") == 1 || tiket[j].tb >= 150 || strcmp(tiket[j].penyakit, "hipertensi") == 1)
                    {
                        printf("WAHANA SKY SWINGER DAPAT ANDA NAIKI\n");
                        printf("APAKAH ANDA INGIN BERMAIN DI WAHANA SKY SWINGER? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIAN :");
                        scanf("%d", &pil5);
                        if (pil5 == 1)
                        {
                            tarif = 5000;
                            if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                            {
                                tiket[j].saldo = tiket[j].saldo - tarif;
                                printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                printf("\nSALDO ANDA SAAT INI Rp.%d\n", tiket[j].saldo);
                            }
                            else
                            {
                                printf("SALDO TIDAK CUKUP\n");
                            }
                        }
                        else if (pil5 == 2)
                        {
                            printf("PEMILIHAN WAHANA DIBATALKAN\n");
                        }
                        else
                        {
                            printf("INPUTAN SALAH\n");
                        }
                        goto konfirmasi;
                    }

                    else if (tiket[j].usia >= 10 || strcmp(tiket[j].penyakit, "jantung") == 1)
                    {
                        printf("WAHANA BOM-BOM CAR DAPAT ANDA NAIKI\n");
                        printf("APAKAH ANDA INGIN BERMAIN DI WAHANA BOM-BOM CAR? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                        scanf("%d", &pil6);
                        if (pil6 == 1)
                        {
                            tarif = 4000;
                            if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                            {
                                tiket[j].saldo = tiket[j].saldo - tarif;
                                printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                printf("\nSALDO ANDA SAAT INI Rp.%d\n", tiket[j].saldo);
                            }
                            else
                            {
                                printf("SALDO TIDAK CUKUP\n");
                            }
                        }
                        else if (pil6 == 2)
                        {
                            printf("PEMILIHAN WAHANA DIBATALKAN\n");
                        }
                        else
                        {
                            printf("INPUTAN SALAH\n");
                        }
                        goto konfirmasi;
                    }

                    else if (tiket[j].usia >= 10 || strcmp(tiket[j].penyakit, "jantung") == 1)
                    {
                        printf("WAHANA RUMAH HANTU DAPAT ANDA MASUKI\n");
                        printf("APAKAH ANDA INGIN BERMAIN DI WAHANA RUMAH HANTU? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                        scanf("%d", &pil7);
                        if (pil7 == 1)
                        {
                            tarif = 7000;
                            if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                            {
                                tiket[j].saldo = tiket[j].saldo - tarif;
                                printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                printf("\nSALDO SAAT INI Rp.%d\n", tiket[j].saldo);
                            }
                            else
                            {
                                printf("SALDO TIDAK CUKUP\n");
                            }
                        }
                        else if (pil7 == 2)
                        {
                            printf("PEMILIHAN WAHANA DIBATALKAN\n");
                        }
                        else
                        {
                            printf("INPUTAN SALAH\n");
                        }
                        goto konfirmasi;
                    }

                    else if (tiket[j].usia >= 10 || strcmp(tiket[j].penyakit, "jantung") == 1 || strcmp(tiket[j].penyakit, "anemia") == 1 || tiket[j].tb >= 130)
                    {
                        printf("WAHANA ACCELERATOR DAPAT ANDA NAIKI\n");
                        printf("APAKAH ANDA INGIN BERMAIN DI WAHANA ACCELERATOR? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                        scanf("%d", &pil8);
                        if (pil8 == 1)
                        {
                            tarif = 10000;
                            if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                            {
                                tiket[j].saldo = tiket[j].saldo - tarif;
                                printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                printf("\nSALDO ANDA SAAT INI Rp.%d\n", tiket[j].saldo);
                            }
                            else
                            {
                                printf("SALDO TIDAK CUKUP\n");
                            }
                        }
                        else if (pil8 == 2)
                        {
                            printf("PEMILIHAN WAHANA DIBATALKAN\n");
                        }
                        else
                        {
                            printf("INPUTAN SALAH\n");
                        }
                        goto konfirmasi;
                    }
                }
                else if (pil1 == 2)
                {
                    system("cls");

                    printf("==============WAHANA PADA TAMAN HIBURAN=============\n");
                    printf("=======SILAHKAN PILIH WAHANA SESUAI KEINGINAN=======\n");
                    printf("                  1.Roller Coaster\n");
                    printf("                  2.Biang Lala\n");
                    printf("                  3.Sky Swinger\n");
                    printf("                  4.Bom - Bom Car\n");
                    printf("                  5.Rumah Hantu\n");
                    printf("                  6.Accelerator\n");
                    printf("=============================================\n");
                    printf("                  1.Roller Coaster  | tarif Rp.10000\n");
                    printf("                  2.Biang Lala      | tarif Rp.8000\n");
                    printf("                  3.Sky Swinger     | tarif Rp.5000\n");
                    printf("                  4.Bom - Bom Car   | tarif Rp.4000\n");
                    printf("                  5.Rumah Hantu     | tarif Rp.7000\n");
                    printf("                  6.Accelerator     | tarif Rp.10000\n");
                    printf("SILAHKAN MASUKKAN PILIHAN ANDA :");
                    scanf("%d", &pil2);
                    switch (pil2)
                    {
                    case 1:
                        if (tiket[j].usia < 18 || strcmp(tiket[j].penyakit, "asma") == 0 || strcmp(tiket[j].penyakit, "jantung") == 0 || tiket[j].tb < 140)
                        {
                            printf("WAHANA TIDAK SESUAI DENGAN KRITERIA ANDA\n");
                        }
                        else
                        {
                            printf("=============================\n");
                            printf(" WAHANA INI COCOK UNTUK ANDA \n");
                            printf("=============================\n");
                            printf("APAKAH ANDA INGIN MENAIKI WAHANA ROLLER COASTER? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                            scanf("%d", &pil3);
                            if (pil3 == 1)
                            {
                                tarif = 10000;
                                if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                                {
                                    tiket[j].saldo = tiket[j].saldo - tarif;
                                    printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                    printf("\nSALDO SAAT INI Rp.%d\n", tiket[j].saldo);
                                }
                                else
                                {
                                    printf("SALDO TIDAK CUKUP\n");
                                }
                            }
                            else if (pil3 == 2)
                            {
                                printf("PEMILIHAN WAHANA DIBATALKAN\n");
                            }
                            else
                            {
                                printf("INPUTAN SALAH\n");
                            }
                            goto konfirmasi;
                        }
                        break;
                    case 2:
                        if (tiket[j].usia < 14 || strcmp(tiket[j].penyakit, "hipertensi") == 0 || strcmp(tiket[j].penyakit, "jantung") == 0)
                        {
                            printf("WAHANA TIDAK SESUAI DENGAN KRITERIA ANDA\n");
                        }
                        else
                        {
                            printf("=============================\n");
                            printf(" WAHANA INI COCOK UNTUK ANDA \n");
                            printf("=============================\n");
                            printf("APAKAH ANDA INGIN BERMAIN DI WAHANA BIANG LALA? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                            scanf("%d", &pil4);
                            if (pil4 == 1)
                            {
                                tarif = 8000;
                                if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                                {
                                    tiket[j].saldo = tiket[j].saldo - tarif;
                                    printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                    printf("\nSALDO SAAT INI Rp.%d\n", tiket[j].saldo);
                                }
                                else
                                {
                                    printf("SALDO TIDAK CUKUP\n");
                                }
                            }
                            else if (pil4 == 2)
                            {
                                printf("PEMILIHAN WAHANA DIBATALKAN\n");
                            }
                            else
                            {
                                printf("INPUTAN SALAH\n");
                            }
                            goto konfirmasi;
                        }
                        break;
                    case 3:
                        if (tiket[j].usia < 16 || strcmp(tiket[j].penyakit, "jantung") == 0 || tiket[j].tb < 150 || strcmp(tiket[j].penyakit, "hipertensi") == 0)
                        {
                            printf("WAHANA TIDAK SESUAI DENGAN KRITERIA ANDA\n");
                        }
                        else
                        {
                            printf("=============================\n");
                            printf(" WAHANA INI COCOK UNTUK ANDA \n");
                            printf("=============================\n");
                            printf("APAKAH ANDA INGIN BERMAIN DI WAHANA SKY SWINGER? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                            scanf("%d", &pil5);
                            if (pil5 == 1)
                            {
                                tarif = 5000;
                                if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                                {
                                    tiket[j].saldo = tiket[j].saldo - tarif;
                                    printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                    printf("\nSALDO SAAT INI Rp.%d\n", tiket[j].saldo);
                                }
                                else
                                {
                                    printf("SALDO TIDAK CUKUP\n");
                                }
                            }
                            else if (pil5 == 2)
                            {
                                printf("PEMILIHAN WAHANA DIBATALKAN\n");
                            }
                            else
                            {
                                printf("INPUTAN SALAH\n");
                            }
                            goto konfirmasi;
                        }
                        break;
                    case 4:
                        if (tiket[j].usia < 10 || strcmp(tiket[j].penyakit, "jantung") == 0)
                        {
                            printf("WAHANA TIDAK SESUAI DENGAN KRITERIA ANDA\n");
                        }
                        else
                        {
                            printf("=============================\n");
                            printf(" WAHANA INI COCOK UNTUK ANDA \n");
                            printf("=============================\n");
                            printf("APAKAH ANDA INGIN BERMAIN DI WAHANA BOM-BOM CAR? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                            scanf("%d", &pil6);
                            if (pil6 == 1)
                            {
                                tarif = 4000;
                                if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                                {
                                    tiket[j].saldo = tiket[j].saldo - tarif;
                                    printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                    printf("\nSALDO SAAT INI Rp.%d\n", tiket[j].saldo);
                                }
                                else
                                {
                                    printf("SALDO TIDAK CUKUP\n");
                                }
                            }
                            else if (pil6 == 2)
                            {
                                printf("PEMILIHAN WAHANA DIBATALKAN\n");
                            }
                            else
                            {
                                printf("INPUTAN SALAH\n");
                            }
                            goto konfirmasi;
                        }
                        break;
                    case 5:
                        if (tiket[j].usia < 10 || strcmp(tiket[j].penyakit, "jantung") == 0)
                        {
                            printf("WAHANA TIDAK SESUAI DENGAN KRITERIA ANDA\n");
                        }
                        else
                        {
                            printf("=============================\n");
                            printf(" WAHANA INI COCOK UNTUK ANDA \n");
                            printf("=============================\n");
                            printf("APAKAH ANDA INGIN BERMAIN DI WAHANA RUMAH HANTU? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                            scanf("%d", &pil7);
                            if (pil7 == 1)
                            {
                                tarif = 7000;
                                if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                                {
                                    tiket[j].saldo = tiket[j].saldo - tarif;
                                    printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                    printf("\nSALDO SAAT INI Rp.%d\n", tiket[j].saldo);
                                }
                                else
                                {
                                    printf("SALDO TIDAK CUKUP\n");
                                }
                            }
                            else if (pil7 == 2)
                            {
                                printf("PEMILIHAN WAHANA DIBATALKAN\n");
                            }
                            else
                            {
                                printf("INPUTAN SALAH\n");
                            }
                            goto konfirmasi;
                        }
                        break;
                    case 6:
                        if (tiket[j].usia < 10 || strcmp(tiket[j].penyakit, "jantung") == 0 || strcmp(tiket[j].penyakit, "anemia") == 0 || tiket[j].tb < 130)
                        {
                            printf("WAHANA TIDAK SESUAI DENGAN KRITERIA ANDA\n");
                        }
                        else
                        {
                            printf("=============================\n");
                            printf(" WAHANA INI COCOK UNTUK ANDA \n");
                            printf("=============================\n");
                            printf("APAKAH ANDA INGIN BERMAIN DI WAHANA ACCELERATOR? \n\t1.IYA\n\t2.TIDAK\nMASUKKAN PILIHAN :");
                            scanf("%d", &pil8);
                            if (pil8 == 1)
                            {
                                tarif = 10000;
                                if (tiket[j].saldo > tarif || tiket[j].saldo == tarif)
                                {
                                    tiket[j].saldo = tiket[j].saldo - tarif;
                                    printf("\n===SILAHKAN BERMAIN DI WAHANA INI===\n");
                                    printf("\nSALDO SAAT INI Rp.%d\n", tiket[j].saldo);
                                }
                                else
                                {
                                    printf("SALDO TIDAK CUKUP\n");
                                }
                            }
                            else if (pil8 == 2)
                            {
                                printf("PEMILIHAN WAHANA DIBATALKAN\n");
                            }
                            else
                            {
                                printf("INPUTAN SALAH\n");
                            }
                            goto konfirmasi;
                        }
                        break;
                    default:
                        printf("PILIHAN ANDA SALAH\n");
                    }
                }
                else
                {
                    printf("PILIHAN SALAH\n");
                }
                break;

            case 3:
                goto keluar;
                break;
            default:
                printf("PILIHAN ANDA SALAH\n");
            }
        konfirmasi:

            printf("\nApakah anda ingin  kembali ke menu ? Y/T : ");

            scanf("%s", &konfirmasi);

            if (strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0)
            {

                goto awal;
            }
            else if (strcmp(konfirmasi, "T") == 0 || strcmp(konfirmasi, "t") == 0)
            {

                goto keluar;
            keluar:
                system("cls");
                printf("================================");
                printf("\n       Terimakasih ");
                printf("\n================================\n");
            }
            else
            {

                printf("\nPilihan salah");

                goto konfirmasi;
            }
            break;
        case 3:
            fflush(stdin);
            do
            {
                system("cls");
                printf("===================================================================\n");
                printf("===========================SOUVENIR SHOP===========================\n");
                printf("===================================================================\n");
                printf("MENU \t: \n");
                printf("1. DAFTAR SOUVENIR \n2. CARI SOUVENIR \n3. PEMBELIAN \n4. TAMBAH SOUVENIR (ADMIN) \n5. UPDATE (ADMIN) \n6. DELETE (ADMIN) \n7. KELUAR \n");
                printf("Masukkan Pilihan : ");
                scanf("%c", &pilihan);
                fflush(stdin);
                system("cls");
                switch (pilihan)
                {
                case '1':
                    system("cls");
                    printf("________________________________________________________________________\n");
                    printf("|                           DAFTAR SOUVENIR                            |\n");
                    printf("|______________________________________________________________________|\n");
                    daftar_souvenir();
                    break;
                case '2':
                    system("cls");
                    printf("________________________________________________________________________\n");
                    printf("|                             CARI SOUVENIR                            |\n");
                    printf("|______________________________________________________________________|\n");
                    cari();
                    break;
                case '3':
                    system("cls");
                    printf("________________________________________________________________________\n");
                    printf("|                            	 PEMBELIAN                             |\n");
                    printf("|______________________________________________________________________|\n");
                    pembelian();
                    break;
                case '4':
                    system("cls");
                    printf("________________________________________________________________________\n");
                    printf("|                            TAMBAH SOUVENIR                           |\n");
                    printf("|______________________________________________________________________|\n");
                    tambah_souvenir();
                    break;
                case '5':
                    system("cls");
                    printf("________________________________________________________________________\n");
                    printf("|                                 UPDATE                               |\n");
                    printf("|______________________________________________________________________|\n");
                    update_stock();
                    break;
                case '6':
                    // delete_stock();
                    break;
                case '7':
                    main();
                    break;
                default:
                    printf("PILIHAN YANG ANDA MASUKKAN SALAH\n");
                }
                printf("KEMBALI KE MENU? (Y/T) :");
                scanf("%c", &ulangi);
                fflush(stdin);
                system("cls");
            } while (ulangi == 'y');
            break;
        case 4:
            printf("MENU YANG ADA DI TOKO KAMI\n");
            printf("1. MAKANAN\n");
            printf("2. MINUMAN\n");
            printf("MASUKKAN PILIHAN : ");
            scanf("%d", &pilih);
            switch (pilih)
            {
            case 1:

            menu:
                printf("\n1. cotton candy (25k) \n");
                printf("2. sausage (20k)\n");
                printf("3. French fries (30k) \n");
                printf("4. popcorn (35k)\n");
                printf("pilih menu makanan: ");
                scanf("%d", &makanan);

                if (makanan == 1)
                {
                    makanan = hcotton_candy;
                }
                else if (makanan == 2)
                {
                    makanan = hsausage;
                }
                else if (makanan == 3)
                {
                    makanan = hFrench_fries;
                }
                else if (makanan == 4)
                {
                    makanan = hpopcorn;
                }
                else if (makanan > 4)
                {
                    printf("pilihan anda tidak ada dalam menu\n");
                }
            hitungf:
                total = makanan;
                printf("total=%d\n", total);

            ulang2:
                printf("\nIngin pesan minuman?\n");
                printf("1. Ya\n");
                printf("2. Tidak\n");
                printf("Masukan Pilihan : ");
                scanf("%d", &ulang);
                fflush(stdin);
                if (ulang == 1)
                {
                    goto drink;
                }
                else if (ulang == 2)
                {
                    goto hitung;
                    break;
                }
                break;

            drink:
                printf("\n1. pop ice (20k) \n");
                printf("2. soft drink (15k) \n");
                printf("3. juice (20k) \n");
                printf("pilih minuman: \n");
                scanf("%d", &drink);

                if (drink == 1)
                {
                    drink = hpop_ice;
                }
                else if (drink == 2)
                {
                    drink = hsoft_drink;
                }
                else if (drink == 3)
                {
                    drink = hjuice;
                }
                else if (drink > 3)
                {
                    printf("pilihan anda tidak ada dalam menu\n");
                }

                total2 = drink;
                printf("total = %d\n", total2);
                goto hitung4;
                fflush(stdin);

            hitung:
                total = makanan;
                printf("total bayar = %d\n", total);
                printf("total pembayaran= ");
                scanf("%d", &bayar);
                if (bayar < total)
                {
                    printf("mohon maaf uang anda kurang\n\n");
                    goto hitung;
                }
                else
                    kembali = bayar - total;
                printf("Kembali : %d\n\n", kembali);
                printf("Terima kasih atas kunjungannya\n\n");
                break;

            hitung4:
                printf("\n\tpesanan anda\n");
                printf("makanan= %d\n", total);
                printf("minuman= %d\n", total2);

            result:
                total3 = total + total2;
                printf("total bayar = %d\n", total3);
                printf("total pembayaran= ");
                scanf("%d", &bayar);
                if (bayar < total3)
                {
                    printf("mohon maaf uang anda kurang\n\n");
                    goto result;
                }
                else
                    kembali = bayar - total3;
                printf("Kembali : %d\n\n", kembali);
                printf("Terima kasih atas kunjungannya\n\n");
                break;

            case 2:
                printf("\n1. pop ice (20k) \n");
                printf("2. soft drink (15k) \n");
                printf("3. juice (20k) \n");
                printf("pilih minuman: ");
                scanf("%d", &minuman);

                if (minuman == 1)
                {
                    minuman = hpop_ice;
                }
                else if (minuman == 2)
                {
                    minuman = hsoft_drink;
                }
                else if (minuman == 3)
                {
                    minuman = hjuice;
                }
                else if (minuman > 3)
                {
                    printf("pilihan anda tidak ada dalam menu\n");
                }

            hitungd:
                total3 = minuman;
                printf("total bayar = %d\n", total3);
                printf("total pembayaran= ");
                scanf("%d", &bayar);
                if (bayar < total3)
                {
                    printf("mohon maaf uang anda kurang\n\n");
                    goto hitungd;
                }
                else
                    kembali = bayar - total3;
                printf("Kembali : %d\n\n", kembali);
                printf("Terima kasih atas kunjungannya\n\n");
                break;
            }
            break;
        case 5:
            if (identitas[0].usia == 0)
            {
                printf("HARUS ADA PELANGGAN UNTUK MENGHITUNG PARKIR\n");
            }
            else
            {
                printf("UNTUK MELAKUKAN OPERASI INI ANDA HARUS MEMASUKKAN KODE ADMIN\n");
                printf("MASUKKAN KODE DISINI : ");
                scanf("%d", &admin);
                if (admin == 61105)
                {
                    fp = fopen("parkir.txt", "r");
                    if (fp == NULL)
                    {
                        printf("TIDAK ADA FILE YANG DITEMUKAN!");
                    }
                    while (!feof(fp))
                    {
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
                    switch (choice)
                    {
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
                }
                else
                {
                    printf("KODE YANG ANDA MASUKKAN SALAH!!!");
                }
            }
            break;
        case 6:
            exit(1);
            break;
        }
    }
    return 0;
}

void title()
{
    printf("\t +----------------------------------------------------------------------------------------+\n");
    printf("\t |                         FINAL PROJECT ALGORITMA PEMROGRAMAN                            |\n");
    printf("\t |                                  PLAYGROUND SYSTEM                                     |\n");
    printf("\t +----------------------------------------------------------------------------------------+\n");
}

void nama()
{
    printf("\t |OLEH: PANDE PUTU DEVO PUNDA MAHESWARA                                        2008561107 |\n");
    printf("\t |      I PUTU DUTA AWIDYA SARTANA PUTRA                                       2008561090 |\n");
    printf("\t |      I WAYAN AGUS JUNIARTHA                                                 2008561095 |\n");
    printf("\t |      I DEWA GDE PUTRA ANGA BIARA                                            2008561105 |\n");
    printf("\t |      I NYOMAN BUDHIARTA SUPUTRA                                             2008561110 |\n");
    printf("\t |      IDA BAGUS MADE SURYA WIDNYANA                                          2008561092 |\n");
    printf("\t +----------------------------------------------------------------------------------------+\n");
    printf("\n");
}
