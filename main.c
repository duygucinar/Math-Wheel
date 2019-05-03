#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 10

void cark();
int ozdegerbul();
int schur();
int ozvektorbul();
int nilpotent();
int det_bul();

int main(){

    int d_sayisi;

    printf("----------ISLEMLER--------------\n");
    printf("1-) Ozdeger Bulma\n");
    printf("2-) Schur Teoremi\n");
    printf("3-) Ozdeger Vektoru Bulma\n");
    printf("4-) Nilpotent Teoremi\n");
    printf("--------------------------------\n");
    printf("Carki kac kere dondurmek istiyorsunuz ? :");
    scanf("%d",&d_sayisi);
    printf("\n\n");

    cark(d_sayisi);

    return 0;
}

void cark(int d_sayisi){

    int i,islem_no,r_sayi;

    srand(time(NULL));


    printf("\tUretilen Sayilar\n");
    printf("------------------------------\n");

    for(i=0;i<d_sayisi;i++){
        r_sayi=rand()%242;
        printf("%d\n",r_sayi);
    }

    islem_no=r_sayi%4;

    switch(islem_no){
        case 1:
            printf("Yapilacak islem   :1");
            ozdegerbul();
            break;

        case 2:
            printf("Yapilacak islem   :2");
            schur();
            break;

        case 3:
            printf("Yapilacak islem   :3");
            ozvektorbul();
            break;

        default:
            printf("Yapilacak islem   :4");
            nilpotent();
            break;

    }



}

int ozdegerbul(){

    int i,j,t=0,k,n,det=0;
    int birim[MAX][MAX];
    int cikarilacakmatris[MAX][MAX];
    int yenimatris[MAX][MAX];
    int oz_deger[MAX];

    FILE *dosya=fopen("ozdeger.txt","w");

    printf("\n\nKare matrisinizin boyutunu giriniz    :");
    scanf("%d",&n);

    int matris[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Matrisin %d. satir %d. sutun elemanini giriniz   :",i+1,j+1);
            scanf("%d",&matris[i][j]);
        }
    }

    printf("\n\tGirdiginiz Matris\n------------------------------------\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",matris[i][j]);
        }
        printf("\n");
    }


    printf("---------------------------------\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                birim[i][j]=1;
            }
            else
                birim[i][j]=0;
        }
    }

    for(k=-100;k<100;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j){
                    cikarilacakmatris[i][j]=k*birim[i][j];
                }
                else{
                    cikarilacakmatris[i][j]=0;
                }

                yenimatris[i][j]=matris[i][j]-cikarilacakmatris[i][j];
                fprintf(dosya,"%5d",yenimatris[i][j]);

                det=det_bul(yenimatris,n);

            }
            fprintf(dosya,"\n");
        }
        fprintf(dosya,"\n");

        if(det==0){
            printf("Matrisin ozdegeri %d dir.\n",k);
            oz_deger[t]=k;
            t++;
        }
    }


    for(i=0;i<t;i++){
        fprintf(dosya,"Ozdeger   :%d\n",oz_deger[i]);
    }

    fclose(dosya);

    return 0;
}

int det_bul(int a[MAX][MAX],int n){

    int det=0,p,h,k,i,j,temp[MAX][MAX];

    if(n==1){
      return a[0][0];
    }

    else if(n==2){
      det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
      return det;
    }

    else{
        for(p=0;p<n;p++){
            h = 0;
            k = 0;

            for(i=1;i<n;i++){
                for( j=0;j<n;j++){
                    if(j==p){
                        continue;
                    }
                    temp[h][k] = a[i][j];
                k++;
                    if(k==n-1){
                      h++;
                      k = 0;
                    }
                }
            }

        det=det+a[0][p]*pow(-1,p)*det_bul(temp,n-1);
    }
    return det;
  }
}

int ozvektorbul(){

    int i,j,m,t=0,k,n,det=0;
    int a,b,c,d,toplam1=0,toplam2=0,toplam3=0,toplam4=0;
    int birim[MAX][MAX];
    int cikarilacakmatris[MAX][MAX];
    int yenimatris[MAX][MAX];
    int yenimatris1[MAX][MAX];
    int yenimatris2[MAX][MAX];
    int yenimatris3[MAX][MAX];
    int yenimatris4[MAX][MAX];
    int oz_deger[MAX];

    FILE *dosya=fopen("ozvektor.txt","w");

    printf("\n\nKare matrisinizin boyutunu giriniz    :");
    scanf("%d",&n);

    int matris[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Matrisin %d. satir %d. sutun elemanini giriniz   :",i+1,j+1);
            scanf("%d",&matris[i][j]);
        }
    }

    printf("\n\tGirdiginiz Matris\n------------------------------------\n");
    fprintf(dosya,"\tGirdiginiz Matris\n------------------------------------\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",matris[i][j]);
            fprintf(dosya,"%3d",matris[i][j]);
        }
        printf("\n");
        fprintf(dosya,"\n");
    }


    printf("---------------------------------\n");
    fprintf(dosya,"---------------------------------\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                birim[i][j]=1;
            }
            else
                birim[i][j]=0;
        }
    }

    for(k=-100;k<100;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j){
                    cikarilacakmatris[i][j]=k*birim[i][j];
                }
                else{
                    cikarilacakmatris[i][j]=0;
                }

                yenimatris[i][j]=matris[i][j]-cikarilacakmatris[i][j];
                fprintf(dosya,"%5d",yenimatris[i][j]);

                det=det_bul(yenimatris,n);

            }
            fprintf(dosya,"\n");
        }
        fprintf(dosya,"\n");

        if(det==0){
            printf("Matrisin ozdegeri %d dir.\n",k);
            fprintf(dosya,"Matrisin ozdegeri %d dir.\n",k);
            oz_deger[t]=k;
            t++;
        }
    }
    if(n==2){
    for(m=0;m<t;m++){
        printf("Ozdeger=%d icin olusan matris:\n",oz_deger[m]);
        fprintf(dosya,"Ozdeger=%d icin olusan matris:\n",oz_deger[m]);
        fprintf(dosya,"-------------------------------------\n");

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                yenimatris[i][j]=matris[i][j]-(oz_deger[m]*birim[i][j]);

                if(m==0){
                    yenimatris1[i][j]=yenimatris[i][j];
                }
                else if(m==1){
                    yenimatris2[i][j]=yenimatris[i][j];
                }

                printf("%5d",yenimatris[i][j]);
                fprintf(dosya,"%5d",yenimatris[i][j]);
                }
                printf("\n");
                fprintf(dosya,"\n");
                }
            printf("\n");
            fprintf(dosya,"\n");
    }

    for(m=0;m<t;m++){
        printf("\nOzdeger=%d icin Ozvektorler:\n",oz_deger[m]);
        printf("-----------------------------------------\n");

        fprintf(dosya,"\nOzdeger=%d icin Ozvektorler:\n",oz_deger[m]);
        fprintf(dosya,"-----------------------------------------\n");

        for(a=-5;a<5;a++){
            for(b=-5;b<5;b++){
                if(a!=0 || b!=0){
                    if(m==0){
                        toplam1=(yenimatris1[0][0]*a)+(yenimatris1[0][1]*b);
                        toplam2=(yenimatris1[1][0]*a)+(yenimatris1[1][1]*b);

                    }
                    if(m==1){
                    toplam1=(yenimatris2[0][0]*a)+(yenimatris2[0][1]*b);
                    toplam2=(yenimatris2[1][0]*a)+(yenimatris2[1][1]*b);

                    }
                }

                if(toplam1==0 && toplam2==0){
                    printf("(%d,%d) matrisin ozvektorudur.\n",a,b);
                    fprintf(dosya,"(%d,%d) matrisin ozvektorudur.\n",a,b);
                }
            }
            toplam1=0;
            toplam2=0;
        }
    }
    }



    if(n==3){
        for(m=0;m<t;m++){
            printf("Ozdeger=%d icin olusan matris:\n",oz_deger[m]);
            printf("-----------------------------------------\n");

            fprintf(dosya,"Ozdeger=%d icin olusan matris:\n",oz_deger[m]);
            fprintf(dosya,"-----------------------------------------\n");

            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    yenimatris[i][j]=matris[i][j]-(oz_deger[m]*birim[i][j]);

                    if(m==0){
                        yenimatris1[i][j]=yenimatris[i][j];
                    }
                    else if(m==1){
                        yenimatris2[i][j]=yenimatris[i][j];
                    }
                    else if(m==2){
                        yenimatris3[i][j]=yenimatris[i][j];
                    }

                    printf("%5d",yenimatris[i][j]);
                    fprintf(dosya,"%5d",yenimatris[i][j]);
                }
                printf("\n");
                fprintf(dosya,"\n");
            }
            printf("\n");
            fprintf(dosya,"\n");

    }

    for(m=0;m<t;m++){
        printf("\nOzdeger=%d icin Ozvektorler:\n",oz_deger[m]);
        printf("-----------------------------------------\n");

        fprintf(dosya,"\nOzdeger=%d icin Ozvektorler:\n",oz_deger[m]);
        fprintf(dosya,"-----------------------------------------\n");
        for(a=-5;a<5;a++){
            for(b=-5;b<5;b++){
                for(c=-5;c<5;c++){
                    if(a!=0 || b!=0 || c!=0){
                        if(m==0){
                            toplam1=(yenimatris1[0][0]*a)+(yenimatris1[0][1]*b)+(yenimatris1[0][2]*c);
                            toplam2=(yenimatris1[1][0]*a)+(yenimatris1[1][1]*b)+(yenimatris1[1][2]*c);
                            toplam3=(yenimatris1[2][0]*a)+(yenimatris1[2][1]*b)+(yenimatris1[2][2]*c);
                        }
                        else if(m==1){
                            toplam1=(yenimatris2[0][0]*a)+(yenimatris2[0][1]*b)+(yenimatris2[0][2]*c);
                            toplam2=(yenimatris2[1][0]*a)+(yenimatris2[1][1]*b)+(yenimatris2[1][2]*c);
                            toplam3=(yenimatris2[2][0]*a)+(yenimatris2[2][1]*b)+(yenimatris2[2][2]*c);
                        }
                        else if(m==2){
                            toplam1=(yenimatris3[0][0]*a)+(yenimatris3[0][1]*b)+(yenimatris3[0][2]*c);
                            toplam2=(yenimatris3[1][0]*a)+(yenimatris3[1][1]*b)+(yenimatris3[1][2]*c);
                            toplam3=(yenimatris3[2][0]*a)+(yenimatris3[2][1]*b)+(yenimatris3[2][2]*c);
                        }
                    }

                    if(toplam1==0 && toplam2==0 && toplam3==0){
                        printf("(%d,%d,%d) matrisin ozvektorudur.\n",a,b,c);
                        fprintf(dosya,"(%d,%d,%d) matrisin ozvektorudur.\n",a,b,c);
                    }
                }
            }
            toplam1=0;
            toplam2=0;
            toplam3=0;
        }

    }


}

    if(n==4){
        for(m=0;m<t;m++){
            printf("Ozdeger=%d icin olusan matris:\n",oz_deger[m]);
            printf("-----------------------------------------\n");

            fprintf(dosya,"Ozdeger=%d icin olusan matris:\n",oz_deger[m]);
            fprintf(dosya,"-----------------------------------------\n");

            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    yenimatris[i][j]=matris[i][j]-(oz_deger[m]*birim[i][j]);

                    if(m==0){
                        yenimatris1[i][j]=yenimatris[i][j];
                    }
                    else if(m==1){
                        yenimatris2[i][j]=yenimatris[i][j];
                    }
                    else if(m==2){
                        yenimatris3[i][j]=yenimatris[i][j];
                    }
                    else if(m==3){
                        yenimatris4[i][j]=yenimatris[i][j];
                    }

                    printf("%5d",yenimatris[i][j]);
                    fprintf(dosya,"%5d",yenimatris[i][j]);
                }
                printf("\n");
            }
            printf("\n");
    }

    for(m=0;m<t;m++){
        printf("\nOzdeger=%d icin Ozvektorler:\n",oz_deger[m]);
        printf("-----------------------------------------\n");

        fprintf(dosya,"\nOzdeger=%d icin Ozvektorler:\n",oz_deger[m]);
        fprintf(dosya,"-----------------------------------------\n");
        for(a=-5;a<5;a++){
            for(b=-5;b<5;b++){
                for(c=-5;c<5;c++){
                    for(d=-5;d<5;d++){
                        if(a!=0 || b!=0 || c!=0 || d!=0){
                            if(m==0){
                                toplam1=(yenimatris1[0][0]*a)+(yenimatris1[0][1]*b)+(yenimatris1[0][2]*c)+(yenimatris1[0][3]*d);
                                toplam2=(yenimatris1[1][0]*a)+(yenimatris1[1][1]*b)+(yenimatris1[1][2]*c)+(yenimatris1[1][3]*d);
                                toplam3=(yenimatris1[2][0]*a)+(yenimatris1[2][1]*b)+(yenimatris1[2][2]*c)+(yenimatris1[2][3]*d);
                                toplam4=(yenimatris1[3][0]*a)+(yenimatris1[3][1]*b)+(yenimatris1[3][2]*c)+(yenimatris1[3][3]*d);
                            }
                            else if(m==1){
                                toplam1=(yenimatris2[0][0]*a)+(yenimatris2[0][1]*b)+(yenimatris2[0][2]*c)+(yenimatris2[0][3]*d);
                                toplam2=(yenimatris2[1][0]*a)+(yenimatris2[1][1]*b)+(yenimatris2[1][2]*c)+(yenimatris2[1][3]*d);
                                toplam3=(yenimatris2[2][0]*a)+(yenimatris2[2][1]*b)+(yenimatris2[2][2]*c)+(yenimatris2[2][3]*d);
                                toplam4=(yenimatris2[3][0]*a)+(yenimatris2[3][1]*b)+(yenimatris2[3][2]*c)+(yenimatris2[3][3]*d);
                            }
                            else if(m==2){
                                toplam1=(yenimatris3[0][0]*a)+(yenimatris3[0][1]*b)+(yenimatris3[0][2]*c)+(yenimatris3[0][3]*d);
                                toplam2=(yenimatris3[1][0]*a)+(yenimatris3[1][1]*b)+(yenimatris3[1][2]*c)+(yenimatris3[1][3]*d);
                                toplam3=(yenimatris3[2][0]*a)+(yenimatris3[2][1]*b)+(yenimatris3[2][2]*c)+(yenimatris3[2][3]*d);
                                toplam4=(yenimatris3[3][0]*a)+(yenimatris3[3][1]*b)+(yenimatris3[3][2]*c)+(yenimatris3[3][3]*d);
                            }
                            else if(m==3){
                                toplam1=(yenimatris4[0][0]*a)+(yenimatris4[0][1]*b)+(yenimatris4[0][2]*c)+(yenimatris4[0][3]*d);
                                toplam2=(yenimatris4[1][0]*a)+(yenimatris4[1][1]*b)+(yenimatris4[1][2]*c)+(yenimatris4[1][3]*d);
                                toplam3=(yenimatris4[2][0]*a)+(yenimatris4[2][1]*b)+(yenimatris4[2][2]*c)+(yenimatris4[2][3]*d);
                                toplam4=(yenimatris4[3][0]*a)+(yenimatris4[3][1]*b)+(yenimatris4[3][2]*c)+(yenimatris4[3][3]*d);
                            }
                        }


                        if(toplam1==0 && toplam2==0 && toplam3==0 && toplam4==0){
                            printf("(%d,%d,%d,%d) matrisin ozvektorudur.\n",a,b,c,d);
                            fprintf(dosya,"(%d,%d,%d,%d) matrisin ozvektorudur.\n",a,b,c,d);
                        }
                    }
                }
            }
            toplam1=0;
            toplam2=0;
            toplam3=0;
            toplam4=0;

        }
    }
}

    fclose(dosya);
    return 0;

}

int schur(){

    int i,j,t=0,k,n,det=0;
    int birim[MAX][MAX];
    int cikarilacakmatris[MAX][MAX];
    int yenimatris[MAX][MAX];
    int oz_deger[MAX];

    printf("\n\n SCHUR\n\n");

    printf("\n\nKare matrisinizin boyutunu giriniz    :");
    scanf("%d",&n);

    int matris[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Matrisin %d. satir %d. sutun elemanini giriniz   :",i+1,j+1);
            scanf("%d",&matris[i][j]);
        }
    }

    printf("\n\tGirdiginiz Matris\n------------------------------------\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%3d",matris[i][j]);
        }
        printf("\n");
    }


    printf("---------------------------------\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                birim[i][j]=1;
            }
            else
                birim[i][j]=0;
        }
    }

    for(k=-100;k<100;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j){
                    cikarilacakmatris[i][j]=k*birim[i][j];
                }
                else{
                    cikarilacakmatris[i][j]=0;
                }

                yenimatris[i][j]=matris[i][j]-cikarilacakmatris[i][j];
                det=det_bul(yenimatris,n);

            }
        }


        if(det==0){
            printf("Matrisin ozdegeri %d dir.\n",k);
            oz_deger[t]=k;
            t++;
        }
    }


    int karelerToplami=0;
    int lamdakareler=0;

    FILE *dosya=fopen("schur.txt","w");


    for(i=0;i<n;i++){
        lamdakareler=lamdakareler+(oz_deger[i]*oz_deger[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            karelerToplami=karelerToplami+(matris[i][j]*matris[i][j]);
        }
    }


    if(lamdakareler<=karelerToplami){
        printf("\n");
        printf("Schur esitsizligine gore alt sinir %d ve ust sinir %d dir.\n",lamdakareler,karelerToplami);
        fprintf(dosya,"Alt sinir   :%d\n",lamdakareler);
        fprintf(dosya,"Ust sinir   :%d\n",karelerToplami);
    }
    else{
        printf("Schur esitsizligine gore alt sinir %d ve ust sinir %d dir.\n",karelerToplami,lamdakareler);
        fprintf(dosya,"Alt sinir   :%d\n",karelerToplami);
        fprintf(dosya,"Ust sinir   :%d\n",lamdakareler);
    }
    fclose(dosya);

    return 0;
}

int nilpotent(){

     int i,j,n,k,r,elemanlar[10][10],carp[10][10],elemanlar1[10][10];
     int toplam=0;  //-15 ile +15 arasında
     printf("\n\nKare matrisin boyutunu giriniz   :");
     scanf("%d",&n);
     srand(time(NULL));

     FILE *dosya=fopen("nilpotent.txt","w");

     fprintf(dosya,"\tUretilen Matris\n-------------------------\n");

     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          elemanlar[i][j]=-15+rand()%30;
          fprintf(dosya,"%5d",elemanlar[i][j]);
        }
        fprintf(dosya,"\n");
     }
     fprintf(dosya,"----------------------------------\n");

     printf("\tMatrisin Elemanlari\n-----------------------------\n");
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",elemanlar[i][j]);
        }
        printf("\n");
     }
     for(i=0;i<n;i++){
         for(j=0;j<n;j++){
            elemanlar1[i][j]=elemanlar[i][j];
         }
     }
     printf("\tMatrisin Usleri\n------------------------------\n");


    fprintf(dosya,"\tElde Edilen Ara Matrisler\n-------------------------------\n");

    for(r=0;r<4;r++){
        for(i=0; i<n; i++){
          for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                toplam +=elemanlar[i][k] * elemanlar1[k][j];  // Matris çarpma işleminin algoritması
            }
            carp[i][j] = toplam;  // Çıkan sonuc dizinin elemanı olarak yazılır
            toplam = 0;   // Toplam tekrar kullanılacağı için 0 a eşitlenir.
            printf("%10d ",carp[i][j]); // çarpma işlemi yapılan eleman ekrana yazdırılır. //Bunun için farklı bir for döngüsüne ihtiyac yoktur
            elemanlar[i][j]=carp[i][j];

            fprintf(dosya,"%10d",elemanlar[i][j]);
          }


        printf("\n");

        fprintf(dosya,"\n");

        }printf("\n");
        fprintf(dosya,"\n");

    }

    if(elemanlar[i][j]==0){
            printf("Girilen matris nilpotentdir");
            fprintf(dosya,"Girilen matris nilpotentdir");
        }
        else
            printf("Girilen matris nilpotent degildir.");
            fprintf(dosya,"Girilen matris nilpotent degildir.");

        printf("\n\n\n");

    fclose(dosya);

    return 0;
}




