#include<stdio.h>
#include<stdlib.h>
#include <errno.h>
#include<string.h>
extern int errno;

typedef struct str{
    int num;
    char kata[1024];
    float des;
}string;
int main(int argc, char* argv[]){
    if (argc == 1){//program akan menampilkan cara jika argc==1
        printf("Dibutuhkan file .txt untuk menjalankan program ini..\n");
        printf("contoh untuk menulis file text ke bin\n");
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt\n");
        printf("contoh untuk membaca file hasil nama_file.txt ke nama_file.bin\n");
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt read\n");
        return EXIT_FAILURE;

    }else if (argc > 4 ){//program akan memberitahu kesalahan command line
        printf("command yang anda masukkan salah!\n");
        printf("Contoh penggunaan command yang benar :"); 
        printf("contoh untuk menulis file text ke bin\n");
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt\n");
        printf("contoh untuk membaca file hasil nama_file.txt ke nama_file.bin\n");
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt read\n");
        return EXIT_FAILURE;
    }
    //untuk mengecek apakah  user memberi ekstensi file yang benar
    char *s = strrchr(argv[1],'.');
    char *t = strrchr(argv[2],'.');
    if(strcmp(s,".txt")!=0){
        printf("maaf, nama file anda bukan format .txt\n");
        return EXIT_FAILURE;
    }else if (strcmp(t,".bin")!=0){
        printf("maaf, nama file anda bukan format .bin\n");
        return EXIT_FAILURE;
    }
    //jika file ga ada.. maka akan error
    FILE* finp = fopen(argv[1],"r");
    if (finp == NULL) {
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror(argv[1]);
        return EXIT_FAILURE;
    }
    FILE* foup;
    char kalimat[1024];
    if(argc == 3 ){//juka argc==3 maka akan dijalankan program menulis file .txt ke dalam binary
        foup= fopen(argv[2],"wb");
    	while(fgets(kalimat,1000,finp)){
        	fwrite(kalimat, sizeof(char), sizeof(kalimat)/sizeof(char), foup);
    	}
       printf("Berhasil Menginput data ke %s\n",argv[2]);
    }else if (argc== 4 && strcmp(argv[3],"read")==0){//program untuk membaca isi file binary 
        foup= fopen(argv[2],"rb");
     	while(fread(kalimat, sizeof(char), sizeof(kalimat)/sizeof(char), foup)){
     		printf("%s",kalimat);   
        }
        printf("\n");
	}else{
        printf("command yang anda masukkan salah!\n");
        return EXIT_FAILURE;
    }
    fclose(finp);
    fclose(foup);   

    return EXIT_SUCCESS;  
}
   
