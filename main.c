#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct DataMainan{
    char brand[20];
    char kategori[80];
    char seri[50];
    char skala[50];
    int status;
} dataMainan;

int main() {
    dataMainan *ptr;
    FILE *pfile;
    int i=0,j=225,k=0,l=-1,m=0,pilihan=0;
    char username[225],password[225],login[225],akun[225],baris[225],baris1[225],token[2]=",",*ptoken,konfirmasi,brand[20],kategori[80],seri[50],skala[50],brand_ubah[20];

    printf("\n========= SILAHKAN LOGIN ===========\n");
    while(1){
        printf("Username: ");
        scanf("%s",username);
        getchar();
        printf("Password: ");
        scanf("%s",password);
        getchar();
        strcpy(login,strcat(strcat(username,"@"),password));
       
        pfile = fopen("data/login.bin","r");
        while(fgets(baris1,225,pfile)!=NULL){
            strcpy(akun,baris1);
        }
        fclose(pfile);
        
        //cek apakah login sama dengan akun di data/login.bin
        if(strcmp(akun,login)==0){
            //buat struct array ukuran 225
            ptr=(dataMainan *)malloc(j * sizeof(dataMainan));

            //baca file data/data.txt dan masukkan ke struct
            pfile = fopen("data/data.txt","r");
            while(fgets(baris,225,pfile)!=NULL){
                if(l>=0){
                    ptoken=strtok(baris,token);
                    while(ptoken!=NULL){
                        if(m==0){
                            strcpy((ptr+l)->brand,ptoken);
                        }
                        else if(m==1){
                            strcpy((ptr+l)->kategori,ptoken);
                        }
                        else if(m==2){
                            strcpy((ptr+l)->seri,ptoken);
                        }
                        else if(m==3){
                            strcpy((ptr+l)->skala,ptoken);
                            (ptr+l)->status=1;
                        }
                        ptoken=strtok(NULL,token);
                        m++;
                    }
                    m=0; k++;
                }
                l++;
            }
            fclose(pfile);

            //mulai program
            while(1){
                printf("\n========= SELAMAT DATANG ADMIN ===========\n");
                printf("\nMENU:\n");
                printf("1. Tampilkan Data Mainan\n");
                printf("2. Cari Data Mainan\n");
                printf("3. Tambah Data Mainan\n");
                printf("4. Hapus Data Mainan\n"); 
                printf("5. Ubah Data Mainan\n");
                printf("6. Keluar\n");
                printf("\nPilihan: ");
                scanf("%d",&pilihan);
                getchar();
                switch(pilihan){
                    case 1: 
                        printf("\nDATA MAINAN\n");
                        for (i=0;i<225;i++){
                            if(strcmp((ptr+i)->brand,"")!=0 && (ptr+i)->status==1){
                                printf("%s\t%s\t%s\t%s\n",(ptr+i)->brand,(ptr+i)->kategori,(ptr+i)->seri,(ptr+i)->skala);
                            }
                        }
                        continue;
                    case 2:
                        printf("\nCARI DATA MAINAN\n");
                        printf("Brand: ");
                        scanf("%s",brand);
                        getchar();
                        for (i=0;i<225;i++){
                            if(strcmp((ptr+i)->brand,brand)==0){
                                printf("%s\t%s\t%s\t%s\n",(ptr+i)->brand,(ptr+i)->kategori,(ptr+i)->seri,(ptr+i)->skala);
                                break;
                            }
                        }
                        continue;
                    case 3:
                        printf("\nTAMBAH DATA MAINAN\n");
                        printf("Brand:");
                        scanf("%s",(ptr+k)->brand);
                        getchar();
                        printf("Kategori:");
                        scanf("%[^\n]s",(ptr+k)->kategori);
                        getchar();
                        printf("Seri:");
                        scanf("%[^\n]s",(ptr+k)->seri);
                        getchar();
                        printf("Skala:");
                        scanf("%[^\n]s",(ptr+k)->skala);
                        getchar();
                        (ptr+k)->status=1;
                        printf("\nStatus: Data berhasil disimpan\n\n");
                        k+=1;
                        continue;
                    case 4:
                        printf("\nHAPUS DATA MAINAN\n");
                        printf("Brand: ");
                        scanf("%s",brand);
                        getchar();
                        printf("\nYakin ingin menghapus %s? (y/n): ",brand);
                        scanf("%c",&konfirmasi);
                        getchar();
                        switch(konfirmasi){
                            case 'y':
                                for (i=0;i<225;i++){
                                    if(strcmp((ptr+i)->brand,brand)==0){
                                        (ptr+i)->status=0; //jika status 0 maka data tersebut sudah dihapus
                                    }
                                }
                                printf("\nStatus: Data berhasil dihapus\n\n");
                                continue;
                            case 'n': break;
                            default: break;
                        } 
                        continue;
                    case 5:
                        printf("\nUBAH DATA MAINAN\n");
                        printf("Brand: ");
                        scanf("%s",brand);
                        getchar();
                        printf("\nApakah ingin mengubah Brand (y/n): ");
                        scanf("%c",&konfirmasi);
                        getchar();
                        switch(konfirmasi){
                            case 'y':
                                printf("Brand: ");
                                scanf("%s",brand_ubah);
                                getchar();
                                for (i=0;i<225;i++){
                                    if(strcmp((ptr+i)->brand,brand)==0){
                                        strcpy((ptr+i)->brand,brand_ubah);
                                        strcpy(brand,brand_ubah);
                                    }
                                }
                                break;
                            case 'n': break;
                            default: break;
                        } 
                        printf("\nApakah ingin mengubah Kategori (y/n): ");
                        scanf("%c",&konfirmasi);
                        getchar();
                        switch(konfirmasi){
                            case 'y':
                                printf("Kategori: ");
                                scanf("%[^\n]s",kategori);
                                getchar();
                                for (i=0;i<225;i++){
                                    if(strcmp((ptr+i)->brand,brand)==0){
                                        strcpy((ptr+i)->kategori,kategori);
                                    }
                                }
                                break;
                            case 'n': break;
                            default: break;
                        } 
                        printf("\nApakah ingin mengubah Seri (y/n): ");
                        scanf("%c",&konfirmasi);
                        getchar();
                        switch(konfirmasi){
                            case 'y':
                                printf("Seri: ");
                                scanf("%[^\n]s",seri);
                                getchar();
                                for (i=0;i<225;i++){
                                    if(strcmp((ptr+i)->brand,brand)==0){
                                        strcpy((ptr+i)->seri,seri);
                                    }
                                }
                                break;
                            case 'n': break;
                            default: break;
                        } 
                        printf("\nApakah ingin mengubah Skala (y/n): ");
                        scanf("%c",&konfirmasi);
                        getchar();
                        switch(konfirmasi){
                            case 'y':
                                printf("Skala: ");
                                scanf("%[^\n]s",skala);
                                getchar();
                                for (i=0;i<225;i++){
                                    if(strcmp((ptr+i)->brand,brand)==0){
                                        strcpy((ptr+i)->skala,skala);
                                    }
                                }
                                break;
                            case 'n': break;
                            default: break;
                        } 
                        printf("\nStatus: Data berhasil diubah\n\n");
                        continue;
                    case 6:
                        pfile = fopen("data/data.txt","w");
                        fprintf(pfile,"Brand,Kategori,Seri,Skala\n");
                        for (i=0;i<225;i++){
                            if(strcmp((ptr+i)->brand,"")!=0 && (ptr+i)->status==1){
                                fprintf(pfile,"%s,%s,%s,%s",(ptr+i)->brand,(ptr+i)->kategori,(ptr+i)->seri,(ptr+i)->skala);
                            }
                        }
                        fclose(pfile);
                        printf("\n========= TERIMAKASIH ADMIN ===========\n"); 
                        break;
                    default: continue;
                }
                printf("\n");
                break;
            }
            free(ptr);
            
            break;
        }
        else{
            printf("\nUsername atau password salah. Login kembali\n");
            continue;    
        }
    }
    return 0;
}