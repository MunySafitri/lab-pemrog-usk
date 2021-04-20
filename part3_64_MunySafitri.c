#include<stdio.h>
int main(){
	char password[30];
	int total_belanja = 0;	
	int nilai;
	char grade;
	char pilihan;
	//printf("");
	printf("masukkan password: ");
	scanf("%s", &password);
	
	if (strcmp(password, "NEKOCHA") ==0){
		printf("Selamat datang Mumun! \n");
		printf("1.program pembayaran \n2.program grade nilai \n=>");
		getchar();
		scanf("%d",&pilihan);
		switch(pilihan){//OPERATOR SWITCHCASE
		case 1:
		printf("==program pembayaran ==\n");
		printf("inputkan total belanja: ");
		scanf("%i", &total_belanja);

		total_belanja>100000? printf("Selamat, anda mendapatkan hadiah! \n"): printf("terimakasih sudah berbelanja  di toko kami \n\n");//OPERATOR TERNARY
		break;
		case 2:
		printf("===Program Grade Nilai \n");
		printf("Inputkan nilai: \n");
		scanf("%i", &nilai );
	
		if (nilai>=90){//operator if, else if, else
			grade= 'A';
		}else if(nilai>=80){
			grade= 'B';\
		}else if (nilai>=70){
		grade = 'B';
		}else if(nilai>=60){
			grade ='C';
		}else if (nilai>=50){
			grade= 'C';
		}else if (nilai>=40){ 
			grade = 'D';
		}else{
			grade= 'F';
		}
		printf("Predikat anda adalah %c", grade);	
		}
	  }
	else{
	printf("password salah, coba lagi \n");
	}
	return 0;
}

