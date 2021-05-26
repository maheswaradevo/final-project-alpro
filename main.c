#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char name[50][50];
int umur;
char penyakit[50][50];
int tb;
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
    umur = thn_skrg - thn_lahir;
    return 0;
}
void identity()
{
    char name[50][50];
    int choice, tgl, bln, thn, n, i;
    char penyakit[50][50];
    int j = 0;
    printf("MASUKKAN NAMA ANDA : ");
    scanf("%[^\n]s", &name);
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
    if ((umur >= 17) && (tb > 170))
    {
        printf("ANDA DAPAT MEMAINKAN PERMAINAN DIBAWAH INI : \n");
        printf("1. ROLLER COASTER\n");
        printf("2. BIANG LALA\n");
        printf("3. SKY SWINGER\n");
        printf("4. BOM-BOM CAR\n");
        printf("5. RUMAH HANTU\n");
        printf("6. ACCELERATOR\n");
    }
    else if ((umur >= 12) && (umur < 17) && (tb <= 170) && (tb > 160))
    {
        printf("1. BOM-BOM CAR\n");
        printf("2. RUMAH HANTU\n");
        printf("3. ACCELERATOR\n");
        printf("4. ROLLER COASTER MINI\n");
    }
    else if ((umur < 12) && (tb <= 160))
    {
        printf("UNTUK ANAK UMUR DIBAWAH 11 TAHUN\n");
        printf("DIMOHON DIDAMPINGIN ORANG TUA\n");
        printf("1. SAFARI CAR\n");
        printf("2. KOMEDI PUTAR\n");
        printf("3. ROLLER COASTER MINI\n");
    }
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
    printf("Untuk melakukan operasi ini anda harus memasukkan kode admin!\n");
    printf("Masukkan kode disini : ");
    scanf("%i", &code);
    fflush(stdin);
    if (code == 61105)
    {
        printf("Nama Produk \t\t: ");
        scanf("%[^\n]", &Produk.nama);
        fflush(stdin);
        printf("No Produk \t\t: ");
        scanf("%i", &Produk.no);
        fflush(stdin);
        printf("Jumlah Produk \t\t: ");
        scanf("%i", &Produk.jmlh);
        fflush(stdin);
        printf("Harga Produk \t\t: ");
        scanf("%i", &Produk.harga);
        fflush(stdin);

        fprintf(SOUVENIR, "%s_%i_%i_%i\n", Produk.nama, Produk.no, Produk.jmlh, Produk.harga);
        printf("Selamat! Produk sudah berhasil ditambahkan.\n");
    }
    else
        printf("Kode yang anda masukkan salah!!!");
    fclose(SOUVENIR);
}

void daftar_souvenir()
{
    Souvenir Produk;
    SOUVENIR = fopen("souvenir.txt", "r");
    printf("======================================================================================\n");
    printf("No \t");
    printf("Nama \t\t\t\t");
    printf("Jumlah \t");
    printf("Harga ");
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
    printf("Masukan Nama Produk yang ingin dicari \t: ");
    scanf("%s", &cari);
    fflush(stdin);
    while (!feof(SOUVENIR))
    {
        fscanf(SOUVENIR, "%[^_]_%i_%i_%i\n", &Produk.nama, &Produk.no, &Produk.jmlh, &Produk.harga);
        fflush(stdin);
        if (strcmp(cari, Produk.nama) == 0)
        {
            printf("Nama Produk \t\t: %s\n", Produk.nama);
            printf("No Produk \t\t: %i\n", Produk.no);
            printf("Jumlah Produk \t\t: %i\n", Produk.jmlh);
            printf("Harga Produk \t\t: %i\n", Produk.harga);
        }
    }
    if (strcmp(cari, Produk.nama) != 0)
    {
        printf("Souvenir tersebut belum tersedia\n");
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
    printf("\t===Pilih produk yang akan anda beli===\n");
    printf("Masukkan nomor produk : ");
    scanf("%i", &nomor);
    fflush(stdin);
    printf("Masukkan nominal uang yang anda berikan : ");
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
                    printf("======================Souvenir Berhasil Dibeli===============\n");
                    Produk[index].jmlh -= 1;
                    PEMBELIAN = fopen("pembelian.txt", "a");
                    fprintf(PEMBELIAN, "%s_%i_%i_%i\n", Produk[index].nama, Produk[index].no, 1, Produk[index].harga);
                    fclose(PEMBELIAN);
                    printf("Anda ingin mencetak struk?(y/n)");
                    scanf("%c", &c);
                    if (c == 'y' || c == 'Y')
                    {
                        system("cls");
                        PEMBELIAN = fopen("pembelian.txt", "r");
                        printf("Tanggal pembelian : %s", ctime(&now));
                        printf("======================Struk Bukti Pembelian===============\n");
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
                    printf("======================Souvenir Tidak Berhasil Dibeli===============\n");
            }
            else
                printf("Uang anda kurang untuk membeli produk ini!!!");
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
    printf("Untuk melakukan operasi ini anda harus memasukkan kode admin!\n");
    printf("Masukkan kode disini : ");
    scanf("%i", &code);
    fflush(stdin);
    if (code == 61105)
    {
        daftar_souvenir();
        SOUVENIR = fopen("souvenir.txt", "r+");
        printf("Masukan Nama Produk yang ingin di update \t: ");
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
                printf("Masukkan jumlah barang yang akan di uptade : ");
                scanf("%i", &jmlh);
                printf("Tunggu Sebentar...\n");
                Produk[index].jmlh = jmlh;
                printf("Selamat! Produk sudah berhasil di update.\n");
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
        printf("Kode yang anda masukkan salah!!!");
    fclose(SOUVENIR);
}

int main()
{
    int i, choice;
    int result;
    element data[50];
    FILE *fp;
    int jam, mnt, dtk;
    char name[50];
    char pilihan;
    char ulangi = 'y';
    while (1)
    {
        system("cls");
        printf("\n1. MASUKKAN IDENTITAS ANDA\n");
        printf("2. REKOMENDASI PERMAINAN\n");
        printf("4. SOUVENIR\n");
        printf("5. HITUNG PARKIR\n");
        printf("6. Exit\n");
        printf("MASUKKAN PILIHAN : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            fflush(stdin);
            identity();
            break;
        case 2:
            game();
            break;
        case 4:
            fflush(stdin);
            do
            {
                system("cls");
                printf("===================================================================\n");
                printf("===========================SOUVENIR SHOP===========================\n");
                printf("===================================================================\n");
                printf("~MENU~ \t: \n");
                printf("1. Daftar Souvenir \n2. Cari Souvenir \n3. Pembelian \n4. Tambah Souvenir (Admin) \n5. Update (Admin) \n6. Delete (Admin) \n7. Keluar \n");
                printf("Masukkan Pilihan : ");
                scanf("%c", &pilihan);
                fflush(stdin);
                system("cls");
                switch (pilihan)
                {
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
                    printf("|                                 Update                               |\n");
                    printf("|______________________________________________________________________|\n");
                    update_stock();
                    break;
                case '6':
                    delete_stock();
                    break;
                case '7':
                    main();
                    break;
                default:
                    printf("~Pilihan yang anda masukkan salah~\n");
                }
                printf("Kembali ke menu ? (y/t) :");
                scanf("%c", &ulangi);
                fflush(stdin);
                system("cls");
            } while (ulangi == 'y');
            break;
        case 5:
            fp = fopen("parkir.txt", "r");
            if (fp == NULL)
            {
                printf("Tidak ada file yang ditemukan!");
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
            break;
        case 6:
            exit(1);
            break;
        }
    }
    return 0;
}