//Criar um filme
//Escolher a quantidade de assentos
//decidir horario de começo do fim
//guardar informações em  um txt
#include <stdio.h>//para print e scan
#include <stdbool.h>//cria a tipagem boleana
#include <unistd.h>//trabalha de forma externa no terminal como sleep(para linux)
#include <stdlib.h>//comandos no terminal
#include <string.h>//Trabalha com string

short qtdDeFilms = 0;//quantidades de filmes criadas comessando como uma

struct nomeDoFilm{//estrutura para cada filme
    char nomeF[100];//nome de cada filme
};


struct valorAssento{//a quantidade de assentos
    char nome[2];//nome de cada poltrona
    bool vaga;//vaga da poltrona
};

int main(){

    printf("\n Você quer adicionar um filme? se sim aperte 1 se não aperte 2\n");//para adicionar um filme
    short novoFilm;//guardar decisão
    scanf("%d", &novoFilm);//leitura da decisão

    sleep(1);
    system("clear");

    if(novoFilm == 1){//caso adicione um filme
        printf("\nQual nome do filme?\n");
        struct nomeDoFilm filmes[qtdDeFilms];//declarando array filmes dentro da estrutura nomeDoFilme
        qtdDeFilms++;//almenta quantidade de filmes
    };
};