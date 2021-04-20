#include<stdio.h>
#include<stdlib.h>
int main(){
	char ibu[20],ayah[20],food[20],hoby[20];
	int saudara,tahun;
	printf("masukkan nama ibu anda: \n");
	printf("=>");
	scanf(" %[^\n]s",ibu);
	printf("masukkan nama ayah anda: \n");
	printf("=>");
	scanf(" %[^\n]s",ayah);
	printf("masukkan jumlah saudara anda: \n");
	printf("=>");
	scanf(" %d",&saudara);
	printf("apa makanan favorit anda? \n ");
	printf("=>");
	scanf(" %[^\n]s",food);
	printf("masukkan tahun lahir anda: \n"); 
	printf("=>");
	scanf(" %d",&tahun);
	printf("apa hoby anda? \n");
	printf("=>");
	scanf(" %[^\n]s",hoby);
	getchar();
	
	printf("Nama ibu dan ayah anda adalah %s dan %s \n",ibu,ayah);
	printf("anda memiliki jumlah saudara sebanyak %d dan anda lahir pada tahun %d",saudara,tahun);
	printf(" makanan kesukaan dan hobby anda adalah %s dan %s", food,hoby);
	return 0;
	
}
