#include<bits/stdc++.h>
using namespace std;

double f1(double,double);
double f2(double);
double nr(double);

int main(){
    FILE *fptr;
    char filename[20],ch;
    printf("\nEnter filename");
    scanf("%s",filename);
    fptr = fopen(filename,"r");
    if(fptr == NULL)
        printf("File does not exist");
    else{
        char binop[] = {'+','-','*','/','<','=','>'};
        char unop[] = {',',';','.','{','[','(','}',']',')'};

        int totalbinop=0,totalunop=0,uniquebinop=0,uniqueunop=0,bincount[8],uncount[8];
        for(int i=0;i<8;++i) bincount[i]=0,uncount[i]=0;

        ch = fgetc(fptr);
        while(ch != EOF){
            for(int i=0;i<8;++i){
                if(ch == binop[i]){
                    bincount[i]++;
                    totalbinop++;
                }
                if(ch == unop[i]){
                    uncount[i]++;
                    totalunop++;
                }
            }
            ch = getc(fptr);
        }
        fclose(fptr);
        for(int i=0;i<8;++i){
            if(bincount[i] != 0)  uniquebinop++;
            if(uncount[i] != 0)   uniqueunop++;
        }
        fptr = fopen(filename,"r");
        char check[50];
        int scount[10];
        for(int i=0;1<10;++i)    scount[i] = 0;

        char str1[] = "int";
        char str2[] = "float";
        char str3[] = "main";
        char str4[] = "printf";
        char str5[] = "scanf";
        char str6[] = "++";
        char str7[] = "--";
        char str8[] = "<=";
        char str9[] = ">=";
        char str10[] = "==";
        char *p1,*p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9,*p10;
        while(fgets(check,50,fptr) != NULL){
            p1 = strstr(check,str1);
            if(p1){
                scount[0]++;
                totalunop++;
            }
            p6 = strstr(check,str6);
            if(p6){
                scount[5]++;
                totalbinop++;
            }
        }
        for(int i=0;i<5;++i)
            if(scount[i] != 0)
                uniqueunop++;
        for(int i=5;i<10;++i)
            if(scount[i] != 0)
                uniquebinop++;
        int totaluniqueop = uniqueunop + uniquebinop;
        int totalop = totalbinop + totalunop;
        int totaloperand = 2*totalbinop + totalunop;
        int N = totalop + totaloperand;
        float a = N - totaluniqueop*log(totaluniqueop)/log(2.0);
        double y = nr(a);
        float length = y*log(y)/log(2) + totaluniqueop * log(totaluniqueop)/log(2.0);
        float volume = length*log(totaluniqueop+y)/log(2.0);

    }
}
