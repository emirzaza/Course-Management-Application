#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *ogrenciListesi, *dersListesi, *notListesi, *yedekListe;

struct ogrenci
{
    char ad[20];
    char soyad[20];
    int no;
}ogrenciBilgisi;

struct ders
{
    char ad[30];
    char kod[10];
    float AKTS;
    float kredi;
}dersBilgisi;


int main()
{
    system("COLOR 9");
    int n;

    while(n>0 || n<9)
    {
        printf("1)Kayit Ekle\n2)Ogrenci Listele\n3)Kayit Arama\n4)Kayit Guncelleme\n5)Kayit Silme\n6)Ders Ekle\n7)Not Giris\n8)Cikis\n");
        printf("seciminiz: ");
        scanf("%d", &n);
        printf("\n");

        switch(n)
        {
        case 1:
            kayitEkle();
        break;
        case 2:
            ogrenciListele();
        break;
        case 3:
            kayitAra();
        break;
        case 4:
            kayitGuncelle();
        break;
        case 5:
            kayitSil();
        break;
        case 6:
            DersEkle();
        break;
        case 7:
            notGiris();
        break;
        case 8:
            return 0;
        break;
        }

    }

}

void kayitEkle()
{
    int i,n;

    printf("kac ogrenci eklemek istediginizi giriniz: ");
    scanf("%d", &n);

    ogrenciListesi = fopen("ogrenciListesi.txt", "a");

    for(i=0; i<n; i++)
    {
        printf("\nogrencinin adini giriniz: ");
        scanf("%s", ogrenciBilgisi.ad);

        printf("ogrencinin soyadini giriniz: ");
        scanf("%s", ogrenciBilgisi.soyad);

        printf("ogrencinin numarasini giriniz: ");
        scanf("%d", &ogrenciBilgisi.no);

        fprintf(ogrenciListesi, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, ogrenciBilgisi.no);

        if(n!=0)
        {
            printf("basariyla eklendi!\n");
        }

    }

    fclose(ogrenciListesi);
    getch();
    system("cls");

}

void ogrenciListele()
{
    int i,n;

    ogrenciListesi = fopen("ogrenciListesi.txt", "r");

    if(ogrenciListesi==NULL)
    {
        printf("Dosya bulunamadi!");
    }
    else
        while(!feof(ogrenciListesi))
        {
            fscanf(ogrenciListesi, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, &ogrenciBilgisi.no);
            printf("%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, ogrenciBilgisi.no);
        }

        fclose(ogrenciListesi);
        getch();
        system("cls");

}

void kayitAra()
{
    int isimSorgu[20];
    ogrenciListesi = fopen("ogrenciListesi.txt", "r");

    if(ogrenciListesi==NULL)
    {
         printf("Dosya Bulunamadi!");
    }

    printf("aradiginiz ogrencinin ismini giriniz: ");
    scanf("%s", isimSorgu);

    while(!feof(ogrenciListesi))
    {
        fscanf(ogrenciListesi, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, &ogrenciBilgisi.no);
        if(strcmp(isimSorgu, ogrenciBilgisi.ad)==0)
        {
            printf("\naradiginiz ogrenci bulundu: \n%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, ogrenciBilgisi.no);
        }

    }

    fclose(ogrenciListesi);
    getch();
    system("cls");

}

void kayitGuncelle()
{
    int numaraKontrol, durum = 0;
    printf("Guncellemek istediginiz ogrencinin numarasini giriniz: ");
    scanf("%d", &numaraKontrol);

    ogrenciListesi = fopen("ogrenciListesi.txt", "r");
    yedekListe = fopen("yedekListe.txt", "w");

    if(ogrenciListesi==NULL)
    {
         printf("Dosya Bulunamadi!");
    }

    while(!feof(ogrenciListesi))
    {
        fscanf(ogrenciListesi, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, &ogrenciBilgisi.no);

        if(numaraKontrol!=ogrenciBilgisi.no)
        {
            fprintf(yedekListe, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, ogrenciBilgisi.no);
        }
        else
            durum = 1;

    }
    fclose(ogrenciListesi);
    fclose(yedekListe);

    if(durum = 1)
    {
        remove("ogrenciListesi.txt");
        rename("yedekListe.txt", "ogrenciListesi.txt");
    }
    else
    {
        remove("yedekListe.txt");
        printf("%d numarali ogrenci bulunamadi", numaraKontrol);
    }

    ogrenciListesi = fopen("ogrenciListesi.txt", "a");

    printf("\nyeni adi giriniz: ");
    scanf("%s", ogrenciBilgisi.ad);

    printf("yeni soyadi giriniz: ");
    scanf("%s", ogrenciBilgisi.soyad);

    printf("yeni numarayi giriniz: ");
    scanf("%d", &ogrenciBilgisi.no);

    fprintf(ogrenciListesi, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, ogrenciBilgisi.no);

    printf("basariyla eklendi!\n");

    fclose(ogrenciListesi);
    getch();
    system("cls");

}

void kayitSil()
{
    int numaraKontrol, durum = 0;
    printf("silinecek ogrencinin numarasini giriniz: ");
    scanf("%d", &numaraKontrol);

    ogrenciListesi = fopen("ogrenciListesi.txt", "r");
    yedekListe = fopen("yedekListe.txt", "w");

    if(ogrenciListesi==NULL)
    {
         printf("Dosya Bulunamadi!");
    }

    while(!feof(ogrenciListesi))
    {
        fscanf(ogrenciListesi, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, &ogrenciBilgisi.no);

        if(numaraKontrol!=ogrenciBilgisi.no)
        {
            fprintf(yedekListe, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, ogrenciBilgisi.no);
        }
        else
            durum = 1;

    }
    fclose(ogrenciListesi);
    fclose(yedekListe);

    if(durum = 1)
    {
        remove("ogrenciListesi.txt");
        rename("yedekListe.txt", "ogrenciListesi.txt");
        printf("silme islemi basarili\n\n");
    }
    else
    {
        remove("yedekListe.txt");
        printf("%d numarali ogrenci bulunamadi", numaraKontrol);
    }

    ogrenciListele();


}
void DersEkle()
{
    dersListesi = fopen("dersListesi.txt", "a");

    printf("Dersin adini bosluk olmadan giriniz: ");
    scanf("%s", dersBilgisi.ad);

    printf("Ders kodunu giriniz: ");
    scanf("%s", dersBilgisi.kod);

    printf("Derse ait AKTS bilgisini giriniz: ");
    scanf("%f", &dersBilgisi.AKTS);

    printf("Dersin kredi bilgisini giriniz: ");
    scanf("%f", &dersBilgisi.kredi);

    fprintf(dersListesi, "%s\t%s\t%.1f\t%.1f\n", dersBilgisi.ad, dersBilgisi.kod, dersBilgisi.AKTS, dersBilgisi.kredi);

    printf("\nDers basariyla eklendi!");

    fclose(dersListesi);
    getch();
    system("cls");
}

void notGiris()
{
    float vizeNot, finalNot;
    char isimSorgu[20], dersSorgu[20];

    ogrenciListesi = fopen("ogrenciListesi.txt", "r");
    dersListesi = fopen("dersListesi.txt", "r");
    notListesi = fopen("notListesi.txt", "a");

    printf("not girmek istediginiz ogrencinin ismini giriniz: ");
    scanf("%s", isimSorgu);

    while(!feof(ogrenciListesi))
    {
         fscanf(ogrenciListesi, "%s\t%s\t%d\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, &ogrenciBilgisi.no);
         if(strcmp(isimSorgu, ogrenciBilgisi.ad)==0)
         {
              printf("not girisi yapmak istediginiz dersi giriniz: ");
              scanf("%s", dersSorgu);

              while(!feof(dersListesi))
                {
                    fscanf(dersListesi, "%s\t%s\t%.1f\t%.1f\n", dersBilgisi.ad, dersBilgisi.kod, &dersBilgisi.AKTS, &dersBilgisi.kredi);
                    if(strcmp(dersSorgu, dersBilgisi.ad)==0)
                        {
                            printf("ogrencinin %s dersi icin vize notunu giriniz: ", dersBilgisi.ad);
                            scanf("%f", &vizeNot);
                            printf("ogrencinin %s dersi icin final notunu giriniz: ", dersBilgisi.ad);
                            scanf("%f", &finalNot);
                            fprintf(notListesi, "%s\t%s\t%d\t|\t%s\t%s\t%.1f\n", ogrenciBilgisi.ad, ogrenciBilgisi.soyad, ogrenciBilgisi.no, dersBilgisi.ad, dersBilgisi.kod, (vizeNot * 0.4) + (finalNot * 0.6));
                            printf("not basariyla eklenmistir! ");
                        }

                }

                fclose(dersListesi);
         }

    }
    fclose(ogrenciListesi);
    fclose(notListesi);
    getch();
    system("cls");
}
