#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> // to lower
#include "forca.h"

void inicializarJogo(Forca *jogo) {
    char palavras[][20] = {"computador", "programacao", "tecnologia", "internet"};
    int totalPalavras = sizeof(palavras) / sizeof(palavras[0]);
    srand(time(NULL)); // numero aleatório
    strcpy(jogo->palavraSecreta, palavras[rand() % totalPalavras]);
    jogo->tentativasRestantes = 6;
    jogo->terminado = 0;

    // Inicializa a palavra atual com _
    int len = strlen(jogo->palavraSecreta);
    for (int i = 0; i < len; i++) {
        jogo->palavraAtual[i] = '_';
    }
    jogo->palavraAtual[len] = '\0';

    // Inicializa o array letrasTentadas com zeros
    for (int i = 0; i < 26; i++) {
        jogo->letrasTentadas[i] = 0;
    }
}

void imprimirJogo(Forca *jogo) {
    printf("Palavra: %s\n", jogo->palavraAtual);
    printf("Tentativas restantes: %d\n", jogo->tentativasRestantes);
    printf("Letras tentadas: ");
    for (int i = 0; i < 26; i++) {
        if (jogo->letrasTentadas[i]) {
            printf("%c ", 'a' + i);
        }
    }
    printf("\n");
}

void adivinharLetra(Forca *jogo, char letra) {
    letra = tolower(letra);
    if (letra < 'a' || letra > 'z') { //valor da letra
        printf("Letra inválida.\n");
        return;
    }

    if (jogo->letrasTentadas[letra - 'a']) {
        printf("Você já tentou esta letra.\n");
        return;
    }

    jogo->letrasTentadas[letra - 'a'] = 1;
    int acertou = 0;
    for (int i = 0; i < strlen(jogo->palavraSecreta); i++) {
        if (jogo->palavraSecreta[i] == letra) {
            jogo->palavraAtual[i] = letra;
            acertou = 1;
        }
    }

    if (!acertou) {
        jogo->tentativasRestantes--;
        printf("Letra errada! Você perdeu uma tentativa.\n");
    }

    if (strcmp(jogo->palavraAtual, jogo->palavraSecreta) == 0) {
        printf("Parabéns! Você adivinhou a palavra: %s\n", jogo->palavraSecreta);
        jogo->terminado = 1;
    } else if (jogo->tentativasRestantes <= 0) {
        printf("Você perdeu! A palavra era: %s\n", jogo->palavraSecreta);
        jogo->terminado = 1;
    }
}

void finalizarJogo(Forca *jogo) {
}
