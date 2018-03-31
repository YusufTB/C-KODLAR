#include<stdio.h>

struct ogrenci{
	char name[20];
	int number;
};
struct ogrenci ogr;

void convert(FILE*);
void listele();

int main(){
	int secim;
	FILE*myPtr;
	myPtr=fopen("sirali.txt","w");
	printf("ogrenci ismini ve numarasini giriniz:(cikis icin eof)\n");
	scanf("%s%d",ogr.name,&ogr.number);
	while(!feof(stdin)){
		fprintf(myPtr,"%s %d\n",ogr.name,ogr.number);
		scanf("%s%d",ogr.name,&ogr.number);
	} 
	rewind(myPtr);
	fclose(myPtr);
	printf("Olusturdugunuz sirali dosyayi rastgele cevirmek icin 1 e listelemek icin 2 ye basiniz : \n");
	scanf("%d",&secim);
	switch(secim){
		case 1: convert(myPtr);
			break;
		case 2: listele();
			break;
	}

	return 0;
}
void convert(FILE*myPtr){
	FILE*myPtr2;
	myPtr=fopen("sirali.txt","r");
	myPtr2=fopen("rastgele.txt","w");
	fscanf(myPtr,"%s%d",ogr.name,&ogr.number);
	while(!feof(myPtr)){
		fwrite(&ogr,sizeof(struct ogrenci),1,myPtr2);
		fscanf(myPtr,"%s%d",ogr.name,&ogr.number);
	}
	rewind(myPtr2);
	fclose(myPtr2);
}
void listele(){
	FILE*myPtr;
	myPtr=fopen("rastgele.txt","r");
	fread(&ogr,sizeof(struct ogrenci),1,myPtr);
	while(!feof(myPtr))
	{
		printf("%s %d\n",ogr.name,ogr.number);
		fread(&ogr,sizeof(struct ogrenci),1,myPtr);
	}
	fclose(myPtr);
}
