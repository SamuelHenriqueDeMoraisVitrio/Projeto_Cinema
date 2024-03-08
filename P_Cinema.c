//Criar um filme
//Escolher a quantidade de assentos
//decidir horario de começo do fim
//guardar informações em  um txt
#include <stdio.h>//para print e scan
#include <stdbool.h>//cria a tipagem boleana
#include <unistd.h>//trabalha de forma externa no terminal como sleep(para linux)
#include <stdlib.h>//comandos no terminal
#include <string.h>//Trabalha com string

void selecLetra(){
    char a1 = 'A';
    char a2 = 'B';
    char a3 = 'C';
    char a4 = 'D';
    char a5 = 'E';
    char a6 = 'F';
    char a7 = 'G';
    char a8 = 'H';
    char a9 = 'I';
    char a10 = 'J';
    char a11 = 'K';
    char a12 = 'L';
    char a13 = 'M';
    char a14 = 'N';
    char a15 = 'O';
    char a16 = 'P';
    char a17 = 'Q';
    char a18 = 'R';
    char a19 = 'S';
    char a20 = 'T';
    char a21 = 'U';
    char a22 = 'V';
    char a23 = 'W';
    char a24 = 'X';
    char a25 = 'Y';
    char a26 = 'Z';
};

struct valorAssento{//a quantidade de assentos
    char nome[2];//nome de cada poltrona
    bool vaga;//vaga da poltrona
};

int main(){
    system("clear");

    printf("\n Qual nome do Filme? com no max 10 caracters\n");
    char nomeFilm[101];
    fgets(nomeFilm, sizeof(nomeFilm), stdin);
    nomeFilm[strcspn(nomeFilm, "\n")] = '\0';

    sleep(1);
    system("clear");

    short linhas = 0;
    short colunas = 0;
    do{
        printf("\nQuantas colunas? com no maximo 26 colunas\n");
        scanf("%hd", &colunas);
        if(colunas > 26 || colunas < 1){
            printf("Você digitou o numero errado, tente novamente.");
            sleep(2.5);
        }else{
            break;
        };
    }while(true);
    
    do{
        sleep(1);
        printf("\nQuantas linhas?\n");
        scanf("%hd", &linhas);
        if(linhas < 1){
            printf("Você digitou o numero errado, tente novamente.");
            sleep(2.5);
        }else{
            break;
        };
    }while(true);

sleep(5);

    struct valorAssento PosiAssento[colunas][linhas];
    strcpy(PosiAssento[0][0].nome, "A1");
    //PosiAssento[0][0].nome = "A1";

    printf("\n\n\n%s\n\n\n", PosiAssento[0][2].nome);
    /*
    for(int i = 0; i <= colunas; i++){

        //valorAssento[i][0].nome = 
    };*/
};