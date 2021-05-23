#include <stdio.h>
#include <stdlib.h>
// cotton candy |sausage |French fries |popcorn
// pop ice |soft drink |lemon water |

int main (void)
{
    system ("color 0b");
    int hcotton_candy, hsausage, hFrench_fries, hpopcorn, hpop_ice, hsoft_drink, hjuice;
    int total, total2, total3, bayar, kembali, makanan, minuman, pilih, ulang, drink;
    
    hcotton_candy=25000;
    hsausage=20000;
    hFrench_fries=30000;
    hpopcorn=35000;
    hpop_ice=20000;
    hsoft_drink=15000;
    hjuice=20000;

    printf("MENU YANG ADA DI TOKO KAMI\n");
    printf("1. makanan\n");
    printf("2. minuman\n");
    printf("masukkan pilihan anda: ");
    scanf("%d", &pilih);

    switch (pilih) {
        case 1:

        menu:
        printf("\n1. cotton candy (25k) \n");
        printf("2. sausage (20k)\n");
        printf("3. French fries (30k) \n");
        printf("4. popcorn (35k)\n");
        printf("pilih menu makanan: ");
        scanf("%d", &makanan);

        if (makanan==1)
        {
            makanan=hcotton_candy;
        }else if(makanan==2)
        {
            makanan=hsausage;
        }else if(makanan==3)
        {
            makanan=hFrench_fries;
        }else if(makanan==4)
        {
            makanan=hpopcorn;
        }else if(makanan>4)
        {
            printf("pilihan anda tidak ada dalam menu\n");
        }
        hitungf:
        total = makanan;
        printf("total=%d\n", total);



      ulang2 :
        printf("\nIngin pesan minuman?\n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Masukan Pilihan : ");
        scanf("%d",&ulang);
        fflush(stdin);
            if (ulang==1){
                goto drink;
            }else if(ulang==2){
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

             if (drink==1)
        {
            drink=hpop_ice;
        }else if(drink==2)
        {
            drink=hsoft_drink;
        }else if(drink==3)
        {
            drink=hjuice;
        }else if(drink>3)
        {
            printf("pilihan anda tidak ada dalam menu\n");
        }

        total2=drink;
        printf("total = %d\n", total2);
            goto hitung4;
        fflush(stdin);
    

        hitung: 
        total=makanan;
        printf("total bayar = %d\n", total);
        printf("total pembayaran= ");
            scanf("%d", &bayar);
                if (bayar<total)
                    {
                        printf("mohon maaf uang anda kurang\n\n");
                        goto hitung;
                    } else 
                        kembali=bayar-total;
                        printf("Kembali : %d\n\n",kembali);
                        printf("Terima kasih atas kunjungannya\n\n");
        break; 

         hitung4:
        printf("\n\tpesanan anda\n");
        printf("makanan= %d\n", total);
        printf("minuman= %d\n", total2);
        
        result:
            total3=total+total2;
            printf("total bayar = %d\n", total3);
            printf("total pembayaran= ");
            scanf("%d", &bayar);
                if (bayar<total3)
                    {
                        printf("mohon maaf uang anda kurang\n\n");
                        goto result;
                    } else 
                        kembali=bayar-total3;
                        printf("Kembali : %d\n\n",kembali);
                        printf("Terima kasih atas kunjungannya\n\n");
        break;

        case 2:
        printf("\n1. pop ice (20k) \n");
        printf("2. soft drink (15k) \n");
        printf("3. juice (20k) \n");
        printf("pilih minuman: ");
        scanf("%d", &minuman);
       

        if (minuman==1)
        {
            minuman=hpop_ice;
        }else if(minuman==2)
        {
            minuman=hsoft_drink;
        }else if(minuman==3)
        {
            minuman=hjuice;
        }else if(minuman>3)
        {
            printf("pilihan anda tidak ada dalam menu\n");
        }
        
        hitungd:
        total3=minuman;
        printf("total bayar = %d\n", total3);
        printf("total pembayaran= ");
            scanf("%d", &bayar);
                if (bayar<total3)
                    {
                        printf("mohon maaf uang anda kurang\n\n");
                        goto hitungd;
                    } else 
                        kembali=bayar-total3;
                        printf("Kembali : %d\n\n",kembali);
                        printf("Terima kasih atas kunjungannya\n\n");
        break; 
        }
}
        
