#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct node{
	int no;
	int kuyrugaGiris;  // kuyruga giris dakikasini tutan degisken
	struct node *next;
};
struct queue{
	struct node *front;
	struct node *rear;
	int cnt;
};
struct gise{
	int musteriSayisi;
	int toplamSureGise;    // gisenin toplam hizmet suresi
	int durum;     // gisede müsteri olup olmadýgýný kontrol eden degisken
};
typedef struct node node;
typedef struct queue queue;
typedef struct gise gise;

queue *q;
int maxMusteri=0;
int maxBekleme=-1;
int toplamGecenSure;
int ekstraSure=0;
int musteriToplamBekleme=0;
int kuyrugaGirenMusteri=0;

void enqueue(musteriNo,kGiris){
	node *temp;
	if(q->cnt==0){
		temp=(node*)malloc(sizeof(node));
		temp->no=musteriNo;
		temp->kuyrugaGiris=kGiris;
		q->front=q->rear=temp;
	}
	else{
		temp=(node*)malloc(sizeof(node));
		temp->no=musteriNo;
		temp->kuyrugaGiris=kGiris;
		q->rear->next=temp;
		q->rear=temp;
	}
	q->cnt++;
	if(q->cnt>maxMusteri){
		maxMusteri=q->cnt;
	}
}
int dequeue(){
	int musteriNo;
	if(((toplamGecenSure)+(ekstraSure))-(q->front->kuyrugaGiris)>maxBekleme){
		maxBekleme=(toplamGecenSure)+(ekstraSure)-(q->front->kuyrugaGiris);
		}
	if(((toplamGecenSure)+(ekstraSure)-(q->front->kuyrugaGiris))>0){
			musteriToplamBekleme+=(toplamGecenSure)+(ekstraSure)-(q->front->kuyrugaGiris);
			kuyrugaGirenMusteri++;
		}
	musteriNo=q->front->no;
	q->front=q->front->next;
	q->cnt--;
	return musteriNo;
}

int main(){
	q=(queue*)malloc(sizeof(queue));
	q->front=q->rear=NULL;
	q->cnt=0;
	gise gise1,gise2,gise3;
	gise1.durum=0; gise2.durum=0; gise3.durum=0;
	gise1.musteriSayisi=0;  gise2.musteriSayisi=0;  gise3.musteriSayisi=0;
	gise1.toplamSureGise=0;  gise2.toplamSureGise=0;  gise3.toplamSureGise=0;
	
	int i=0,gecenSure=0,toplamSure,musteriSure,musteriNo=1,kontrol=0;
	int islemTipi1,islemSuresi1,islemGecenSure1=0,giseDekiMusteri1;
	int islemTipi2,islemSuresi2,islemGecenSure2=0,giseDekiMusteri2;
	int islemTipi3,islemSuresi3,islemGecenSure3=0,giseDekiMusteri3;
	printf("program suresini giriniz:\n");	scanf("%d",&toplamSure);
	srand(time(NULL));
	printf("\n* * * BANKANIN ACILISI * * *\n\n");
	while(toplamGecenSure!=toplamSure || gise1.durum==1 || gise2.durum==1 || gise3.durum==1){  // her dongu 1 dakikaya esit
		if(toplamGecenSure==toplamSure && kontrol==0){
			printf("* * * BANKAMIZIN KAPISI KAPATILMISTIR! ( ICERIDEKI MUSTERILERIN ISLEMI BITIRILECEKTIR ) * * *\n");
			kontrol++;
		}
		if(toplamGecenSure!=toplamSure){ // banka aciksa musteri gelisi devam edicek
			if(gecenSure==0){  // kendi icinde bir sayiciyla musteri gelis zamanini random alma
				musteriSure=rand()%6;
			}
			if(gecenSure==musteriSure){   // zamani gelen musterinin bankaya gelmesi
				printf("--- %d nolu musteri bankaya %d dakika sonra geldi ---\n",musteriNo,toplamGecenSure);
				enqueue(musteriNo,toplamGecenSure);
				musteriNo++;
				gecenSure=0;
			}
			else{
				gecenSure++;
			}
		}
		if(gise1.durum==1){   // gise musteri olma durumunu kontrol eden kosul
			if(islemGecenSure1==islemSuresi1){ // kendi icinde bir sayiciyla musterinin isleminin bitip bitmedigini kontrol eden kosul
				if(ekstraSure!=0){ // ekstra sure bankanin kapisi kapandiktan sonra tuttugum zaman
					printf("%d nolu musteri %d dakika sonra [1].giseden ayrilmistir.\n",giseDekiMusteri1,toplamGecenSure+ekstraSure);
				}
				else{
					printf("%d nolu musteri %d dakika sonra [1].giseden ayrilmistir.\n",giseDekiMusteri1,toplamGecenSure);
				}
				gise1.toplamSureGise+=islemGecenSure1;
				islemGecenSure1=0;
				gise1.durum=0;
			}
			else{
				islemGecenSure1++;
			}
		}
		if(gise1.durum==0 && q->cnt!=0){ // gise boþsa ve kuyrukta musteri varsa giseye musteri almayi kontrol eden kosul
			
			giseDekiMusteri1=dequeue();
			if(ekstraSure!=0){
				printf("%d nolu musteri %d dakika sonra [1] nolu gisede islem yapmaya baslamistir.\n",giseDekiMusteri1,toplamGecenSure+ekstraSure);
			}
			else{
				printf("%d nolu musteri %d dakika sonra [1] nolu gisede islem yapmaya baslamistir.\n",giseDekiMusteri1,toplamGecenSure);
			}
			gise1.musteriSayisi++;
			islemTipi1=rand()%4+1;
			if(islemTipi1==1){    // EFT
			    islemSuresi1=rand()%8+3;
			}
			if(islemTipi1==2){   // KREDÝ CEKME
				islemSuresi1=rand()%11+10;
			}
			if(islemTipi1==3){   // FATURA ODEME
				islemSuresi1=rand()%11+2;
			}
			if(islemTipi1==4){	// PARA CEKME
				islemSuresi1=rand()%7+1;
			}
			gise1.durum=1;
		}
		if(gise2.durum==1){  // ilk gisede yaptigim islemlerin aynisi kodlamasi kolay olsun diye tekrarladým
			if(islemGecenSure2==islemSuresi2){
				if(ekstraSure!=0){
					printf("%d nolu musteri %d dakika sonra [2].giseden ayrilmistir.\n",giseDekiMusteri2,toplamGecenSure+ekstraSure);
				}
				else{
					printf("%d nolu musteri %d dakika sonra [2].giseden ayrilmistir.\n",giseDekiMusteri2,toplamGecenSure);
				}
				gise2.toplamSureGise+=islemGecenSure2;
				islemGecenSure2=0;
				gise2.durum=0;
			}
			else{
				islemGecenSure2++;
			}
		}
		if(gise2.durum==0 && q->cnt!=0){
			giseDekiMusteri2=dequeue();
			if(ekstraSure!=0){
				printf("%d nolu musteri %d dakika sonra [2] nolu gisede islem yapmaya baslamistir.\n",giseDekiMusteri2,toplamGecenSure+ekstraSure);
			}
			else{
				printf("%d nolu musteri %d dakika sonra [2] nolu gisede islem yapmaya baslamistir.\n",giseDekiMusteri2,toplamGecenSure);
			}
			gise2.musteriSayisi++;
			islemTipi2=rand()%4+1;
			if(islemTipi2==1){    // EFT
			    islemSuresi2=rand()%8+3;
			}
			if(islemTipi2==2){   // KREDÝ CEKME
				islemSuresi2=rand()%11+10;
			}
			if(islemTipi2==3){   // FATURA ODEME
				islemSuresi2=rand()%11+2;
			}
			if(islemTipi2==4){	// PARA CEKME
				islemSuresi2=rand()%7+1;
			}
			gise2.durum=1;
		}
		if(gise3.durum==1){
			if(islemGecenSure3==islemSuresi3){
				if(ekstraSure!=0){
					printf("%d nolu musteri %d dakika sonra [3].giseden ayrilmistir.\n",giseDekiMusteri3,toplamGecenSure+ekstraSure);
				}
				else{
					printf("%d nolu musteri %d dakika sonra [3].giseden ayrilmistir.\n",giseDekiMusteri3,toplamGecenSure);
				}
				gise3.toplamSureGise+=islemGecenSure3;
				islemGecenSure3=0;
				gise3.durum=0;
			}
			else{
				islemGecenSure3++;
			}
		}
		if(gise3.durum==0 && q->cnt!=0){
			giseDekiMusteri3=dequeue();
			if(ekstraSure!=0){
				printf("%d nolu musteri %d dakika sonra [3] nolu gisede islem yapmaya baslamistir.\n",giseDekiMusteri3,toplamGecenSure+ekstraSure);
			}
			else{
				printf("%d nolu musteri %d dakika sonra [3] nolu gisede islem yapmaya baslamistir.\n",giseDekiMusteri3,toplamGecenSure);
			}
			gise3.musteriSayisi++;
			islemTipi3=rand()%4+1;
			if(islemTipi3==1){    // EFT
			    islemSuresi3=rand()%8+3;
			}
			if(islemTipi3==2){   // KREDÝ CEKME
				islemSuresi3=rand()%11+10;
			}
			if(islemTipi3==3){   // FATURA ODEME
				islemSuresi3=rand()%11+2;
			}
			if(islemTipi3==4){	// PARA CEKME
				islemSuresi3=rand()%7+1;
			}
			gise3.durum=1;
		}
		if(toplamGecenSure==toplamSure){ // programin suresi bitince son musteriler icin ekstra zamani devreye soktum
			ekstraSure++;
		}
		else{
			toplamGecenSure++;
		}
	}
	printf("* * * BANKAMIZ TAMAMIYLE KAPATILMISTIR! * * *\n");
	printf("\n\n * * * ISTATISTIKLER * * * \n\n");
	if(gise1.musteriSayisi==0){
		printf("1.Giseye hic musteri gelmemistir.\n\n");
	}
	else{
		printf("1.giseye gelen toplam musteri sayisi : %d dir.\n",gise1.musteriSayisi);
		printf("1.gisenin bir musteriye ortalama hizmet verme suresi : %d dir.\n\n",(gise1.toplamSureGise)/(gise1.musteriSayisi)+1);
	}
	if(gise2.musteriSayisi==0){
		printf("2.Giseye hic musteri gelmemistir.\n\n");
	}
	else{
		printf("2.giseye gelen toplam musteri sayisi : %d dir.\n",gise2.musteriSayisi);
		printf("2.gisenin bir musteriye ortalama hizmet verme suresi : %d dir.\n\n",(gise2.toplamSureGise)/(gise2.musteriSayisi)+1);
	}
	if(gise3.musteriSayisi==0){
		printf("3.Giseye hic musteri gelmemistir.\n\n");
	}
	else{
		printf("3.giseye gelen toplam musteri sayisi : %d dir.\n",gise3.musteriSayisi);
		printf("3.gisenin bir musteriye ortalama hizmet verme suresi : %d dir.\n\n",(gise3.toplamSureGise)/(gise3.musteriSayisi)+1);
	}
	if(maxBekleme==0){
		printf("herhangi bir zamanda kuyrukta bekleyen en fazla musteri sayisi : 0 dir\n");
	}
	else{
		printf("herhangi bir zamanda kuyrukta bekleyen en fazla musteri sayisi : %d dir\n",maxMusteri);
	}
	printf("Kuyrukta en uzun bekleyen musterinin bekleme suresi : %d dir.\n",maxBekleme);
	if(kuyrugaGirenMusteri!=0){
		printf("Bir musterinin ortalama kuyrukta bekleme suresi : %d dir\n",(musteriToplamBekleme)/(kuyrugaGirenMusteri));
	}
	else{
		printf("Bir musterinin ortalama kuyrukta bekleme suresi : 0 dir\n");
	}
}
