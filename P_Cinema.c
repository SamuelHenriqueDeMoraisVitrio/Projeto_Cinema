//Criar um filme
//Escolher a quantidade de assentos
//decidir horario de começo do fim
//guardar informações em  um txt
#include <stdio.h>//para print e scan
#include <stdbool.h>//cria a tipagem boleana
#include <unistd.h>//trabalha de forma externa no terminal como sleep(para linux)
#include <stdlib.h>//comandos no terminal
#include <string.h>//Trabalha com string

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

    short linhas = NULL;
    short colunas = NULL;
    printf("\nQuantas colunas?\n");
    scanf("%hd", &colunas);
    sleep(1);
    printf("\nQuantas linhas?\n");
    scanf("%hd", &linhas);
    printf("\n\n%hd\n\n", colunas * linhas);
};