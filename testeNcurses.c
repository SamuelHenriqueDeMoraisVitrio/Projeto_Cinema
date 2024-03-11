#include <ncurses.h>

int main(){
    // Inicializa a biblioteca ncurses
    initscr();

    // Imprime um texto na janela padrão
    printw("Hello, world!");

    // Atualiza a tela
    refresh();

    // Espera por um caractere
    getch();

    // Finaliza a biblioteca ncurses
    endwin();

    return 0;
}