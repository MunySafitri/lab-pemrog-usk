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
    if (argc == 1){
        printf("Dibutuhkan file .txt untuk menjalankan program ini..\n");
        printf("contoh untuk menulis file text ke bin\n");
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt\n");
        printf("contoh untuk membaca file hasil nama_file.txt ke nama_file.bin\n");
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt read\n");
        return EXIT_FAILURE;

    }else if (argc > 4 ){
        printf("command yang anda masukkan salah!\n");
        printf("Contoh penggunaan command yang benar :"); 
        printf("contoh untuk menulis file text ke bin\n");
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt\n");
        printf("contoh untuk membaca file hasil nama_file.txt ke nama_file.bin\n");
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt read\n");
        return EXIT_FAILURE;
    }
    char *s = strrchr(argv[1],'.');
    //printf("%s",s);
    char *t = strrchr(argv[2],'.');
    //printf("%s",t);
    if(strcmp(s,".txt")!=0){
        printf("maaf, nama file anda bukan format .txt\n");
        return EXIT_FAILURE;
    }else if (strcmp(t,".bin")!=0){
        printf("maaf, nama file anda bukan format .bin\n");
        return EXIT_FAILURE;
    }
    
    FILE* finp = fopen(argv[1],"r");
    if (finp == NULL) {
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror(argv[1]);
        return EXIT_FAILURE;
    }
    char c;
    int jumlah=0;
    while(!feof(finp)){
        c = getc(finp);
         if (c=='\n') jumlah++;       
     }  
    jumlah++;  
    rewind(finp);
    
    string data[jumlah];
    int i=0;
    FILE* foup;
    if(argc == 3 ){
        // printf("sampai disini\n");
        foup  = fopen(argv[2],"wb");
        
        while(!feof(finp)){
        //for ( i = 0; i < jumlah; i++) {
            fscanf(finp, " %d \"%[^\"]\" %f", &data[i].num, data[i].kata, &data[i].des);
            fwrite(&data[i].num, sizeof(data[i].num), 1, foup);
            fwrite(data[i].kata, sizeof(data[i].kata), 1, foup);
            fwrite(&data[i].des, sizeof(data[i].des), 1, foup);  
            //printf("%d",i);
            i++;
        }
        printf("Berhasil Menginput data ke %s\n",argv[2]);
    }else if (argc== 4 && strcmp(argv[3],"read")==0){
        foup = fopen(argv[2], "rb");
        for( i = 0; i <jumlah; i++){
            fread (&data[i], sizeof(struct str), jumlah, foup);
            printf("%d %s %.2f\n", data[i].num, data[i].kata, data[i].des);
        }
           
    }else{
        printf("command yang anda masukkan salah!\n");
    }
    fclose(finp);
    fclose(foup);   

    return EXIT_SUCCESS;  
}