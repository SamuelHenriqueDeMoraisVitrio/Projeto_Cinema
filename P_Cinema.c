//Criar um filme
//Escolher a quantidade de assentos
//decidir horario de começo do fim
//guardar informações em  um txt
#include <stdio.h>//para print e scan
#include <stdbool.h>//cria a tipagem boleana
#include <unistd.h>//trabalha de forma externa no terminal como sleep(para linux)
#include <stdlib.h>//comandos no terminal
#include <string.h>//Trabalha com string


char selecLetra(short letra){
    switch(letra){
        case 1:
            return 'A';
        case 2:
            return 'B';
        case 3:
            return 'C';
        case 4:
            return 'D';
        case 5:
            return 'E';
        case 6:
            return 'F';
        case 7:
            return 'G';
        case 8:
            return 'H';
        case 9:
            return 'I';
        case 10:
            return 'J';
        case 11:
            return 'K';
        case 12:
            return 'L';
        case 13:
            return 'M';
        case 14:
            return 'N';
        case 15:
            return 'O';
        case 16:
            return 'P';
        case 17:
            return 'Q';
        case 18:
            return 'R';
        case 19:
            return 'S';
        case 20:
            return 'T';
        case 21:
            return 'U';
        case 22:
            return 'V';
        case 23:
            return 'W';
        case 24:
            return 'X';
        case 25:
            return 'Y';
        case 26:
            return 'Z';
    };

};

struct valorAssento{//a quantidade de assentos
    char nome[5];//nome de cada poltrona
    bool vaga;//vaga da poltrona
    short numColum;
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
    
    short numLetra = 0;
    for(int i = 0; i < colunas; i++){//escrevi o nome e cada coluna
        numLetra++;
        char proxLetra = selecLetra(numLetra);
        for (int j = 0; j < linhas; j++){//escrevi o nome de cada linha
            sprintf(PosiAssento[i][j].nome, "%c%d", proxLetra, j + 1);
            PosiAssento[i][j].numColum = (short)j + 1;
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
    printf("\nOs bancos que não foram alugados ainda estão em vermelho\n");
    for(int k = 0; k < colunas; k++){//escrevi o nome e cada coluna
        printf("\n");
        for (int u = 0; u < linhas; u++){//escrevi o nome de cada linha
            if(PosiAssento[k][u].vaga){
            printf("\x1b[32m%s\x1b[0m ", PosiAssento[k][u].nome);
            }else{
            printf("\x1b[31m%s\x1b[0m ", PosiAssento[k][u].nome);
            };
        };
    };
    /*
    printf("\n\n");
    printf("\nOs bancos que não foram alugados ainda estão em vermelho\n");
    for(int i = 0; i < colunas; i++){//escrevi o nome e cada coluna
        printf("\n");
        for (int j = 0; j < linhas; j++){//escrevi o nome de cada linha
            printf("\x1b[31m%hd ", PosiAssento[i][j].numColum);
        };
    };
    printf("\n\n");
    */
        
        short bancoAC = NULL;
        short bancoAL = NULL;
        while(true){
            printf("\n\nVai alugar o banco de qual coluna, lembrando que temos somente %hd colunas.\n", colunas);
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

        if(PosiAssento[bancoAC - 1][bancoAL - 1].vaga){
            printf("Este ja foi alugado. Tente outro");
            l = l - 1;//para repetir o for mais uma vez
        }else{
            PosiAssento[bancoAC - 1][bancoAL - 1].vaga = true;
        };
        sleep(1);
    };

    sleep(2);
    system("clear");

    printf("\n\n");
    printf("******************************\n");
    printf("** %s **\n", nomeFilm);
    printf("******************************\n");
    printf("\n\n");
    for(int k = 0; k < colunas; k++){//escrevi o nome e cada coluna
        printf("\n");
        for (int u = 0; u < linhas; u++){//escrevi o nome de cada linha
            if(PosiAssento[k][u].vaga){
            printf("\x1b[32m%s\x1b[0m ", PosiAssento[k][u].nome);
            }else{
            printf("\x1b[31m%s\x1b[0m ", PosiAssento[k][u].nome);
            };
        };
    };
    printf("\n\nFim Program\n\n");
};