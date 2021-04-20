#include<stdio.h>
#include<ctype.h>
#define Kelvin 273 //konstanta
int main(){
	const double Reamur = 0.8;//konstanta
	float suhu;
	float Suhu;
	float reamur;
	float fahren;
	float kelvin;
	char answer,Answer;
	int i=0,angka;
	
	do{
	printf("Masukkan Suhu dalam Celcius: ");
	scanf("%f",&suhu);
	Suhu=(float)suhu;
	printf("Hasil Konversi %.2f celcius ialah: \n", Suhu);
	reamur= (float)suhu*Reamur;//casting
	printf("\t Reamur: %.2f \n",reamur);
	fahren= ((float)suhu*9/5)+32;//casting
	printf("\t Fahrenheit : %.2f \n", fahren);
	kelvin= (float)suhu + Kelvin;//casting
	printf("\t Kelvin : %.2f \n", kelvin);
	
	printf("\n");
	printf("apakah anda ingin konversi lagi (Y/N): ");
	scanf("%s", &answer);
	
	if(toupper(answer)=='Y'){
		continue;		
	}if (toupper(answer)=='N'){
		break;
	}else{
		do{
			if (toupper(answer)=='N'){
				break;
		}printf("\nmasukkan input dengan benar: ");
		scanf("%s",&answer);
		}while(toupper(answer)!= 'Y' );
	  }
	} while(toupper(answer)=='Y');
	
	printf("ingin dapat hadiah?(y/n)");
	printf("=>");
	getchar();
	scanf("%c",&Answer);
	
	if(Answer=='y'){
		do{
			if(i==3){
				printf("kesempatan anda sudah habis\n");
				printf("Terimakasih telah menggunakan aplikasi ini..");
				break;
			}else if(angka==198){
				printf("Selamat!, anda mendapatkan hadiah!\n");
				printf("silahkan hubungi 08010023410 untuk pengambilan hadiah");
				break;	
			}
		printf("sebutkan angka yang dimaksud pada angka biner dibawah ini: \n");
		printf("11000110 \n=>");
		scanf("%d",&angka);	
		i++; //increment
	}while(angka!=198);
	if(angka==198){
				printf("Selamat!, anda mendapatkan hadiah!\n");
				printf("\nsilahkan hubungi 08010023410 untuk pengambilan hadiah");
			}
	}else if(tolower(Answer)=='n'){
		printf("Terimakasih telah menggunakan aplikasi ini..");
	}
	return 0;
	
}
