#include <stdio.h>
#include <stdlib.h>
// cotton candy |sausage |French fries |popcorn
// pop ice |soft drink |lemon water |

int main (void)
{
    system ("color 0b");
    int hcotton_candy, hsausage, hFrench_fries, hpopcorn, hpop_ice, hsoft_drink, hjuice;
    int total,total2, makanan, minuman, pilih, ulang, drink;
    *
    hcotton_candy=25000;
    hsausage=20000;
    hFrench_fries=30000;
    hpopcorn=35000;
    hpop_ice=20000;
    hsoft_drink=15000;
    hjuice=20000;

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

