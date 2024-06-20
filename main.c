#include <stdio.h>
#include <stdlib.h>
#include "forca.h"

int main() {
    Forca jogo;
    inicializarJogo(&jogo);

    while (!jogo.terminado) {
        imprimirJogo(&jogo);
        char letra;
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        adivinharLetra(&jogo, letra);
    }

    finalizarJogo(&jogo);
    return 0;
}
