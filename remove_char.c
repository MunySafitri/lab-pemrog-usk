#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
    if (argc != 4){//jika argc buka 4 , maka command yng dijalankan tidak benar
        printf("command yang anda masukkan salah!\n");
        printf("Contoh penggunaan command yang benar :"); 
        printf("./NamaProgramYangDituju inputFile.txt OutputFile.txt Karkater_yang_dihapus\n");
        return EXIT_FAILURE;
    }
    FILE* finp;
    FILE* foup;
    finp=(fopen(argv[1],"r"));
    foup=(fopen(argv[2],"w"));
    char c,character= argv[3][0];
    if(finp==NULL){//program untuk membaca apakah file input ada pada storage
        printf("Program input yang anda masukkan salah!.\n");
        return EXIT_FAILURE;
    }
    while((c=fgetc(finp))!= EOF){//menghilangkan karakter tertentu dan tulis ke file output.txt
        if(c==character){
            continue;
        }
        fputc(c,foup);
    } 
    printf("berhasil menghilangkan '%c'\n",character); 
    fclose(finp);
    fclose(foup);
}
