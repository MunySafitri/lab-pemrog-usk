#include<stdio.h>
int main(){
	char a[256];
	char cari;
	char ganti;
	char *kata;
	printf("masukkan sebuah string: ");
	scanf(" %[^\n]",a);
	kata=a;
	getchar();
	printf("huruf yang ingin diganti: ");
	scanf("%c",&cari);
	getchar();
	printf("menjadi huruf: ");
	scanf("%c",&ganti);
	
	for(;*kata!='\0';kata++){
		char temp=*kata;
		if (temp==cari){
			*kata=ganti;
		putchar(*kata);
		}else{
		putchar(*kata);
		}
	}
	printf("\n");
}

