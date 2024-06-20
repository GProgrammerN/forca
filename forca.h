#ifndef FORCA_H
#define FORCA_H

typedef struct {
    char palavraSecreta[20];
    char palavraAtual[20];
    int letrasTentadas[26];
    int tentativasRestantes;
    int terminado;
} Forca;

void inicializarJogo(Forca *jogo);
void imprimirJogo(Forca *jogo);
void adivinharLetra(Forca *jogo, char letra);
void finalizarJogo(Forca *jogo);

#endif
