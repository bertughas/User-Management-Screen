#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//kullanici giris ekrain yapimi.
struct kisi{
char ad[25],soyad[25],tel[25],adres[25],id[25],parola[25],parolaTekrar[25];
};
FILE *fp;
void giris(){
static adet=0;
struct kisi k1;
fp=fopen("kisiler.dat","r+b");
if(fp==NULL){
    printf("Veritabani hatasi.");
}
char id[25],parola[25];
printf("\nKullanici adi:");scanf("%s",&id);
printf("\nParola:");
char ch;
ch=getch();
int i=0;
while(ch!=13){
    parola[i]=ch;
    printf("*");
    ch=getch();
    i++;
}
parola[i]='\0';
while(fread(&k1,sizeof(struct kisi),1,fp)==1){
    if(strcmp(id,k1.id)==0 && strcmp(parola,k1.parola)==0){
        printf("\nGiris islemi basarili\n");
        printf("\nHOSGELDINIZ");
        printf("\n\tSayin:%s",k1.ad);
        fclose(fp);
        return;

    }
    else{
        printf("\nHatali id veya parola.");
        adet++;
        if(adet==3){
            printf("\nCok fazla sayida hatali giris yaptiniz,ana menuye yonlendiriliyorsunuz.");
            return 0;
        }
        giris();
    }
}


}

void yeniKayit(){
struct kisi k1;
fp=fopen("kisiler.dat","a+b");
if(fp==NULL){
    printf("Veri tabani hatasi");
}
printf("\nAd:");scanf("%s",&k1.ad);
printf("Soyad:");scanf("%s",&k1.soyad);
printf("Tel:");scanf("%s",&k1.tel);
printf("Adres:");scanf("%s",&k1.adres);
printf("ID:");scanf("%s",&k1.id);
printf("Parola(en az 8 karakter):");
char ch;
ch=getch();
int i=0;
while(ch!=13){
    k1.parola[i]=ch;
    printf("*");
    ch=getch();
    i++;
}
k1.parola[i]='\0';
i=0;
int len=strlen(k1.parola);
if(len<8){
    printf("\nParola en az 8 karakter uzunlugunda olmailidir");
    yeniKayit();
}
printf("\nParola tekrar(en az 8 karakter):");
ch=getch();
while(ch!=13){
    k1.parolaTekrar[i]=ch;
    printf("*");
    ch=getch();
    i++;
}
k1.parolaTekrar[i]='\0';
int len2=strlen(k1.parolaTekrar);
if(len2<8){
    printf("\nParola tekrari en az 8 karakter uzunlugunda olmalidir.");
    yeniKayit();
}
if(strcmp(k1.parola,k1.parolaTekrar)!=0){
    printf("\nParolalar birbiriyle eslesmiyor.");
    yeniKayit();
}

fwrite(&k1,sizeof(struct kisi),1,fp);
}




int menu(){
printf("\n\n\tANA MENU\n");
printf("\n1-Giris\n");
printf("2-Yeni kayit\n");
printf("3-Cikis\n");
printf("Secim:");
int secim;
scanf("%d",&secim);
return secim;

}


int main() {
int secim=menu();
while(1){
    switch(secim){
        case 1:printf("\nGiris Ekrani\n");
        giris();
        break;
        case 2:printf("\nYeni Kayit Ekrani\n");
        yeniKayit();
        break;
        case 3:printf("\nCikis yaptiniz.");
        return 0;
        default:printf("Gecersiz secim");
        break;

    }




    secim=menu();
}


    return 0;
}
