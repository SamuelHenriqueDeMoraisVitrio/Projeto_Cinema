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

int main(){//função principal

    system("clear");//apaga terminal

    printf("\n Qual nome do Filme? com no max 10 caracters\n");
    char nomeFilm[101];//nome do filme
    fgets(nomeFilm, sizeof(nomeFilm), stdin);//le no terminal o nome
    nomeFilm[strcspn(nomeFilm, "\n")] = '\0';//coloca o fim na string

    sleep(1);//espera 1 segundo
    system("clear");//apaga terminal

    short linhas = 0;
    short colunas = 0;
    do{
        printf("\nQuantas colunas? com no maximo 26 colunas\n");
        scanf("%hd", &colunas);//lê a quantidade de colunas escolhidas
        if(colunas > 26 || colunas < 1){//caso dê erro
            printf("Você digitou o numero errado, tente novamente.");
            sleep(1.5);
        }else{
            break;//sai do while
        };
    }while(true);//sempre como verdadeiro
    
    do{
        sleep(1);//espera 1 segudo
        printf("\nQuantas linhas?\n");
        scanf("%hd", &linhas);//lê a quantidade de linhas escolhidas
        if(linhas < 1){//se a quantidade for igual a zero ou negativa
            printf("Você digitou o numero errado, tente novamente.");
            sleep(1.5);
        }else{
            break;//sai do while
        };
    }while(true);

    sleep(2.5);

    struct valorAssento PosiAssento[colunas][linhas];//cria um array com 2 dimensôes dentro da estrutura 'valorAssento'
    
    for(int i = 0; i < colunas; i++){//escrevi o nome e cada coluna
        for (int j = 0; j < linhas; j++){//escrevi o nome de cada linha
            PosiAssento[i][j].nome = j + 1;
        };
    };

    for(int i = 0; i < colunas; i++){//coloca todas poltronas como falsa de começo
        for (int j = 0; j < linhas; j++){
            PosiAssento[i][j].vaga = false;
        };
    };

    short qtdBancoPAlugar = 0;
    do{
        printf("Você quer alugar quantos bancos?");
        scanf("%hd", &qtdBancoPAlugar);

        if(qtdBancoPAlugar < 1){//finaliza codigo caso não queira alugar nenhum banco
            return 0;
        }else if(qtdBancoPAlugar < colunas * linhas && qtdBancoPAlugar >= 1){//caso a quantidadeEscolhida < quantidade de poltronas disponiveis sai do while
            break;
        }else if(qtdBancoPAlugar > colunas * linhas){//caso exsede o numero de poltronas
            system("clear");
            printf("Não temos tantos bancos, sorry");
            sleep(2);
        }else if(qtdBancoPAlugar == colunas * linhas){//caso alugue todas poltronas
            printf("\n\nVocê alugou todos bancos.\n\n");
            for(int i = 0; i < colunas; i++){//lista todas poltronas como verdadeiro/alugadas
                for (int j = 0; j < linhas; j++){
                    PosiAssento[i][j].vaga = true;
                };
            };
            return 0;
        };
    }while(true);

    for(int l = 1; l <= qtdBancoPAlugar; l++){//escolhe as poltronas de acordo com as colunas e linhas
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
            l = l - 1;//para repetir o for mais uma vez
        }else{
            PosiAssento[bancoAC][bancoAL].vaga = true;
        };
    };

};