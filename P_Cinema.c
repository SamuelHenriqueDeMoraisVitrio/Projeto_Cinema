//Criar um filme
//Escolher a quantidade de assentos
//decidir horario de começo do fim
//guardar informações em  um txt
#include <stdio.h>//para print e scan
#include <stdbool.h>//cria a tipagem boleana
#include <unistd.h>//trabalha de forma externa no terminal como sleep(para linux)
#include <stdlib.h>//comandos no terminal
#include <string.h>//Trabalha com string

/*
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
*/

struct valorAssento{//a quantidade de assentos
    short nome;//nome de cada poltrona
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
    
    for(int i = 0; i < colunas; i++){
        for (int j = 0; j < linhas; j++){
            PosiAssento[i][j].nome = j + 1;
        };
    };
    for(int i = 0; i < colunas; i++){
        for (int j = 0; j < linhas; j++){
            PosiAssento[i][j].vaga = false;
        };
    };

    short qtdBancoPAlugar = 0;
    do{
        printf("Você quer alugar quantos bancos?");
        scanf("%hd", &qtdBancoPAlugar);

        if(qtdBancoPAlugar < 1){
            return 0;
        }else if(qtdBancoPAlugar < colunas * linhas && qtdBancoPAlugar >= 1){
            break;
        }else if(qtdBancoPAlugar > colunas * linhas){
            system("clear");
            printf("Não temos tantos bancos, sorry");
            sleep(2);
        }else if(qtdBancoPAlugar == colunas * linhas){
            printf("\n\nVocê alugou todos bancos.\n\n");
            for(int i = 0; i < colunas; i++){
                for (int j = 0; j < linhas; j++){
                    PosiAssento[i][j].vaga = true;
                };
            };
            return 0;
        };
    }while(true);

    for(int l = 1; l <= qtdBancoPAlugar; l++){
        system("clear");
        short bancoAC = NULL;
        short bancoAL = NULL;
        while(true){
            printf("\n\nVai alugar o banco e qual coluna, lembrando que temos somente %hd colunas.\n", colunas);
            scanf("%hd", &bancoAC);
            if(bancoAC < 1 || bancoAC > colunas){
                printf("\nEsse numero não é valido.\n");
            }else{
                break;
            };
        };
        while(true){
            printf("\n\nVai alugar o banco e qual linha, lembrando que temos somente %hd linhas.\n", linhas);
            scanf("%hd", &bancoAL);
            if(bancoAL < 1 || bancoAL > linhas){
                printf("\nEsse numero não é valido.\n");
            }else{
                break;
            };
        };

        if(PosiAssento[bancoAC][bancoAL].vaga){
            printf("Este ja foi alugado. Tente outro");
            qtdBancoPAlugar--;
        }else{
            PosiAssento[bancoAC][bancoAL].vaga = true;
        };
    };

    //printf("\n\n\n%hd\n\n\n", PosiAssento[colunas - 1][linhas - 1].nome);
};